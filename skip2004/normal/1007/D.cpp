#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 100200;
typedef long long ll;
const int mod = 998244353;
inline ll pow(ll a,int b,int ans = 1) {
	for(;b;b >>= 1,a = a * a % mod) if(b & 1)
		ans = ans * a % mod;
	return ans;
}
inline ll inverse(int x){ return pow(x, mod - 2); }
namespace tj {
	const int maxn = 1e7;
	struct T { int to, nxt; } way[maxn * 3];
	int h[maxn], num;
	inline void link(int x, int y) {
		way[++num] = {y, h[x]}, h[x] = num;
	}
	int dfn[maxn], low[maxn], st[maxn], bel[maxn], tot, top, idx;
	bool in[maxn];
	inline void dfs0(int x) {
		dfn[x] = low[x] = ++tot, st[++top] = x, in[x] = 1;
		for(int i = h[x];i;i = way[i].nxt) {
			if(!dfn[way[i].to]) {
				dfs0(way[i].to);
				low[x] = std::min(low[x], low[way[i].to]);
			} else {
				if(in[way[i].to]) {
					low[x] = std::min(low[x], dfn[way[i].to]);
				}
			}
		}
		if(low[x] == dfn[x]) {
			++ idx;
			do {
				in[st[top]] = 0;
				bel[st[top]] = idx;
			} while(st[top--] != x);
		}
	}
}
int n, m, tot, idx;
struct T {
	int to, nxt;
} way[maxn << 1];
int h[maxn], num;
inline void link(int x, int y) {
	way[++num] = {y, h[x]}, h[x] = num;
	way[++num] = {x, h[y]}, h[y] = num;
}
int dep[maxn], size[maxn], son[maxn], dfn[maxn], top[maxn], fa[maxn];
inline void dfs0(int x, int fa = 0) {
	dep[x] = dep[fa] + 1;
	::fa[x] = fa;
	size[x] = 1;
	for(int i = h[x];i;i = way[i].nxt) if(way[i].to != fa) {
		dfs0(way[i].to, x);
		if(size[way[i].to] >= size[son[x]]) {
			son[x] = way[i].to;
		}
		size[x] += size[way[i].to];
	}
}
inline void dfs1(int x, int top, int fa = 0){ 
	dfn[x] = ++ idx; ::top[x] = top;
	if(son[x]) dfs1(son[x], top, x);
	for(int i = h[x];i;i = way[i].nxt) if(way[i].to != fa && way[i].to != son[x]) {
		dfs1(way[i].to, way[i].to, x);
	}
}
std::vector<int> vc[maxn << 2];
inline void ins(int ql, int qr, int v, int cur = 1, int l = 2, int r = n) {
	if(ql <= l && r <= qr) {
		vc[cur].push_back(v);
		return ;
	}
	int mid = l + r >> 1;
	if(ql <= mid) ins(ql, qr, v, cur << 1, l, mid);
	if(mid < qr) ins(ql, qr, v, cur << 1 | 1, mid + 1, r);
}
inline void add(int x, int y, int v) {
	for(;top[x] != top[y];x = fa[top[x]]) {
		if(dep[top[x]] < dep[top[y]]) std::swap(x, y);
		ins(dfn[top[x]], dfn[x], v);
	}
	if(x != y) ins(std::min(dfn[x], dfn[y]) + 1, std::max(dfn[x], dfn[y]), v);
}
inline void dfs2(int cur, int now0, int now1, int l = 2, int r = n) {
	for(int i : vc[cur]) {
		tj::link(i, now0);
		tj::link(++tot, now0);
		tj::link(now0 = tot, i ^ 1);

		tj::link(now1, i ^ 1);
		tj::link(now1, ++tot);
		tj::link(i, now1 = tot);
	}
	if(l == r) {
		return ;
	}
	int mid = l + r >> 1;
	dfs2(cur << 1, now0, now1, l, mid);
	dfs2(cur << 1 | 1, now0, now1, mid + 1, r);
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	rep(i, 2, n) {
		int x, y;
		cin >> x >> y;
		link(x, y);
	}
	dfs0(1);
	dfs1(1, 1);
	cin >> m;
	rep(i, 1, m) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		add(a, b, i << 1);
		add(c, d, i << 1 | 1);
	}
	dfs2(1, m + 1 << 1, tot = m + 1 << 1 | 1);
	rep(i, 2, m + m + 1) if(!tj::dfn[i]) {
		tj::dfs0(i);
	}
	rep(i, 1, m) {
		if(tj::bel[i << 1] == tj::bel[i << 1 | 1]) {
			cout << "NO" << '\n';
			return 0;
		}
	}
	cout << "YES" << '\n';
	rep(i, 1, m) {
		cout << (tj::bel[i << 1] > tj::bel[i << 1 | 1]) + 1 << '\n';
	}
}