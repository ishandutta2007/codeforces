#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
#define pb push_back
#define all(x) (x).begin(), (x).end()
using std::cin; using std::cout;
const int maxn = 200200;
template<typename T>
using vec = std::vector<T>;
typedef long long ll;
const int mod = 998244353;
inline ll pow(ll a,int b,int ans = 1) {
	for(;b;b >>= 1,a = a * a % mod) if(b & 1)
		ans = ans * a % mod;
	return ans;
}
inline ll inverse(int x){ return pow(x, mod - 2); }
struct T {
	int to, nxt;
} way[maxn << 1];
int h[maxn], num;
inline void link(int x,int y) {
	way[++num] = {y, h[x]}, h[x] = num;
	way[++num] = {x, h[y]}, h[y] = num;
}
int dfn[maxn], st[20][maxn], dep[maxn], tot, size[maxn];
inline void dfs0(int x,int f = 0) {
	st[0][tot] = f, dfn[x] = ++ tot, dep[x] = dep[f] + 1, size[x] = 1;
	for(int i = h[x];i;i=way[i].nxt) if(way[i].to != f) {
		dfs0(way[i].to, x), size[x] += size[way[i].to];
	}
}
inline int min(int x,int y) { return dfn[x] < dfn[y] ? x : y; }
inline int cmp(int x,int y) { return dfn[x] < dfn[y]; }
inline int lca(int x,int y) {
	if(dfn[x] > dfn[y]) std::swap(x, y);
	const int lg = std::__lg(dfn[y] - dfn[x]);
	return x == y ? x : min(st[lg][dfn[x]], st[lg][dfn[y] - (1 << lg)]);
}
inline int dis(int x,int y) {
	return dep[x] + dep[y] - dep[lca(x, y)] * 2;
}
int s[maxn], id[maxn], start[maxn];
int ask[maxn];
int n, q;
namespace vt {
	struct T {
		int to, nxt;
	} way[maxn << 1];
	int h[maxn], num;
	inline void link(int x,int y) {
		way[++num] = {y, h[x]}, h[x] = num;
		way[++num] = {x, h[y]}, h[y] = num;
	}
	struct data { int id, T, s; };
	inline int operator < (const data & x, const data & y) { return x.T == y.T ? x.s > y.s : x.T > y.T; }
	inline void solve(vec<int> & v) {
		std::priority_queue<data> q;
		for(int i : v) if(id[i]) q.push({i, 0, id[i]});
		for(;!q.empty();){
			data x = q.top(); q.pop(); if(id[x.id] && x.T) continue;
			id[x.id] = x.s;
			for(int & i = h[x.id];i;i = way[i].nxt) if(!id[way[i].to]) {
				q.push({way[i].to, (dis(start[x.s], way[i].to) + s[x.s] - 1) / s[x.s], x.s});
			}
		}
		num = 0;
	}
}
int main() {
	std::ios::sync_with_stdio(false),cin.tie(0);
	cin >> n;
	rep(i, 2, n) {
		int x, y; cin >> x >> y;
		link(x, y);
	}
	dfs0(1);
	for(int i = 1;i < 20;++i) for(int j = 1;j + (1 << i) - 1 < n;++j) {
		st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << i - 1)]);
	}
	cin >> q;
	rep(i, 1, q) {
		int k, m;
		cin >> k >> m;
		vec<int> v;
		rep(i, 1, k) {
			int x;
			cin >> x >> s[i];
			start[i] = x;
			id[x] = i;
			v.pb(x);
		}
		rep(i, 1, m) {
			cin >> ask[i];
			v.pb(ask[i]);
		}
		sort(all(v),cmp),v.erase(std::unique(v.begin(),v.end()),v.end());
		for(int s = v.size(), i = 1;i < s;++i) v.pb(lca(v[i - 1], v[i]));
		sort(all(v),cmp),v.erase(std::unique(v.begin(),v.end()),v.end());
		static int st[maxn]; int top = 0;
		for(int i : v) {
			for(;top && dfn[i] >= dfn[st[top]] + size[st[top]];) -- top;
			if(top) vt::link(st[top], i);
			st[++top] = i;
		}
		vt::solve(v);
		rep(i, 1, m) cout << id[ask[i]] << " \n"[i == m];
		for(int i : v) id[i] = 0;
	}
}