#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 100005
#define inf 1000000007
#define ll long long
#define ld double
#define mod 998244353
using namespace std;
ll sx, sy; 
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n * 2; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		sx += a, sy += b;
	}
	printf("%lld %lld\n", sx / n, sy / n);
	return 0;
 }