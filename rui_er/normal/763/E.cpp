//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int n, k, m, q, L[N], R[N], pos[N], sz, tot, ans[N];
vector<int> e[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
struct Query {
	int l, r, id;
	Query(int a=0, int b=0, int c=0) : l(a), r(b), id(c) {}
	~Query() {}
	friend bool operator < (const Query& a, const Query& b) {
		if(pos[a.l] != pos[b.l]) return a.l < b.l;
		return a.r < b.r;
	}
}Q[N];
struct Dsu {
	int fa[N], sz[N];
	stack<int> stk;
	void init(int L, int R) {
		rep(i, L, R) {
			fa[i] = i;
			sz[i] = 1;
		}
		while(!stk.empty()) stk.pop();
	}
	int find(int x) {
		return x == fa[x] ? x : fa[x] = find(fa[x]);
	}
	int findd(int x) {
		return x == fa[x] ? x : findd(fa[x]);
	}
	bool merge(int x, int y, bool undo) {
		int u = x, v = y;
		if(undo) {
			u = findd(x);
			v = findd(y);
		}
		else {
			u = find(x);
			v = find(y);
		}
		if(u == v) {
			if(undo) stk.push(-1);
			return 0;
		}
		if(sz[u] < sz[v]) swap(u, v);
		sz[u] += sz[v];
		fa[v] = u;
		if(undo) stk.push(v);
		return 1;
	}
	bool undo() {
		if(stk.empty()) return 0;
		int u = stk.top(); stk.pop();
		if(u == -1) return 0;
		int v = fa[u];
		sz[v] -= sz[u];
		fa[u] = u;
		return 1;
	}
}dsu1, dsu2;
void initBlock() {
	sz = sqrt(n);
	while(++tot) {
		L[tot] = R[tot-1] + 1;
		R[tot] = min(sz*tot, n);
		rep(i, L[tot], R[tot]) pos[i] = tot;
		if(R[tot] == n) break;
	}
}

int main() {
	scanf("%d%d", &n, &k);
	scanf("%d", &m);
	rep(i, 1, m) {
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	scanf("%d", &q);
	rep(i, 1, q) {
		scanf("%d%d", &Q[i].l, &Q[i].r);
		Q[i].id = i;
	}
	initBlock();
	sort(Q+1, Q+1+q);
	int l = 1, r = 0, qwq = 0, now = 0;
	rep(i, 1, q) {
		if(pos[Q[i].l] == pos[Q[i].r]) {
			dsu2.init(Q[i].l, Q[i].r);
			ans[Q[i].id] = Q[i].r - Q[i].l + 1;
			rep(u, Q[i].l, Q[i].r) {
				for(auto v : e[u]) {
					if(Q[i].l <= v && v <= Q[i].r) {
						ans[Q[i].id] -= dsu2.merge(u, v, 0);
					}
				}
			}
			continue;
		}
		if(pos[Q[i].l] != qwq) {
			dsu1.init(1, n);
			qwq = pos[Q[i].l];
			l = R[qwq] + 1;
			r = R[qwq];
			now = 0;
		}
//		printf("L=%d R=%d Q=[%d, %d]\n", l, r, Q[i].l, Q[i].r);
		while(r < Q[i].r) {
			++r;
			int u = r;
			for(auto v : e[u]) {
				if(v < u && v >= R[qwq]) {
//					printf("ADD (%d, %d) @ R\n", u, v);
					now += dsu1.merge(u, v, 0);
				}
			}
		}
		int sv = now;
		while(l > Q[i].l) {
			--l;
			int u = l;
			for(auto v : e[u]) {
				if(v > u && v <= r) {
//					printf("ADD (%d, %d) @ L\n", u, v);
					now += dsu1.merge(u, v, 1);
				}
			}
		}
		ans[Q[i].id] = Q[i].r - Q[i].l + 1 - now;
		now = sv;
		l = R[qwq] + 1;
		while(!dsu1.stk.empty()) dsu1.undo();
	}
	rep(i, 1, q) printf("%d\n", ans[i]);
	return 0;
}