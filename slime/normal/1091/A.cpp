#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 100005
#define ll long long
#define ld double
#define mod 998244353
using namespace std;
int a[3]; 
int main()
{
	for(int i = 0; i < 3; i++)
		scanf("%d", &a[i]);
	for(int i = 100; i >= 0; i--)
	{
		int fl = 1;
		for(int j = 0; j < 3; j++)
			if(a[j] < i + j) fl = 0;
		if(!fl) continue;
		printf("%d\n", i * 3 + 3);
		return 0;
	}
	return 0;
}