#include<bits/stdc++.h>
const int maxn = 300200;
struct map{ std::map<int,int> mp; int tot; inline int get(int x){ return mp.count(x) ? mp[x] : mp[x] = ++tot; } } map;
struct edge { int u, v, c, t; } a[maxn];
std::vector<int> c[maxn];
std::vector<int> cnd[maxn];
int n, m;
namespace tarjan{ 
	int low[maxn], dfn[maxn], color[maxn], cl, stack[maxn], in[maxn], tot, top;
	struct T { int to, nxt; } way[maxn << 3];
	int h[maxn], num;
	inline void link(int x,int y) { way[++num] = {y,h[x]}, h[x] = num; }
	inline void dfs(int x) {
		low[x] = dfn[x] = ++tot, stack[++top] = x, in[x] = 1;
		for(int i = h[x];i;i = way[i].nxt) {
			if(!dfn[way[i].to]) {
				dfs(way[i].to);
				low[x] = std::min(low[x], low[way[i].to]);
			} else if(in[way[i].to]) low[x] = std::min(low[x], dfn[way[i].to]);
		}
		if(dfn[x] == low[x]) {
			++ cl;
			do color[stack[top]] = cl, in[stack[top]] = 0; while(stack[top--] != x);
		}
	}
	std::vector<int> v[maxn];
	inline std::vector<int> __(int o) {
		memset(h, 0, sizeof h), memset(dfn, 0, sizeof dfn), num = 1, cl = 0;
		int idx = m + m;
		for(int i = 1;i <= m;++i) v[a[i].u].push_back(i), v[a[i].v].push_back(i);
		for(int i = 1;i <= n;++i) if(v[i].size()) {
			for(int j = 1, pre = v[i][0];j < v[i].size();++j) 
				link(v[i][j] + m, pre), link(++idx, pre), link(pre = idx, v[i][j]);
			std::reverse(v[i].begin(), v[i].end());
			for(int j = 1, pre = v[i][0];j < v[i].size();++j) 
				link(v[i][j] + m, pre), link(++idx, pre), link(pre = idx, v[i][j]);
			v[i].clear();
		}
		for(int color = 1;color <= m;++color) {
			for(int i : c[color]) v[a[i].u].push_back(i), v[a[i].v].push_back(i);
			for(int i : cnd[color]) {
				for(int j = 1, pre = v[i][0] + m;j < v[i].size();++j) 
					link(v[i][j], pre), link(++idx, pre), link(pre = idx, v[i][j] + m);
				std::reverse(v[i].begin(), v[i].end());
				for(int j = 1, pre = v[i][0] + m;j < v[i].size();++j) 
					link(v[i][j], pre), link(++idx, pre), link(pre = idx, v[i][j] + m);
				v[i].clear();
			}
		}
		for(int i = 1;i <= m;++i) if(a[i].t > o) link(i + m, i);
		for(int i = 1;i <= idx;++i) if(!dfn[i]) dfs(i);
		for(int i = 1;i <= m;++i) if(color[i] == color[i + m]) return {};
		std::vector<int> v = {0};
		for(int i = 1;i <= m;++i) if(color[i] > color[i + m]) v.push_back(i);
		return v;
	}
}
int main() {
	std::ios::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> m;
	for(int i = 1;i <= m;++i) {
		std::cin >> a[i].u >> a[i].v >> a[i].c >> a[i].t, a[i].c = map.get(a[i].c);
		c[a[i].c].push_back(i);
		cnd[a[i].c].push_back(a[i].u);
		cnd[a[i].c].push_back(a[i].v);
	}
	for(int i = 1;i <= m;++i) 
		std::sort(cnd[i].begin(), cnd[i].end()), cnd[i].erase(std::unique(cnd[i].begin(), cnd[i].end()), cnd[i].end());
	int l = -1, r = 1e9;
	for(;l + 1 != r;) {
		int mid = l + r >> 1;
		(tarjan::__(mid).empty() ? l : r) = mid;
	}
	auto ans = tarjan::__(r);
	if(ans.size()) {
		std::cout << "Yes" << '\n';
		std::cout << r << ' ' << ans.size() - 1 << '\n';
		for(int i = 1;i < ans.size();++i) std::cout << ans[i] << ' ';
	} else {
		std::cout << "No" << '\n';
	}
}