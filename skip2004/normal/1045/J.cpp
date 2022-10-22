#include<bits/stdc++.h>
const int maxn = 100100;
typedef unsigned long long ll;

using std::cin;
using std::cout;
int n, q;
namespace sam {
	const int N = ::maxn * 40;
	int ls[N], rs[N], val[N], idx;

	inline void add(int & rt, int pos, int l = 1, int r = n) {
		if(!rt) rt = ++ idx;
		val[rt] += 1;
		if(l == r) return ;
		int mid = l + r >> 1;
		pos <= mid ? add(ls[rt], pos, l, mid) : add(rs[rt], pos, mid + 1, r);
	}
	inline int merge(int x, int y) {
		if(!x || !y) return x | y;
		int p = ++ idx;
		val[p] = val[x] + val[y];
		ls[p] = merge(ls[x], ls[y]);
		rs[p] = merge(rs[x], rs[y]);
		return p;
	}
	inline int ask(int rt, int ql, int qr, int l = 1, int r = n) {
		if(ql <= l && r <= qr) return val[rt];
		int mid = l + r >> 1, ans = 0;
		if(ql <= mid) ans += ask(ls[rt], ql, qr, l, mid);
		if(mid < qr) ans += ask(rs[rt], ql, qr, mid + 1, r);
		return ans;
	}
	const int maxn = ::maxn << 1;
	int c[maxn][26], fa[maxn], mx[maxn], right[maxn], la = 1, tot = 1;
	inline void apd(int w, int id) {
		int p = la, now = la = ++ tot;
		mx[now] = mx[p] + 1, right[now] = id;
		for(;p && !c[p][w];p = fa[p]) c[p][w] = now;
		if(!p) fa[now] = 1;
		else {
			int q = c[p][w];
			if(mx[q] == mx[p] + 1) {
				fa[now] = q;
			} else {
				int x = ++tot;
				mx[x] = mx[p] + 1;
				memcpy(c[x], c[q], sizeof c[0]);
				fa[x] = fa[q];
				fa[q] = fa[now] = x;
				for(;p && c[p][w] == q;p = fa[p]) c[p][w] = x;
			}
		}
	}
	int head[maxn], next[maxn], rt[maxn];
	inline void dfs0(int x) {
		if(right[x]) add(rt[x], right[x]);
		for(int i = head[x];i;i = next[i]) dfs0(i), rt[x] = merge(rt[x], rt[i]);
	}
	inline void bd() {
		for(int i = 2;i <= tot;++i) next[i] = head[fa[i]], head[fa[i]] = i;
		dfs0(1);
	}
	inline int count(int ql, int qr, int x, int len) {
		return qr - ql + 1 >= len ? ask(rt[x], ql + len - 1, qr) : 0;
	}
}

struct edge {
	int to, nxt;
	char v;
} way[maxn << 1];
int h[maxn], num;
inline void link(int x, int y, char v) {
	way[++num] = {y, h[x], v}, h[x] = num;
	way[++num] = {x, h[y], v}, h[y] = num;
}
int size[maxn], son[maxn], dfn[maxn], top[maxn], tot;
int fav[maxn], dep[maxn], fa[maxn];
inline void dfs0(int x, int fa = 0) {
	size[x] = 1, dep[x] = dep[fa] + 1;
	for(int i = h[x];i;i = way[i].nxt) if(way[i].to != fa) {
		fav[way[i].to] = way[i].v;
		dfs0(way[i].to, x);
		size[x] += size[way[i].to];
		if(size[way[i].to] > size[son[x]]) son[x] = way[i].to;
	}
}
char s[maxn];
ll pw[maxn];
const ll mod = 4000000007;
const ll base = 1145141919810 % mod;

inline void dfs1(int x, int top, int fa = 0) {
	::fa[x] = fa;
	dfn[x] = ++ tot, ::top[x] = top;
	s[tot] = fav[x];
	if(son[x]) 
		dfs1(son[x], top, x);
	for(int i = h[x];i;i = way[i].nxt) if(way[i].to != fa && way[i].to != son[x]) {
		dfs1(way[i].to, way[i].to, x);
	}
}
char buf[maxn];
int idx, len, ans;
int x0, x1;
ll Hash[maxn];
inline void ps(char c) {
	buf[++idx] = c;
	Hash[idx] = (Hash[idx - 1] * base + c) % mod;
}
inline ll get() {
	return idx >= len ? (Hash[idx] + Hash[idx - len] * ll(mod - pw[len])) % mod : -1;
}
inline void push(int l, int r, ll h0) {
	if(l <= r) {
		ans += sam::count(l, r, x0, len);
		int i = l;
		for(;i <= r && i < l + len - 1;++i) {
			ps(s[i]);
			ans += get() == h0;
		}
		i = std::max(i, r - len + 2);
		for(;i <= r;++i) ps(s[i]);
	} else {
		ans += sam::count(r, l, x1, len);
		int i = l;
		for(;i >= r && i > l - len + 1;--i) ps(s[i]), ans += get() == h0;
		i = std::min(i, r + len - 2);
		for(;i >= r;--i) ps(s[i]);
	}
}
inline int ask(int x, int y, const char * s) {
	std::vector<std::pair<int, int>> v0, v1;
	for(;top[x] != top[y];) {
		if(dep[top[x]] > dep[top[y]]) {
			v0.emplace_back(dfn[x], dfn[top[x]]);
			x = fa[top[x]];
		} else {
			v1.emplace_back(dfn[top[y]], dfn[y]);
			y = fa[top[y]];
		}
	}
	if(dfn[x] < dfn[y]) v0.emplace_back(dfn[x] + 1, dfn[y]);
	if(dfn[x] > dfn[y]) v0.emplace_back(dfn[x], dfn[y] + 1);
	len = strlen(s);
	x0 = x1 = 1;
	idx = ans = 0;
	ll hs = 0;
	for(int i = 0;i < len;++i) x0 = sam::c[x0][s[i] - 'a'], hs = (hs * base + s[i] - 'a') % mod;
	for(int i = len - 1;i >= 0;--i) x1 = sam::c[x1][s[i] - 'a'];
	for(int i = 0;i < v0.size();++i) push(v0[i].first, v0[i].second, hs);
	for(int i = v1.size() - 1;i >= 0;--i) push(v1[i].first, v1[i].second, hs);
	return ans;
}
int main() {
	*pw = 1;
	for(int i = 1;i < maxn;++i) {
		pw[i] = pw[i - 1] * base % mod;
	}
	std::ios::sync_with_stdio(false), std::cin.tie(0);
	cin >> n;
	for(int i = 1;i < n;++i) {
		int u, v; char L;
		cin >> u >> v >> L;
		link(u, v, L - 'a');
	}
	dfs0(1);
	dfs1(1, 1);
	for(int i = 1;i <= n;++i) {
		sam::apd(s[i], i);
	}
	sam::bd();
	cin >> q;
	for(int i = 1, x, y;i <= q;++i) {
		static char s[200];
		cin >> x >> y >> s;
		cout << ask(x, y, s) << '\n';
	}
}