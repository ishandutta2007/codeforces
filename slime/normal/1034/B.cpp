#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 400005
#define ll long long
#define ld double
#define mod 998244353
using namespace std;

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	if(n > m) swap(n, m);
	if(n == 1)
	{
		int lst = 0;
		if(m % 6 <= 3) lst = m % 6;
		else lst = 6 - m % 6;
		printf("%d\n", m - lst);
		return 0; 	
	} 
	if(m % 2) swap(n, m);
	if(!(m % 2))
	{
		if(n == 2) 
		{
			if(m == 2)
			{
				printf("0\n");
				return 0;
			}
			else 
			{
				printf("%lld\n", n * (ll)m);
				return 0;
			}
		}
		else if(n == 3)
		{
			if(m == 2)
			{
				printf("4\n");
				return 0;
			}
			else 
			{
				printf("%lld\n", n * (ll)m);
				return 0;
			}
		}
		else if(n == 7)
		{
			if(m == 2)
			{
				printf("12\n");
				return 0;
			}
			else 
			{
				printf("%lld\n", n * (ll)m);
				return 0;
			}
		}
		else
		{
				printf("%lld\n", n * (ll)m);
				return 0;
		}
	}
	else
	{
		//if(n > m) swap(n, m);
		printf("%lld\n", n * (ll)m - 1);
		return 0;
	}
	return 0;
 }