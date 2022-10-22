#include<bits/stdc++.h>
typedef long long ll;
using std::cin;
using std::cout;

const int maxn = 100100;

inline ll c(ll x){ return x * (x - 1); }

int n, q;

struct T {
	int to, nxt;
} way[maxn << 1];
int h[maxn], num;
inline void link(int x, int y) {
	way[++num] = {y, h[x]}, h[x] = num;
	way[++num] = {x, h[y]}, h[y] = num;
}

ll cnt[maxn], size[maxn], sum[maxn];

inline ll calc(int x) {
	return cnt[x] * (c(n - 1) - sum[x]);
}

int fa[maxn], pa[maxn], dep[maxn];
inline void dfs0(int x, int fa = 0) {
	:: fa[x] = fa, pa[x] = x, size[x] = cnt[x] = 1, dep[x] = dep[fa] + 1;
	for(int i = h[x];i;i = way[i].nxt) if(way[i].to != fa) {
		dfs0(way[i].to, x);
		size[x] += size[way[i].to];
		sum[x] += c(size[way[i].to]);
	}
	sum[x] += c(n - size[x]);
}

inline int find(int x) {
	return pa[x] == x ? x : pa[x] = find(pa[x]);
}

ll ans = 0;
inline void merge(int x, int y) {
	x = find(x), y = find(y);
	ans -= calc(x) + calc(y);
	cnt[y] += cnt[x];
	sum[y] -= c(size[x]);
	sum[y] += sum[x] - c(n - size[x]);
	ans += calc(y);
}

int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	for(int i = 1, u, v;i < n;++i) {
		cin >> u >> v;
		link(u, v);
	}
	dfs0(1);
	for(int i = 1;i <= n;++i) {
		ans += calc(i);
	}
	cout << ans << '\n';
	cin >> q;
	for(int i = 1, u, v;i <= q;++i) {
		cin >> u >> v;
		u = find(u), v = find(v);
		for(;u != v;) {
			if(dep[u] < dep[v])
				std::swap(u, v);
			merge(u, fa[u]);
			u = pa[u] = find(fa[u]);
		}
		cout << ans << '\n';
	}
}