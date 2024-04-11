#include<bits/stdc++.h>
const int maxn = 500200;
const int mod = 998244353;
typedef long long ll;
inline ll pow(ll a,int b,ll ans = 1) {
	for(;b;b >>= 1,a = a * a % mod) if(b & 1) ans = ans * a % mod;
	return ans;
}
inline ll inverse(int x){ return pow(x, mod - 2); }
inline void reduce(int & x){ x += x >> 31 & mod; }
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
namespace lct {
	const int N = 3e6;
	int son[N][2], fa[N], size[N], val[N], min[N], tag[N];
	int map[(int) 3e7], tot;
	inline bool get(int x,int p = 1){ return son[fa[x]][p] == x; }
	inline bool is_root(int x){ return !(get(x,0) || get(x)); }
	inline void up(int x) {
		size[x] = size[son[x][0]] + size[son[x][1]] + 1, min[x] = x;
		if(son[x][0] && val[min[son[x][0]]] < val[min[x]]) min[x] = min[son[x][0]];
		if(son[x][1] && val[min[son[x][1]]] < val[min[x]]) min[x] = min[son[x][1]];
	}
	inline void put(int x) { if(x) std::swap(son[x][0], son[x][1]), tag[x] ^= 1; }
	inline void down(int x) { if(tag[x]) put(son[x][0]), put(son[x][1]), tag[x] = 0; }
	inline void pushdown(int x) { if(!is_root(x)) pushdown(fa[x]); down(x); }
	inline void rotate(int x) {
		int y = fa[x], z = fa[y], b = get(x);
		if(!is_root(y)) son[z][get(y)] = x;
		son[y][b] = son[x][!b], son[x][!b] = y;
		fa[son[y][b]] = y,fa[y] = x,fa[x] = z;
		up(y);
	}
	inline void splay(int x) {
		for(pushdown(x);!is_root(x);rotate(x)) if(!is_root(fa[x]))
			rotate(get(x) ^ get(fa[x]) ? x : fa[x]);
		up(x);
	}
	inline void access(int x) {
		for(int t = 0;x;son[x][1]=t,t=x,x=fa[x])
			splay(x);
	}
	inline void make_root(int x) {
		access(x), splay(x), put(x);
	}
	inline bool split(int x,int y) {
		make_root(x), access(y), splay(y);
		for(;son[y][0];y = son[y][0]);
		return splay(y), x == y;
	}
	inline int getmap(int x){ return map[x] ? map[x] : map[x] = ++ tot; }
	inline void base_cut(int x,int y) {
		split(x, y); splay(y);
		if(son[y][0] == x && fa[x] == y) son[y][0] = fa[x] = 0, up(y);
	}
	inline void cut(int x,int y) { base_cut(getmap(x),getmap(y)); }
	inline void cut_to(int x,int y) {
		split(x, y); int now = son[x][1];
		for(down(now);son[now][0];down(now = son[now][0]));
		base_cut(x, now);
	}
	inline bool good(int x,int y,int edge) {
		x = getmap(x); y = getmap(y); up(edge = getmap(edge));
		if(!split(x,y)) {
			make_root(x), make_root(y);
			fa[x] = fa[y] = edge;
			return 1;
		} else {
			if((size[x] + 1) % 4 == 0) {
				int o = min[x];
				if(val[o] < val[edge]) {
					cut_to(o, x); cut_to(o, y);
					make_root(x), make_root(y);
					fa[x] = fa[y] = edge;
				}
				return 1;
			} else return 0;
		}
	}
}
int a[maxn], b[maxn], color[maxn], id[maxn];
int e[maxn], c[maxn];
std::priority_queue<int,std::vector<int>,std::greater<int>> heap[maxn];
int n, m, k, q;
int main() {
	std::ios::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> m >> k >> q; int edge = n * k;
	for(int i = 1;i <= m;++i) {
		std::cin >> a[i] >> b[i];
		heap[i].push(q + 1);
	}
	for(int i = 1;i <= q;++i) std::cin >> e[i] >> c[i], heap[e[i]].push(i);
	for(int i = 1, e, c;i <= q;++i) {
		e = ::e[i], c = ::c[i], heap[e].pop();
		lct::val[lct::getmap(++edge)] = heap[e].top();
		lct::val[lct::getmap(a[e] + (c - 1) * n)] = 1e9;
		lct::val[lct::getmap(b[e] + (c - 1) * n)] = 1e9;
		if(c == color[e]) {
			lct::cut(id[e], a[e] + (c - 1) * n);
			lct::cut(id[e], b[e] + (c - 1) * n);
		}
		if(lct::good(a[e] + (c - 1) * n,b[e] + (c - 1) * n,edge)) {
			if(color[e]) {
				lct::cut(id[e], a[e] + (color[e] - 1) * n);
				lct::cut(id[e], b[e] + (color[e] - 1) * n);
			}
			id[e] = edge; color[e] = c;
			std::cout << "YES" << '\n';
		} else {
			if(color[e]) {
				lct::cut(id[e], a[e] + (color[e] - 1) * n);
				lct::cut(id[e], b[e] + (color[e] - 1) * n);
				lct::good(a[e] + (color[e] - 1) * n,b[e] + (color[e] - 1) * n, edge);
				id[e] = edge;
			}
			std::cout << "NO" << '\n';
		}
	}
}