#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin;
using std::cout;

typedef unsigned long long u64;
typedef double db;
typedef long long ll;
typedef unsigned u32;

int n, m;
const int N = 200200;

struct edge {
	int to, nxt; ll v;
} e[N << 1];
int h[N], num = 1;
inline void link(int x, int y, ll v) {
	e[++num] = (edge) {y, h[x], v}, h[x] = num;
	e[++num] = (edge) {x, h[y], v}, h[y] = num;
}

int who[N];
ll w[N];

int fa[N], anc[N], dep[N];
inline int find(int x) {
	return anc[x] == x ? x : anc[x] = find(anc[x]);
}

inline void dfs0(int x, int fa = 0) {
	::fa[x] = fa, dep[x] = dep[fa] + 1;

	for(int i = h[x];i;i = e[i].nxt) if(e[i].to != fa) {
		who[i >> 1] = e[i].to;
		w[e[i].to] = e[i].v;
		dfs0(e[i].to, x);
	}
}

inline ll ask(int x, int y, ll c) {
	for(;;) {
		x = find(x), y = find(y);
		if(x == y) break;
		if(dep[x] < dep[y]) std::swap(x, y);
		c /= w[x], x = fa[x];
		if(c == 0) break;
	}
	return c;
}

int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m;
	for(int i = 1, x, y;i < n;++i) {
		ll v;
		cin >> x >> y >> v;
		link(x, y, v);
	}
	dfs0(1);
	rep(i, 1, n) {
		anc[i] = i;
		if(w[i] == 1) anc[i] = fa[i];
	}
	rep(i, 1, m) {
		int opt, x, y, p; ll c;
		cin >> opt;
		if(opt == 1) {
			cin >> x >> y >> c;
			cout << ask(x, y, c) << '\n';
		} else {
			cin >> p >> c;
			w[who[p]] = c;
			if(c == 1 && anc[who[p]] == who[p]) {
				anc[who[p]] = fa[who[p]];
			}
		}
	}
}