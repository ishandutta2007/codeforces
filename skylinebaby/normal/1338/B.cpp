#include<bits/stdc++.h>
using namespace std;
int vis[112345];
vector<int> g[112345];
set<int> s;
int papa[112345];
int dep[112345];
int deg[112345];
void dfs(int x, int p)
{
	vis[x] = 1;
	for(int i = 0; i < g[x].size(); ++i)
	{
		int y = g[x][i];
		if(y == p) continue;
		papa[y] = x;
		dep[y] = dep[x] + 1;
		dfs(y, x);
	}
} 
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n - 1; ++i)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		--x, --y;
		g[x].push_back(y);
		g[y].push_back(x);
		++deg[x], ++deg[y];
	}
	for(int i = 0; i < n; i++) if(deg[i] != 1)
	{
		dfs(i, i);
		break;
	}
	int od = 0;
	int ev = 0;
	int sum = 0;
	for(int i = 0; i < n; i++) if(deg[i] == 1)
	{
		s.insert(papa[i]);
		++sum;
		if(dep[i] & 1) ++od;
		else ++ev;
	}
	int z = s.size();
	if(od && ev) printf("3 ");
	else printf("1 ");
	printf("%d\n", n - 1 - sum + z);
	return 0;
}