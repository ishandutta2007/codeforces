#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 300200;
typedef long long ll;
const int mod = 998244353;
inline ll pow(ll a,int b,int ans = 1) {
	for(;b;b >>= 1,a = a * a % mod) if(b & 1)
		ans = ans * a % mod;
	return ans;
}
inline ll inverse(int x){ return pow(x, mod - 2); }
struct T {
	int to, nxt, v;
} way[maxn << 1];
int h[maxn], num;
inline void link(int x, int y, int v) {
	way[++num] = {y, h[x], v}, h[x] = num;
	way[++num] = {x, h[y], v}, h[y] = num;
}
int a[maxn];
int n, q;
int st[20][maxn], dfn[maxn], fa[maxn], tot;
ll sum[maxn], dp[maxn], go_up[maxn], sum_son[maxn], pre[maxn];
ll s0[maxn];
inline int min(int x, int y) { return dfn[x] < dfn[y] ? x : y; }
inline void dfs0(int x, int fa = 0) {
	st[0][tot] = fa, dfn[x] = ++tot, ::fa[x] = fa;
	for(int i = h[x];i;i = way[i].nxt) if(way[i].to != fa) {
		sum[way[i].to] = sum[x] - way[i].v + a[way[i].to];
		dp[way[i].to] = a[way[i].to] - way[i].v * 2;
		dfs0(way[i].to, x);
		sum_son[x] += dp[way[i].to];
	}
	dp[x] = std::max<ll>(dp[x] + sum_son[x], 0);
}
inline void dfs1(int x, int fa = 0) {
	s0[x] = s0[fa] + sum_son[x] - dp[x];
	pre[x] += sum_son[x];
	for(int i = h[x];i;i = way[i].nxt) if(way[i].to != fa) {
		go_up[way[i].to] = std::max<ll>(0, a[x] - way[i].v * 2 + sum_son[x] - dp[way[i].to] + go_up[x]);
		pre[way[i].to] = pre[x] - dp[way[i].to];
		dfs1(way[i].to, x);
	}
}
inline int lca(int x, int y) {
	if(dfn[x] > dfn[y]) std::swap(x, y);
	const int lg = std::__lg(dfn[y] - dfn[x]);
	return x == y ? x : min(st[lg][dfn[x]], st[lg][dfn[y] - (1 << lg)]);
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> q;
	rep(i, 1, n) {
		cin >> a[i];
	}
	rep(i, 2, n) {
		int u, v, w;
		cin >> u >> v >> w;
		link(u, v, w);
	}
	sum[1] = a[1];
	dfs0(1);
	dfs1(1);
	for(int i = 1;i < 20;++i) {
		for(int j = 1;j + (1 << i) - 1 < n;++j) {
			st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << i - 1)]);
		}
	}
	rep(i, 1, q) {
		int x, y;
		cin >> x >> y;
		const int o = lca(x, y);
		cout << (s0[x] + s0[y] - s0[o] * 2 + sum_son[o] + go_up[o] + sum[x] + sum[y] - sum[o] * 2 + a[o]) << '\n';
	}
}