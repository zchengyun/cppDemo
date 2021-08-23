#include <iostream>
#include <cassert>//可用作标准调试工具的宏函数
#include <cctype>//字符处理函数，声明了一组函数来对单个字符进行分类和转换
#include <cfenv>//声明了一组函数和宏来访问浮点环境以及特定类型
#include <cmath>
#include <ciso646>//可选的运算符拼写and, and_eq, or, or_eq, xor, xor_eq, not, not_eq, bitand, bitor 11种
#include <climits>//具有用于特定系统和编译器实现的基本整数类型限制的常量

#pragma STDC FENV_ACCESS on

#include "Ctype.h"
int main()
{
	int a = 10;
	int* b = NULL;
	b = &a;
    assert(b);


    Ctype* ctype = new Ctype();
    assert(!isalnum(ctype->m_i));//是数字或者字母？
    assert(!isdigit(ctype->m_i));//是数字？
    assert(!islower(ctype->m_str[ctype->m_i]));//是小写字母？
    std::cout <<std::string("ctype->m_str[0]的大写字母为：");
    std::cout<<char(toupper(ctype->m_str[0])) << std::endl;


	double PI = 3.14159;
	int num = PI;
	//获取所有可能的异常
	int res = fetestexcept(FE_ALL_EXCEPT);
	if (res & FE_INEXACT)//判断是否有精度损失
	{
		std::cout << std::string(" inexact  ");
	}
    //清除异常，调用此函数的程序应确保 pragmaFENV_ACCESS 为呼叫启用。FE_ALL_EXCEPT：域错误，至少有一个参数是未定义函数的值。
	if (fetestexcept(FE_INVALID)) printf("sqrt(-1) raises FE_INVALID\n");


	if (1 and 0) {//&&
	}
	if (not false) {//！
		std::cout << "真\n";
	}


	std::cout << "SCHAR_MAX:" << SCHAR_MAX<<std::endl;
	std::cout << "INT_MAX:" << INT_MAX << std::endl;
	std::cout << "INT_MIN:" << INT_MIN << std::endl;
	std::cout << "ULONG_MAX:" << ULONG_MAX << std::endl;
	std::cout << "LONG_MAX:" << LONG_MAX << std::endl;
}

