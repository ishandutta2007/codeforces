#include <bits/stdc++.h>

using namespace std;

long long read() {
	long long x = 0 , f = 1 , c = getchar();
	while (c > '9' || c < '0') f = c == '-' ? -1 : 1 , c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48 , c = getchar();
	return x * f;
}

const long long maxn = 3e5;

long long n, m, money, pos[maxn];
pair <long long, long long> delet_which;

struct graph{
	long long x, y, w, c, id;

	bool operator < (const graph &t) const {
		return w < t.w || w == t.w && c < t.c;
	}
}p[maxn];

namespace Kruscal{

	long long fa[maxn], Value;

	bool choose[maxn];

	long long find(long long x) {
		return x == fa[x] ? x : fa[x] = find(fa[x]);
	}

	void init() {
		for (long long i = 1; i <= n; i ++) fa[i] = i;
		memset(choose, 0, sizeof choose);
	}

	void solve() {
		sort(p + 1, p + m + 1);
		for (long long i = 1; i <= m; i ++) pos[p[i].id] = i;
		for (long long i = 1; i <= m; i ++) {
			long long f1 = find(p[i].x), f2 = find(p[i].y);
			if (f1 == f2) continue;
			fa[f1] = f2;
			Value += p[i].w;
			choose[p[i].id] = 1;
		}
	}
}

namespace Tree{

	long long fa[maxn], head[maxn], cnt, seg, cost;
	long long siz[maxn], son[maxn], dep[maxn], dfn[maxn], top[maxn];

	struct edge {
		long long nxt, to, w, c;
	}e[maxn << 1];

	struct segment_tree {
		long long w, id, l, r;

		segment_tree() {
			w = id = 0;
		}
	}t[maxn << 2];

	void insert(long long u, long long v, long long w, long long c) {
		e[++ cnt].nxt = head[u], e[head[u] = cnt].to = v, e[cnt].w = w, e[cnt].c = c;
	}

	void dfs(long long u) {
		siz[u] = 1;
		for (long long i = head[u]; i; i = e[i].nxt) {
			long long v = e[i].to;
			if (v != fa[u]) {
				fa[v] = u;
				dep[v] = dep[u] + 1;
				dfs(v);
				siz[u] += siz[v];
				if (siz[v] > siz[son[u]]) son[u] = v;
			}
		}
	}

	void DFS(long long u, long long tp) {
		dfn[u] = ++ seg;
		top[u] = tp;
		if (son[u]) DFS(son[u], tp);
		for (long long i = head[u]; i; i = e[i].nxt) {
			long long v = e[i].to;
			if (v == fa[u] || v == son[u]) continue;
			DFS(v, v);
		}
	}

	void push_up(long long k) {
		if (t[k << 1].w > t[k << 1 | 1].w) t[k].id = t[k << 1].id, t[k].w = t[k << 1].w;
		else t[k].id = t[k << 1 | 1].id, t[k].w = t[k << 1 | 1].w;
	}

	void update(long long k, long long l, long long r, long long x, long long v, long long id) {
		if (l == r) {
			t[k].w = v;
			t[k].id = id;
			return;
		}
		long long mid = l + r >> 1;
		if (x <= mid) update(k << 1, l, mid, x, v, id);
		else update(k << 1 | 1, mid + 1, r, x, v, id);
		push_up(k);
	}

	segment_tree query(long long k, long long l, long long r, long long x, long long y) {
//		printf("%d %d\n",x , y);
		if (x == l && r == y) return t[k];
		long long mid = l + r >> 1;
		if (y <= mid) return query(k << 1, l, mid, x, y);
		else if (x > mid) return query(k << 1 | 1, mid + 1, r , x, y);
		else {
			segment_tree L = query(k << 1, l, mid, x, mid);
			segment_tree R = query(k << 1 | 1, mid + 1, r, mid + 1, y);
			if (L.w > R.w) return L;
			else return R;
		}
	}
	
