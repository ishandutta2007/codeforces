#include<bits/stdc++.h>
using std::cin;
using std::cout;
typedef long long ll;
const int maxn = 100100;
int n, m, q;
struct T
{
	int to, nxt, v;
} way[maxn << 1];
int h[maxn], num;
inline void link(int x, int y, int v)
{
	way[++num] = {y, h[x], v}, h[x] = num;
	way[++num] = {x, h[y], v}, h[y] = num;
}


int st[20][maxn], dfn[maxn], size[maxn], tot;
ll dep[maxn];

inline int min(int x, int y)
{
	return dfn[x] < dfn[y] ? x : y;
}

inline int cmp0(int x, int y) 
{
	return dfn[x] < dfn[y];
}

inline void dfs0(int x, int fa = 0)
{
	st[0][tot] = fa, dfn[x] = ++ tot, size[x] = 1;
	for(int i = h[x];i;i = way[i].nxt) if(way[i].to != fa)
	{
		dep[way[i].to] = dep[x] + way[i].v;
		dfs0(way[i].to, x);
		size[x] += size[way[i].to];
	}
}

inline int lca(int x, int y) 
{
	if(dfn[x] > dfn[y])
		std::swap(x, y);
	const int lg = std::__lg(dfn[y] - dfn[x]);
	return x != y ? min(st[lg][dfn[x]] , st[lg][dfn[y] - (1 << lg)]) : x;
}

int fa[maxn];
inline int find(int x)
{
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

int nd[maxn], idx;

namespace vt
{
	int x[maxn], y[maxn], v[maxn], tot;
	inline void add(int a, int b, int c) {
		x[++tot] = a;
		y[tot] = b;
		v[tot] = c;
	}
	struct T 
	{
		int to, nxt; ll v;
	} way[maxn << 1];
	int h[maxn], num;
	inline void link(int x, int y, ll v)
	{
		way[++num] = {y, h[x], v}, h[x] = num;
		way[++num] = {x, h[y], v}, h[y] = num;
	}
	typedef std::pair<ll, int> pr;
	ll dis[maxn]; int vis[maxn];
	inline void dij(int u, std::vector<int> & vec) {
		for(int i = 1;i <= tot;++i)
			link(x[i], y[i], v[i]);
		std::priority_queue<pr, std::vector<pr>, std::greater<pr>> q;
		for(int i : vec)
			dis[i] = 1e18, vis[i] = 0;
		q.emplace(dis[u] = 0, u);
		for(;q.size();) {
			int x = q.top().second; q.pop();
			if(vis[x]) continue;
			vis[x] = 1;
			for(int&i = h[x];i;i = way[i].nxt) if(dis[way[i].to] > dis[x] + way[i].v) {
				q.emplace(dis[way[i].to] = dis[x] + way[i].v, way[i].to);
			}
		}
		num = 0;
	}
}
int main()
{
	std::ios::sync_with_stdio(false), std::cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;++i)
	{
		fa[i] = i;
	}
	for(int i = 1, x, y, v;i <= m;++i)
	{
		cin >> x >> y >> v;
		if(find(x) != find(y))
		{
			fa[find(x)] = find(y);
			link(x, y, v);
		}
		else
		{
			vt::add(x, y, v);
			nd[++idx] = x;
			nd[++idx] = y;
		}
	}
	dfs0(1);
	for(int i = 1;i < 20;++i)
	{
		for(int j = 1;j + (1 << i) - 1 < n;++j)
		{
			st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << i - 1)]);
		}
	}
	std::sort(nd + 1, nd + tot + 1, cmp0);
	tot = std::unique(nd + 1, nd + tot + 1) - nd - 1;
	cin >> q;
	for(int i = 1, u, v;i <= q;++i)
	{
		std::vector<int> vec(nd + 1, nd + tot + 1);
		cin >> u >> v;
		auto iter = lower_bound(vec.begin(), vec.end(), u, cmp0);
		if(iter == vec.end() || *iter != u) vec.insert(iter, u);
		iter = lower_bound(vec.begin(), vec.end(), v, cmp0);
		if(iter == vec.end() || *iter != v) vec.insert(iter, v);
		for(int S = vec.size(), i = 1;i < S;++i)
			vec.push_back(lca(vec[i - 1], vec[i]));
		sort(vec.begin(), vec.end(), cmp0);
		vec.erase(unique(vec.begin(), vec.end()), vec.end());
		static int st[maxn];
		int top = 0;
		for(int i : vec) 
		{
			for(;top && dfn[i] >= dfn[st[top]] + size[st[top]];) -- top;
			if(top) vt::link(st[top], i, dep[i] - dep[st[top]]);
			st[++top] = i;
		}
		vt::dij(u, vec);
		cout << vt::dis[v] << '\n';
	}
}