#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#define maxn 5005
#define ll long long
#define mod 998244353
using namespace std;
int cnt[maxn];
int w[maxn];
int t[maxn];
int ans[maxn][105];
char inp[20];	
int n, m, q;
int rd()
{
	scanf("%s", inp + 1);
	int ns = 0;
	for(int i = 1; i <= n; i++)
	{
		ns *= 2;
		if(inp[i] == '1') ns++;
	}
	return ns;
}
int main()
{
	scanf("%d%d%d", &n, &m, &q);
	for(int i = 0; i < n; i++)
		scanf("%d", &w[n - 1 - i]);
	for(int i = 0; i < (1 << n); i++)
		for(int j = 0; j < n; j++)
			if(i & (1 << j))
				t[i] += w[j];
	for(int i = 1; i <= m; i++)
	{
		int x = rd();
		cnt[x]++;
	}
	for(int i = 0; i < (1 << n); i++)
		for(int j = 0; j < (1 << n); j++)
		{
			int ns = t[i ^ j ^ ((1 << n) - 1)];
			if(ns <= 100)
				ans[i][ns] += cnt[j];
		}
	for(int i = 0; i < (1 << n); i++)
		for(int j = 1; j <= 100; j++)
			ans[i][j] += ans[i][j - 1];
	for(int i = 0; i < q; i++)
	{
		int x = rd();
		int k;
		scanf("%d", &k);
		printf("%d\n", ans[x][k]);
	}
	return 0;
}