#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin;
using std::cout;

typedef unsigned long long u64;
struct BS {
	static const int size = 200000 / 64 + 1;
	u64 a[size];
	inline int count() const {
		int sum = 0;
		for(int i = 0;i != size;++i) {
			sum += __builtin_popcountll(a[i]);
		}
		return sum;
	}
	inline bool test(int pos) const { return a[pos >> 6] >> (pos & 63) & 1; }
	inline void set(int pos) { a[pos >> 6] |= 1ull << (pos & 63); }
	inline void reset(int pos) { a[pos >> 6] &= ~(1ull << (pos & 63)); }
	inline BS& operator &= (const BS & x) {
		for(int i = 0;i != size;++i) {
			a[i] &= x.a[i];
		}
		return * this;
	}
	inline BS& shift(const BS & A, int __shift, const BS & B) {
		const int __wshift = __shift / 64;
		const int __offset = __shift % 64;
		const int _Nw = size;
		const u64 * _M_w = A.a;

		if (__offset == 0)
			for (int __n = _Nw - 1; __n >= __wshift; --__n)
				a[__n] = _M_w[__n - __wshift] & B.a[__n];
		else
		{
			const int __sub_offset = (64
					- __offset);
			for (int __n = _Nw - 1; __n > __wshift; --__n)
				a[__n] = ((_M_w[__n - __wshift] << __offset)
						| (_M_w[__n - __wshift - 1] >> __sub_offset)) & B.a[__n];
			a[__wshift] = (_M_w[0] << __offset) & B.a[__wshift];
		}

		std::fill(a + 0, a + __wshift, 0ull);
		return *this;
	}
};
const int N = 200005;
const int M = 400005;
const int B = 400;
struct SAM {
	char T[N];
	int c[M][27], mx[M], fa[M], right[M], la, tot;
	int n;

	inline void append(int w, int o) {
		int p = la, now = la = ++ tot;
		mx[now] = mx[p] + 1, right[now] = o;
		for(;p && !c[p][w];p = fa[p])
			c[p][w] = now;
		if(!p) fa[now] = 1;
		else {
			int q = c[p][w];
			if(mx[q] == mx[p] + 1)
				fa[now] = q;
			else {
				int x = ++ tot;
				mx[x] = mx[p] + 1;
				memcpy(c[x], c[q], sizeof(c[0]));
				fa[x] = fa[q], fa[q] = fa[now] = x;
				for(;p && c[p][w] == q;p = fa[p])
					c[p][w] = x;
			}
		}
	}
	int head[M], next[M];

