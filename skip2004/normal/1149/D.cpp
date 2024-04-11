#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 80;
typedef long long ll;
const int mod = 998244353;
int fa[maxn], idx[maxn], size[maxn], tot;
int n, m, a, b;
int dis[1 << 17][maxn];
int vis[1 << 17][maxn];
int ans[maxn];
int u[10000], v[10000], w[10000];
struct pr {
	int s, u, d;
	inline int operator < (const pr & b) const {
		return d > b.d;
	}
};
std::priority_queue<pr> q;
inline void relax(const pr & x) {
	if(dis[x.s][x.u] > x.d) {
		dis[x.s][x.u] = x.d;
		q.push(x);
	}
	if(ans[x.u] > x.d) {
		ans[x.u] = x.d;
	}
}
struct edge {
	int to, nxt, v;
} way[500];
int h[maxn], num;
inline void link(int x, int y, int v) {
	way[++num] = {y, h[x], v}, h[x] = num;
	way[++num] = {x, h[y], v}, h[y] = num;
}
inline int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
inline int ins(int s,int x) {
	return x ? s | 1 << x - 1 : s;
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m >> a >> b;
	rep(i, 1, n) {
		fa[i] = i;
	}
	rep(i, 1, m) {
		cin >> u[i] >> v[i] >> w[i];
		link(u[i], v[i], w[i]);
		if(w[i] == a) {
			fa[find(u[i])] = find(v[i]);
		}
	}
	rep(i, 1, n) {
		++size[find(i)];
	}
	rep(i, 1, n) {
		if(fa[i] == i && size[i] > 3) {
			idx[i] = ++tot;
		}
	}
	rep(i, 1, n) {
		idx[i] = idx[find(i)];
		ans[i] = 1e9;
	}
	for(int i = 0;i < 1 << tot;++i) {
		rep(j, 1, n) {
			dis[i][j] = 1e9;
		}
	}
	relax({ins(0, idx[1]), 1, 0});
	for(;q.size();) {
		pr x = q.top(); q.pop(); if(vis[x.s][x.u]) continue;
		vis[x.s][x.u] = 1;
		for(int i = h[x.u];i;i = way[i].nxt) {
			if(way[i].v == a || fa[way[i].to] != fa[x.u] && (!idx[way[i].to] || !(x.s >> idx[way[i].to] - 1 & 1))) {
				relax({ins(x.s, idx[way[i].to]), way[i].to, x.d + way[i].v});
			}
		}
	}
	rep(i, 1, n) {
		cout << ans[i] << '\n';
	}
}