#include<bits/stdc++.h>
const int maxn = 300200;
int n, m;
struct T
{
	int to,nxt,v;
} way[maxn << 1];
int h[maxn],num = 1;
int deg[maxn];
inline void link(int x,int y)
{
	way[++num] = {y,h[x],1},h[x] = num;
	way[++num] = {x,h[y],1},h[y] = num;
}
std::vector<int> ans;
inline void dfs(int x)
{
	for(int & i = h[x];i;)
		if(way[i].v)
		{
			way[i].v = way[i ^ 1].v = 0;
			int to = way[i].to;
			i = way[i].nxt;
			dfs(to);
		} else 
			i = way[i].nxt;
	ans.push_back(x);
}
main()
{
	std::ios::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> m;
	for(int i = 1,a,b;i <= m;++i)
	{
		std::cin >> a >> b;
		link(a,b);
		++ deg[a];
		++ deg[b];
	}
	int pre = 0;
	for(int i = 1;i <= n;++i) if(deg[i] & 1)
	{
		pre ? link(i,pre),pre = 0 : (pre = i);
	}
	if(num / 2 & 1)
	{
		link(1,1);
	}
	dfs(1);
	std::cout << ans.size() - 1 << '\n';
	for(int i = 0;i + 1 < ans.size();++i)
	{
		if(i & 1)
			std::cout << ans[i] << ' ' << ans[i + 1] << '\n';
		else
			std::cout << ans[i + 1] << ' ' << ans[i] << '\n';
	}
}