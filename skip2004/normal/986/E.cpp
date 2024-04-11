#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 200200;
typedef long long ll;
const int mod = 1e9 + 7;
inline ll pow(ll a,int b,int ans = 1) {
	for(;b;b >>= 1,a = a * a % mod) if(b & 1)
		ans = ans * a % mod;
	return ans;
}
inline ll inverse(int x){ return pow(x, mod - 2); }
typedef std::vector<int> vc;
namespace pm {
	const int N = 1e7 + 10;
	int is[N], nxt[N];
	inline void init() {
		for(int i = 2;i < N;++i) if(!is[i]) {
			nxt[i] = i;
			for(int j = i + i;j < N;j += i) is[j] = 1, nxt[j] = i;
		}
	}
	inline vc factor(int x) {
		vc ret;
		for(;x != 1;) {
			int now = 1, p = nxt[x];
			for(;x % p == 0;x /= p) ret.push_back(now *= p);
		}
		return ret;
	}
}
int n, q, a[maxn];
struct T {
	int to, nxt;
} way[maxn << 1];
int h[maxn], num;
inline void link(int x, int y) {
	way[++num] = {y, h[x]}, h[x] = num;
	way[++num] = {x, h[y]}, h[y] = num;
}
int st[20][maxn], dfn[maxn], fa[maxn], tot;
inline int min(int x, int y) {
	return dfn[x] < dfn[y] ? x : y;
}
inline void dfs0(int x, int fa = 0) {
	st[0][tot] = fa, dfn[x] = ++tot, ::fa[x] = fa;
	for(int i = h[x];i;i = way[i].nxt) if(way[i].to != fa) {
		dfs0(way[i].to, x);
	}
}
inline int lca(int x, int y) {
	if(dfn[x] > dfn[y]) std::swap(x, y);
	const int lg = std::__lg(dfn[y] - dfn[x]);
	return x == y ? x : min(st[lg][dfn[x]], st[lg][dfn[y] - (1 << lg)]);
}
int ans[maxn << 2];
std::vector<std::pair<int, int>> Q[maxn];
int cnt[(int) 1e7 + 10];
inline void dfs1(int x, int fa = 0) {
	for(int i : pm::factor(a[x])) ++ cnt[i];
	for(auto i : Q[x]) {
		int & a = ans[i.second];
		for(int x : pm::factor(i.first)) {
			a = (ll) a * pow(pm::nxt[x], cnt[x]) % mod;
		}
	}
	for(int i = h[x];i;i = way[i].nxt) if(way[i].to != fa) {
		dfs1(way[i].to, x);
	}
	for(int i : pm::factor(a[x])) -- cnt[i];
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	pm::init();
	cin >> n;
	rep(i, 2, n) {
		int x, y;
		cin >> x >> y;
		link(x, y);
	}
	rep(i, 1, n) {
		cin >> a[i];
	}
	dfs0(1);
	for(int i = 1;i < 20;++i) {
		for(int j = 1;j + (1 << i) - 1 < n;++j) {
			st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << i - 1)]);
		}
	}
	cin >> q;
	rep(i, 1, q) {
		int u, v, x;
		cin >> u >> v >> x;
		Q[u].emplace_back(x, i * 4 - 3);
		Q[v].emplace_back(x, i * 4 - 2);
		Q[lca(u, v)].emplace_back(x, i * 4 - 1);
		Q[fa[lca(u, v)]].emplace_back(x, i * 4);
	}
	rep(i, 1, q * 4) ans[i] = 1;
	dfs1(1);
	rep(i, 1, q) {
		ll a0 = (ll) ans[i * 4 - 3] * ans[i * 4 - 2] % mod;
		ll a1 = (ll) ans[i * 4 - 1] * ans[i * 4 - 0] % mod;
		cout << int(a0 * inverse(a1) % mod) << '\n';
	}
}