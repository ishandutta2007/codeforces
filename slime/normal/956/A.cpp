#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#define maxn 105
using namespace std;
int n, m;
bool hv[maxn][maxn];
int fa[maxn];
int gfa(int a)
{
	if(fa[a] == a) return a;
	return fa[a] = gfa(fa[a]);
}
char inp[maxn];
int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n + m; i++)
		fa[i] = i;
	for(int i = 1; i <= n; i++)
	{
		scanf("%s", inp);
		for(int j = 0; j < m; j++)
			if(inp[j] == '#')	
				hv[i][j + 1] = 1, fa[gfa(i)] = gfa(j + n + 1);
	}
	bool flag = 1;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(gfa(i) == gfa(j + n))
				if(!hv[i][j]) flag = 0;
	if(flag) printf("Yes\n");
	else printf("No\n");
	return 0;
}