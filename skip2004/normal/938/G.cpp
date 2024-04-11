#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 200200;
typedef std::pair<int, int> pr;
struct T {
	int u, v, w;
	inline T(int U = 0, int V = 0, int W = 0): u(std::min(U, V)), v(std::max(U, V)), w(W) {}
	inline int operator < (const T & y) const {
		return u == y.u ? v < y.v : u < y.u;
	}
};
typedef long long ll;
typedef unsigned u32;
int n, m, q;
inline void down(u32 & x, u32 y) {
	if(x > y) {
		x = y;
	}
}
struct base {
	int a[31];
	inline void ins(u32 x) {
		for(int i = 30;i >= 0;--i) {
			if(x >> i & 1) {
				if(a[i]) {
					x ^= a[i];
				} else {
					a[i] = x;
					return ;
				}
			}
		}
	}
	inline u32 qry(u32 x) {
		for(int i = 30;i >= 0;--i) {
			down(x, x ^ a[i]);
		}
		return x;
	}
} now;
int opt[maxn], x[maxn], y[maxn], d[maxn], ans[maxn];
std::map<T, int> map;
std::vector<T> edge[maxn << 2];
inline void add(int ql,int qr,T e,int cur = 1,int l = 1,int r = q) {
	if(ql <= l && r <= qr) {
		edge[cur].push_back(e);
		return ;
	}
	int mid = l + r >> 1;
	if(ql <= mid) add(ql, qr, e, cur << 1, l, mid);
	if(mid < qr) add(ql, qr, e, cur << 1 | 1, mid + 1, r);
} 
int fa[maxn], size[maxn], w[maxn];
pr stack[maxn]; int top;
inline int find(int x) {
	for(;x != fa[x];x = fa[x]);
	return x;
}
inline pr get(int x) {
	int o = 0;
	for(;x != fa[x];x = fa[x]) o ^= w[x];
	return {o, x};
}
inline int link(int x,int y,int v) {
	pr px = get(x), py = get(y);
	x = px.second; y = py.second;
	v ^= px.first ^ py.first;
	if(x != y) {
		if(size[x] > size[y]) {
			std::swap(x, y);
		}
		size[y] += size[x];
		fa[x] = y;
		w[x] = v;
		stack[++top] = pr(x, y);
		return 0;
	} else {
		return v;
	}
}
inline void pop_top() {
	pr x = stack[top--];
	size[x.second] -= size[x.first];
	fa[x.first] = x.first;
	w[x.first] = 0;
}
inline void solve(int cur, base now, int l = 1,int r = q) {
	int t = top;
	for(T i : edge[cur]) {
		now.ins(link(i.u, i.v, i.w));
	}
	if(l == r) {
		if(opt[l] == 3) {
			ans[l] = now.qry(link(x[l], y[l], 0));
		}
	} else {
		int mid = l + r >> 1;
		solve(cur << 1, now, l, mid);
		solve(cur << 1 | 1, now, mid + 1, r);
	}
	for(;top != t;) pop_top();
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	rep(i, 1, m) {
		int x, y, d;
		cin >> x >> y >> d;
		map[T(x, y, d)] = 1;
	}
	cin >> q;
	rep(i, 1, q) {
		cin >> opt[i] >> x[i] >> y[i];
		if(opt[i] == 1) {
			cin >> d[i];
			map[T(x[i], y[i], d[i])] = i;
		}
		if(opt[i] == 2) {
			auto it = map.find(T(x[i], y[i], 0));
			add(it -> second, i, it -> first);
			map.erase(it);
		}
	}
	for(auto i : map) {
		add(i.second, q, i.first);
	}
	rep(i, 1, n) {
		fa[i] = i;
		size[i] = 1;
	}
	solve(1, now);
	rep(i, 1, q) {
		if(opt[i] == 3) {
			cout << ans[i] << '\n';
		}
	}
}