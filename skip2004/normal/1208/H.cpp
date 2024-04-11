#include<bits/stdc++.h>
const int maxn = 100100;
using std::cin;
using std::cout;
const int inf = 1e6;

struct mes
{
	int blue, red;
};
const mes E = (mes) {inf, -inf};

inline mes operator + (const mes & a, const mes & b) {
	return (mes) {
		std::min(a.blue, std::max(b.blue, a.red)), 
		std::min(a.blue, std::max(b.red, a.red)), 
	};
}

int c[maxn];
int n, k, q; struct edge {
	int to, nxt;
} way[maxn << 1];
int h[maxn], num;
inline void link(int x, int y) {
	way[++num] = {y, h[x]}, h[x] = num;
	way[++num] = {x, h[y]}, h[y] = num;
}

std::mt19937 rd(time(0));
struct Set {
	struct node{
		node * ls, * rs;
		int val, p;
		int size;
		inline node(int x){
			size = 1; val = x; p = rd();
			ls = rs = NULL;
		}
		inline void update(){
			size = 1;
			if(this -> ls) size += this -> ls -> size;
			if(this -> rs) size += this -> rs -> size;
		}
	};
	inline void rotaters(node *& rt){
		node * x = rt -> rs,* y = rt; rt = x;
		y -> rs = x -> ls,x -> ls = y;
		y -> update(); rt -> update();
	}
	inline void rotatels(node *& rt){
		node * x = rt -> ls,* y = rt; rt = x;
		y -> ls = x -> rs,x -> rs = y;
		y -> update(); rt -> update();
	}
	inline void ins(node *&rt,int val){
		if(rt == NULL){
			rt = new node(val);
		}else{
			if(val < rt -> val){
				ins(rt -> ls,val);
				++ (rt -> size);
				if(rt -> ls -> p > rt -> p)
					rotatels(rt);
			}else{
				ins(rt -> rs,val);
				++ (rt -> size);
				if(rt -> rs -> p > rt -> p)
					rotaters(rt);
			}
		}
	}
	inline node * merge(node * x,node * y){
		if(x == NULL) return y;
		if(y == NULL) return x;
		if(x -> p > y -> p){
			x -> rs = merge(x -> rs,y),x -> update();
			return x;
		}else{
			y -> ls = merge(x,y -> ls),y -> update();
			return y;
		}
	}
	inline void erase(node *&x,int val){
		if(x == NULL) return ;
		if(x -> val == val){
			x = merge(x -> ls,x -> rs);
			return ;
		}
		if(val < x -> val)
			erase(x -> ls,val);
		else
			erase(x -> rs,val);
		x -> update();
	}
	inline int kth(node * x,int k){
		const int lssz = x -> ls == NULL ? 0 : x -> ls -> size;
		if(k <= lssz) return kth(x -> ls,k);
		if(k == lssz + 1) return x -> val;
		return kth(x -> rs,k - lssz - 1);
	}
	inline int size(node * x) { return x == NULL ? 0 : x -> size; }
	inline std::pair<node*, int> bound(node * x, int v){
		node * ans = NULL;
		int size = 0, anssize = 0;
		for(;x != nullptr;) {
			const int lssz = this -> size(x -> ls);
			const int val = x -> val + (size + lssz) * 2;
			if(val <= v) {
				size += lssz + 1;
				x = x -> rs;
			} else {
				anssize = size + lssz;
				ans = x;
				x = x -> ls;
			}
		}
		return {ans, anssize};
	}
	node * root;
	inline void ins(int x) {
		ins(root, x);
	}
	inline void del(int x) {
		erase(root, x);
	}
	inline int calc(int T, int F = 0) {
		auto res = bound(root, T - F);
		if(res.first != nullptr) {
			int i = res.second;
			return i ? std::max(kth(root, i), T - i - i - F + 1) : T - i - i - F + 1;
		}
		int ans = T - size(root) * 2 - F + 1;
		return size(root) ? std::max(ans, kth(root, size(root))) : ans;
	}
} set[maxn];
int top[maxn], size[maxn], dfn[maxn], son[maxn], bot[maxn], fa[maxn], T[maxn], tot;
inline void dfs0(int x, int fa = 0) {
	size[x] = 1, :: fa[x] = fa;
	for(int i = h[x];i;i = way[i].nxt) if(way[i].to != fa) {
		++ T[x];
		dfs0(way[i].to, x);
		size[x] += size[way[i].to];
		if(size[way[i].to] > size[son[x]])
			son[x] = way[i].to;
	}
}

int dp[maxn];

namespace seg {
	mes tree[maxn << 2];
	const int L = 1 << 17;
	inline void upt(int pos, mes v) {
		tree[pos += L] = v;
		for(;pos >>= 1;) tree[pos] = tree[pos + pos] + tree[pos + pos + 1];
	}
	inline mes ask(int l, int r) {
		l += L - 1, r += L + 1;
		mes A = E, B = E;
		for(;l != r;) {
			if((l & 1) == 0) A = A + tree[l ^ 1];
			if((r & 1) == 1) B = tree[r ^ 1] + B;
			l >>= 1;
			r >>= 1;
		}
		return A + B;
	}
}
inline void calc(int x) {
	if(T[x] == 0) {
		dp[x] = c[x] ? inf : -inf;
	} else {
		mes t = seg::ask(dfn[x], dfn[bot[x]]);
		dp[x] = std::min(t.blue, t.red);
	}
}
mes TS[maxn];
inline void reset(int x) {
	if(T[x] == 0) {
		seg::upt(dfn[x], TS[x] = (mes) {
			c[x] ? inf : -inf, 
			c[x] ? inf : -inf, 
		});
	} else {
		seg::upt(dfn[x], TS[x] = (mes) { set[x].calc(T[x]), set[x].calc(T[x], 2), });
	}
}

inline void dfs1(int x, int top, int fa = 0) {
	dfn[x] = ++ tot;
	::top[x] = top;
	if(son[x]) {
		dfs1(son[x], top, x);
		bot[x] = bot[son[x]];
	} else {
		bot[x] = x;
	}
	for(int i = h[x];i;i = way[i].nxt) if(way[i].to != fa && way[i].to != son[x]) {
		dfs1(way[i].to, way[i].to, x);
		set[x].ins(dp[way[i].to]);
	}
	reset(x);
	calc(x);
}

inline void update(int x) {
	for(;fa[x = top[x]];x = fa[x]) {
		set[fa[x]].del(dp[x]);
		calc(x);
		set[fa[x]].ins(dp[x]);
		reset(fa[x]);
	}
}

int main() {
	std::ios::sync_with_stdio(false), std::cin.tie(0);
	cin >> n >> k;
	for(int i = 1, u, v;i < n;++i) {
		cin >> u >> v;
		link(u, v);
	}
	for(int i = 1;i <= n;++i) {
		cin >> c[i];
	}
	dfs0(1);
	dfs1(1, 1);
	cin >> q;
	for(int i = 1, opt, v, c;i <= q;++i) {
		cin >> opt;
		if(opt == 1) {
			cin >> v;
			calc(v);
			cout << (k >= dp[v] ? 0 : 1) << '\n';
		} else if(opt == 2) {
			cin >> v >> c;
			::c[v] = c;
			reset(v);
			update(v);
		} else {
			cin >> k;
		}
	}
}