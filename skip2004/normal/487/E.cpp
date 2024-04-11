#include<bits/stdc++.h>
using std::cin;
using std::cout;
const int maxn = 100100;
int n, m, q;
int a[maxn];
int node_cnt;

struct heap {
	std::priority_queue<int, std::vector<int>, std::greater<int>> q0, q1;
	inline void push(int x) {
		q0.push(x);
	}
	inline void pop(int x) {
		q1.push(x);
	}
	inline int top() {
		for(;q1.size() && q0.top() == q1.top();)
			q0.pop(), q1.pop();
		return q0.top();
	}
};
namespace tr {
	const int N = maxn << 1;
	namespace lct {
		int son[N][2], fa[N], min[N], val[N], tag[N];
		inline int get(int x, int p = 1) { return son[fa[x]][p] == x; }
		inline int is_root(int x) { return !(get(x) || get(x, 0)); }
		inline void update(int x) {
			min[x] = val[x];
			if(son[x][0] && min[son[x][0]] < min[x]) min[x] = min[son[x][0]];
			if(son[x][1] && min[son[x][1]] < min[x]) min[x] = min[son[x][1]];
		}
		inline void put(int x) {
			std::swap(son[x][0], son[x][1]);
			tag[x] ^= 1;
		}
		inline void pushdown(int x) {
			if(tag[x]) {
				put(son[x][0]);
				put(son[x][1]);
				tag[x] = 0;
			}
		}
		inline void down(int x) {
			if(!is_root(x)) down(fa[x]);
			pushdown(x);
		}
		inline void rotate(int x) {
			int y = fa[x], z = fa[y], b = get(x);
			if(!is_root(y)) son[z][get(y)] = x;
			son[y][b] = son[x][!b], son[x][!b] = y;
			fa[son[y][b]] = y, fa[y] = x, fa[x] = z;
			update(y);
		}
		inline void splay(int x) {
			for(down(x);!is_root(x);rotate(x)) if(!is_root(fa[x]))
				rotate(get(x) ^ get(fa[x]) ? x : fa[x]);
			update(x);
		}
		inline void access(int x) {
			for(int t = 0;x;son[x][1] = t, t = x, x = fa[x])
				splay(x);
		}
		inline void makeroot(int x) {
			access(x), splay(x), put(x);
		}
		inline void split(int x, int y) {
			makeroot(x), access(y), splay(y);
		}
		inline int list_min(int x, int y) {
			split(x, y);
			return min[y];
		}
		inline void upt(int x, int v) {
			makeroot(x), val[x] = v, update(x);
		}
	}
	heap set[N];
	int is[N], fa[N], st[20][N], dfn[N], tot;
	inline int min(int x, int y) {
		return dfn[x] < dfn[y] ? x : y;
	}
	inline int lca(int x, int y) {
		if(dfn[x] > dfn[y]) std::swap(x, y);
		const int lg = std::__lg(dfn[y] - dfn[x]);
		return x != y ? min(st[lg][dfn[x]], st[lg][dfn[y] - (1 << lg)]) : x;
	}
	struct edge {
		int to, nxt;
	} way[N << 1];
	int h[N], num;
	inline void link(int x, int y) {
		// std::cerr << "link_edge : " << x << ' ' << y << '\n';
		way[++num] = {y, h[x]}, h[x] = num;
		way[++num] = {x, h[y]}, h[y] = num;
	}

	inline void dfs0(int x, int fa = 0) {
		st[0][tot] = fa, dfn[x] = ++ tot, tr::fa[x] = fa;
		for(int i = h[x];i;i = way[i].nxt) if(way[i].to != fa) {
			dfs0(way[i].to, x);
			if(is[x]) set[x].push(lct::val[way[i].to]);
		}
	}

	inline void init() {
		dfs0(1);
		for(int i = 1;i <= node_cnt;++i) {
			lct::fa[i] = fa[i];
		}
		for(int i = 1;i < 20;++i) {
			for(int j = 1;j + (1 << i) - 1 < node_cnt;++j) {
				st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
			}
		}
	}

	inline int ask(int x, int y) {
		int lca = tr::lca(x, y);
		int res = lct::list_min(x, y);
		if(is[lca]) res = std::min(res, lct::val[fa[lca]]);
		return res;
	}
	inline void upt(int x, int v) {
		if(is[fa[x]]) {
			set[fa[x]].pop(lct::val[x]);
			set[fa[x]].push(v);
			lct::upt(fa[x], set[fa[x]].top());
		}
		lct::upt(x, v);
	}
}

struct edge {
	int to, nxt;
} way[maxn << 1];
int h[maxn], num;
inline void link(int x, int y) {
	way[++num] = {y, h[x]}, h[x] = num;
	way[++num] = {x, h[y]}, h[y] = num;
}
int dfn[maxn], low[maxn], st[maxn], top, cnt;
inline void tarjan(int x, int fa = 0) {
	st[++top] = x, dfn[x] = low[x] = ++ cnt;
	for(int i = h[x];i;i = way[i].nxt) if(way[i].to != fa) {
		if(!dfn[way[i].to]) {
			tarjan(way[i].to, x);
			low[x] = std::min(low[x], low[way[i].to]);
			if(low[way[i].to] >= dfn[x]) {
				int nd = ++ node_cnt;
				tr::is[nd] = 1;
				tr::link(x, nd);
				while(st[top] != way[i].to) tr::link(st[top--], nd);
				tr::link(st[top--], nd);
			}
		} else {
			low[x] = std::min(low[x], dfn[way[i].to]);
		}
	}
}
int main() {
//	freopen("1.in", "r", stdin);
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m >> q;
	for(int i = 1;i <= n;++i) {
		cin >> a[i];
	}
	for(int i = 1, a, b;i <= m;++i) {
		cin >> a >> b;
		link(a, b);
	}
	node_cnt = n;
	tarjan(1);
	tr::init();
	for(int i = 1;i <= n;++i) {
		tr::upt(i, a[i]);
	}
	for(int i = 1;i <= q;++i) {
		char type; int x, y, c;
		cin >> type;
		if(type == 'C') {
			cin >> x >> c;
			tr::upt(x, c);
			a[x] = c;
		} else {
			cin >> x >> y;
			cout << tr::ask(x, y) << '\n';
		}
	}
}