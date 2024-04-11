#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>
#define ll long long

using namespace std;
int main() 
{
	ll n, k;
	scanf("%I64d %I64d", &n, &k);
	if (k <= (n + 1) / 2)
		printf("%I64d", 2 * k - 1);
	else
		printf("%I64d", 2 * (k - (n + 1) / 2));                          
}