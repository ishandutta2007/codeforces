#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#define maxn 100005
#define ll long long 
#define ld long double
using namespace std;
int a[maxn]; 
int to[maxn];
int dis[maxn];
void pls(int a, int b, int c)
{
	dis[a] += c, dis[b + 1] -= c;
}
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	int s, f;
	scanf("%d%d", &s, &f);
	f--;
	int len = f - s;
	for(int i = 1; i <= n; i++)
	{
		int bg = s - (i - 1);
		if(bg <= 0) bg += n;
		to[bg] += a[i];
	}
	for(int bg = 1; bg <= n; bg++)
	{
		if(bg + len <= n) pls(bg, bg + len, to[bg]);
		else pls(bg, n, to[bg]), 
			pls(1, bg + len - n, to[bg]);
	}
	int ns = 0;
	int ans = -1, pl = 0;
	for(int i = 1; i <= n; i++)
	{
		ns += dis[i];
		if(ns > ans) pl = i, ans = ns;
	}
	printf("%d\n", pl);
	return 0;
 }