	inline void link(int fa, int x) {
		next[x] = head[fa], head[fa] = x;
	}
	int L[M], R[M], stack[N], cnt;
	struct qwq {
		int l, r;
		BS w;
		inline void move(int L, int R, SAM * A) {
			for(;l > L;) w.set(A -> stack[--l]);
			for(;r < R;) w.set(A -> stack[++r]);
			for(;l < L;) w.reset(A -> stack[l++]);
			for(;r > R;) w.reset(A -> stack[r--]);
		}
	};
	qwq* AWA[N / B + 1][N / B + 1];
	qwq mem[N / B * 4], *_ptr = mem;
	inline void dfs0(int x) {
		L[x] = cnt + 1;
		if(right[x]) stack[++cnt] = right[x];
		for(int i = head[x];i;i = next[i]) {
			dfs0(i);
		}
		R[x] = cnt;
	}
	inline void rev() {
		for(int i = 1;i <= cnt;++i) stack[i] = n + 1 - stack[i];
	}
	inline const BS& get(int l, int r) {
		AWA[l / B][r / B] -> move(l, r, this);
		return AWA[l / B][r / B] -> w;
	}
	inline const BS& get(int id) {
		static BS EP;
		if(id == 0) return EP;
		return get(L[id], R[id]);
	}
	inline void init() {
		la = tot = 1;
		for(int i = 1;i <= n;++i)
			append(T[i] - 'a', i);
		for(int i = 2;i <= tot;++i) {
			link(fa[i], i);
		}
		dfs0(1);
		for(int i = 1;i <= tot;++i) {
			qwq*& ptr = AWA[L[i] / B][R[i] / B];
			if(ptr == nullptr) {
				ptr = _ptr++;
				ptr -> l = L[i];
				ptr -> r = L[i] - 1;
			}
		}
	}
} rev, sam;
int n, m, q;
struct edge { int to, nxt, v; } e[N << 1];
int h[N], num;
inline void link(int x, int y, int v) {
	e[++num] = {y, h[x], v}, h[x] = num;
	e[++num] = {x, h[y], v}, h[y] = num;
}
int L[N], R[N];
struct qy { int u, v, l, r, id; };
int size[N], vis[N];;
inline void dfs0(int x, int fa = 0) {
	size[x] = 1;
	for(int i = h[x];i;i = e[i].nxt) if(!vis[e[i].to] && e[i].to != fa) {
		dfs0(e[i].to, x);
		size[x] += size[e[i].to];
	}
}
int min, root;
inline void dfs1(int x, int s, int fa = 0) {
	int max = s - size[x];
	for(int i = h[x];i;i = e[i].nxt) if(!vis[e[i].to] && e[i].to != fa) {
		dfs1(e[i].to, s, x);
		max = std::max(max, size[e[i].to]);
	}
	if(max < min) min = max, root = x;
}
inline int getroot(int x) {
	dfs0(x), min = 1e9, dfs1(x, size[x]);
	return root;
}
int sa[N], sb[N];
int lab[N], dep[N];
std::vector<qy> p[N];
inline void dfs2(int x, int sa, int sb, int fa = 0) {
	::sa[x] = sa; ::sb[x] = sb;
	for(int i = h[x];i;i = e[i].nxt) if(!vis[e[i].to] && e[i].to != fa) {
		dfs2(e[i].to, sam.c[sa][e[i].v], rev.c[sb][e[i].v], x);
	}
}
inline void dfs3(int x, int lab, int fa = 0) {
	::lab[x] = lab, dep[x] = dep[fa] + 1;
	for(int i = h[x];i;i = e[i].nxt) if(!vis[e[i].to] && e[i].to != fa) {
		dfs3(e[i].to, lab, x);
	}
}
int ans[N];
inline int count(const BS & x, int l, int r) {
	if(l > r) return 0;
	using u64 = unsigned long long;
	int ans = 0;
	for(;l <= r && l % 64 != 0;++l) ans += x.test(l);
	for(;l <= r && r % 64 != 63;--r) ans += x.test(r);
	if(l > r) return ans;
	const int L = l / 64, R = r / 64;
	u64 * ARR = (u64*)&x;
	for(int i = L;i <= R;++i) ans += __builtin_popcountll(ARR[i]);
	return ans;
}
inline void solve(int x, std::vector<qy> o) {
	if(o.empty()) return ;
	x = getroot(x);
	dfs2(x, 1, 1);
	vis[x] = 1, dep[x] = 0, lab[x] = 0;
	for(int i = h[x];i;i = e[i].nxt) if(!vis[e[i].to]) {
		dfs3(e[i].to, e[i].to, x);
		p[e[i].to].clear();
	}
	for(const qy & x : o) {
		if(lab[x.u] && lab[x.v] && lab[x.u] == lab[x.v]) {
			p[lab[x.u]].push_back(x);
		} else {
			const BS & a = rev.get(sb[x.u]);
			const BS & b = sam.get(sa[x.v]);
			static BS Z;
			const int len = dep[x.u] + dep[x.v];
			Z.shift(a, len - 1, b);
			ans[x.id] = count(Z, x.l + len - 1, x.r);
		}
	}
	for(int i = h[x];i;i = e[i].nxt) if(!vis[e[i].to]) {
		solve(e[i].to, p[e[i].to]);
		std::vector<qy>().swap(p[e[i].to]);
	}
}
int main() {
//	freopen("a.in", "r", stdin);
//	freopen("1.out", "w", stdout);
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m >> q;
	for(int i = 1, u, v;i < n;++i) {
		char c; cin >> u >> v >> c;
		link(u, v, c - 'a');
	}

	std::string T;
	for(int i = 1, o = 0;i <= m;++i) {
		std::string s; cin >> s;
		if(i != m) s += char('a' + 26);
		T += s;
		L[i] = o + 1;
		R[i] = o += s.size();
	}
	for(int i = 1;i <= R[m];++i) {
		sam.T[i] = T[i - 1];
		rev.T[i] = T[T.size() - i];
	}
	sam.n = rev.n = R[m];
	sam.init();
	rev.init();
	rev.rev();
	std::vector<qy> o(q);
	for(int i = 0;i < q;++i) {
		cin >> o[i].u >> o[i].v >> o[i].l >> o[i].r; o[i].id = i;
		o[i].l = L[o[i].l]; o[i].r = R[o[i].r];
	}
	solve(1, o);
	for(int i = 0;i < q;++i) cout << ans[i] << '\n';
//	std::cerr << double(clock()) / CLOCKS_PER_SEC << '\n';
}