	void B(long long k, long long l, long long r){
		t[k].l = l, t[k].r = r;
		if (l == r) return;
		long long mid = l + r >> 1;
		B(k << 1, l, mid);
		B(k << 1 | 1, mid + 1, r);
	}

	void build() {
		
		B(1, 1, n);

		for (long long i = 1; i <= m; i ++) {
			if (Kruscal :: choose[p[i].id] == 0) continue;
			insert(p[i].x, p[i].y, p[i].w, p[i].c);
			insert(p[i].y, p[i].x, p[i].w, p[i].c);
		}

		dfs(1);
		DFS(1, 1);

		for (long long i = 1; i <= m; i ++) {
			if (Kruscal :: choose[p[i].id] == 0) continue;
			long long init = p[i].x;
			if (dep[init] < dep[p[i].y]) init = p[i].y;
			update(1, 1, n, dfn[init], p[i].w, p[i].id);
		}
	}

	segment_tree Ask(long long x, long long y) {
		segment_tree ret, tmp;
		while (top[x] != top[y]) {
			if (dep[top[x]] < dep[top[y]]) swap(x, y);
 			tmp = query(1, 1, n, dfn[top[x]], dfn[x]);
			if (tmp.w > ret.w) ret = tmp;
			x = fa[top[x]];
		}
		if (dfn[x] > dfn[y]) swap(x, y);
		if (x == y) return ret;
		if (fa[y] == x) tmp = query(1, 1, n, dfn[y], dfn[y]);
		else tmp = query(1, 1, n, dfn[x] + 1, dfn[y]); 
		if (tmp.w > ret.w) ret = tmp;
		return ret;
	}

	void solve(){
		cost = Kruscal :: Value;
		for (long long i = 1; i <= m; i ++) {
//			printf("%d\n", cost);
			if (Kruscal :: choose[p[i].id]) {
				long long amount = money / p[i].c;
//				printf("amount = %d\n", amount);
				if (cost > Kruscal :: Value - amount) {
					delet_which = make_pair(p[i].id, 0);
					cost = Kruscal :: Value - amount;
				}
			}
			else {
		//		printf("%d %d\n", p[i].x, p[i].y);
				segment_tree pt = Ask(p[i].x, p[i].y);
				long long tmp = Kruscal :: Value - p[pos[pt.id]].w;
//				printf("treeval = %d - %d = %d\n",  Kruscal :: Value ,  p[pos[pt.id]].w, tmp);
//				printf("ptid = %d i = %d\n", pt.id, p[i].id);
				long long amount = money / p[i].c;
//				printf("amount = %d\n", amount);
				tmp += p[i].w - amount;
//				printf("w = %d\n", p[i].w);
				if (cost > tmp) {
					delet_which = make_pair(p[i].id, pt.id);
					cost = tmp;
				}
			}
 		}
	}

}

int main() {
//	freopen("f.in", "r", stdin);
	n = read(), m = read();
	for (long long i = 1; i <= m; i ++) p[p[i].id = i].w = read();
	for (long long i = 1; i <= m; i ++) p[i].c = read();
	for (long long i = 1; i <= m; i ++) {
		p[i].x = read(), p[i].y = read();
		if (p[i].x > p[i].y) swap(p[i].x, p[i].y);
	}

	money = read();

	Kruscal :: init();
	Kruscal :: solve();

	Tree :: build();
	Tree :: solve();

//	printf("%d\n", Kruscal :: Value);
	printf("%I64d\n", Tree :: cost);
	if (delet_which.second != 0) {
		Kruscal :: choose[delet_which.second] = 0;
		Kruscal :: choose[delet_which.first] = 1;
	}
//	printf("del %d ", delet_which.first);
//	printf("%d\n", delet_which.second);
	for (long long i = 1; i <= m; i ++) {
		if (Kruscal :: choose[p[i].id]) printf("%I64d %I64d\n", p[i].id, p[i].w - ((delet_which.first) == p[i].id) * (money / p[i].c));
	}
	return 0;
}