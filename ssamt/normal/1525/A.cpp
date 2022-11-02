#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

long long gcd(long long num1, long long num2)//greatest common divisor
{
	if(num1 == 0)
		return num2;
	if(num2 == 0)
		return num1;
	if(num1<0)
		return gcd(-num1, num2);
	if(num2<0)
		return gcd(num1, -num2);
	while(num1%num2!=0 && num2%num1!=0)
	{
		if(num1>num2)
			num1 %= num2;
		else
			num2 %= num1;
	}
	return (num1<num2)?num1:num2;
}

int main() {
	int h, i, j;
	int t, n;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d", &n);
		printf("%d\n", 100/(gcd(100, n)));
	}
}