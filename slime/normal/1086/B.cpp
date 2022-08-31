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
int s;
int n;
int d[maxn];
int main()
{
	scanf("%d%d", &n, &s);
	for(int i = 1; i < n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		d[a]++, d[b]++;
	}
	int cnt = 0;
	for(int i = 1; i <= n; i++)	
		if(d[i] == 1) cnt++;
	printf("%.10lf\n", 1.0 * s / cnt * 2);
	return 0;
 }