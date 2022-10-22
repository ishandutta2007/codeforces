#include<bits/stdc++.h>
const int mod = 1e9 + 7;
using std::cin;
using std::cout;
const int maxn = 200005;
typedef long long ll;
int n;
struct T {
	int to, nxt;
} way[maxn << 1];
int h[maxn], num;
inline void link(int x, int y) {
	way[++num] = {y, h[x]}, h[x] = num;
	way[++num] = {x, h[y]}, h[y] = num;
}
int st[20][maxn], dfn[maxn], dep[maxn], size[maxn], tot;
inline int min(int x, int y) {
	return dfn[x] < dfn[y] ? x : y;
}
inline int cmp(int x, int y) {
	return dfn[x] < dfn[y];
}
inline void dfs0(int x, int fa = 0) {
	st[0][tot] = fa, dfn[x] = ++ tot, dep[x] = dep[fa] + 1;
	size[x] = 1;
	for(int i = h[x];i;i = way[i].nxt) if(way[i].to != fa) {
		dfs0(way[i].to, x);
		size[x] += size[way[i].to];
	}
}
inline int lca(int x, int y) {
	if(dfn[x] > dfn[y]) std::swap(x, y);
	const int lg = std::__lg(dfn[y] - dfn[x]);
	return x == y ? x : min(st[lg][dfn[x]], st[lg][dfn[y] - (1 << lg)]);
}
int a[maxn];
int phi[maxn], inv[maxn];
std::vector<int> vc[maxn];
inline void add(int&x, int y) {
	x += y - mod, x += x >> 31 & mod;
}
namespace vt {
	int head[maxn], next[maxn], ev[maxn];
	int sum[maxn];
	int val[maxn];
	inline void link(int x, int y, int v) {
		next[y] = head[x], head[x] = y, ev[y] = v;
	}
	inline void dfs0(int x, int s, int & ans) {
		sum[x] = val[x], val[x] = 0;
		for(int& i = head[x];i;i = next[i]) {
			dfs0(i, s, ans);
			add(sum[x], sum[i]);
			ans = (ans + (ll) sum[i] * (mod + s - sum[i]) % mod * ev[i]) % mod;
		}
	}
}
int ans[maxn];
int main() {
	std::ios::sync_with_stdio(false), std::cin.tie(0);
	for(int i = 1;i < maxn;++i) phi[i] = i;
	for(int i = 2;i < maxn;++i) if(phi[i] == i) {
		for(int j = i;j < maxn;j += i) phi[j] = phi[j] / i * (i - 1);
	}
	inv[1] = 1;
	for(int i = 2;i < maxn;++i) {
		inv[i] = ll(mod - mod / i) * inv[mod % i] % mod;
	}
	cin >> n;
	for(int i = 1;i <= n;++i) {
		cin >> a[i];
		vc[a[i]].push_back(i);
	}
	for(int i = 1, x, y;i < n;++i) {
		cin >> x >> y;
		link(x, y);
	}
	dfs0(1);
	for(int i = 1;i < 20;++i) for(int j = 1;j + (1 << i) - 1 < n;++j) {
		st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << i - 1)]);
	}
	for(int gcd = 1;gcd <= n;++gcd) {
		static std::vector<int> v; v.clear();
		int sum = 0;
		for(int i = gcd;i <= n;i += gcd) for(int j : vc[i]) v.push_back(j), add(sum, vt::val[j] = phi[a[j]]);
		if(v.size()) {
			sort(v.begin(), v.end(), cmp);
			for(int i = 1, s = v.size();i < s;++i) v.push_back(lca(v[i - 1], v[i]));
			sort(v.begin(), v.end(), cmp);
			v.erase(unique(v.begin(), v.end()), v.end());
			static int st[maxn]; int top = 0;
			for(int i : v) {
				for(;top && dfn[i] >= dfn[st[top]] + size[st[top]];) -- top;
				if(top) vt::link(st[top], i, dep[i] - dep[st[top]]);
				st[++top] = i;
			}
			vt::dfs0(st[1], sum, ans[gcd]);
		}
	}
	int out = 0;
	for(int i = n;i >= 1;--i) {
		for(int j = i + i;j <= n;j += i) {
			ans[i] -= ans[j], ans[i] += ans[i] >> 31 & mod;
		}
		out = (out + (ll) ans[i] * i % mod * inv[phi[i]]) % mod;
	}
	out = (ll) out * inv[n] % mod * inv[n - 1] * 2 % mod;
	cout << out << '\n';
}