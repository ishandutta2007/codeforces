#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 4e5 + 5, N1 = N * 2, S = N1 * 20, P = 1073741824;
int n, q, p[N], nx[N1], ny[N1], lft[N1], rht[N1], root;
struct Node {
	int lc, rc, sze;
	long long S1, S2;
} t[S];
int T[N], tot;

namespace Tree1 {
	struct Edge { int v, nxt, w; } edge[N1];
	int head[N1], tot = 1;
	int mid, vis[N1], sze[N1], mx[N1], node;

	void addedge(int u, int v, int w) { edge[++tot] = (Edge){ v, head[u], w }, head[u] = tot; }
	void insedge(int u, int v, int w) { addedge(u, v, w), addedge(v, u, w); }
	
	void GetMid(int u, int fa) {
		sze[u] = 1;
		for(int i = head[u]; i; i = edge[i].nxt) {
			int v = edge[i].v;
			if(v == fa || vis[i]) continue;
			GetMid(v, u), sze[u] += sze[v], mx[i] = max(sze[v], node - sze[v]);
			if(mx[i] < mx[mid]) mid = i;
		}
	}

	void solve(int x) {
		if(!x) return;
		vis[x] = vis[x ^ 1] = 1;
		int u = nx[x] = edge[x].v, v = ny[x] = edge[x ^ 1].v;
		mid = 0, node = sze[u], GetMid(u, v), lft[x] = mid, solve(mid);
		mid = 0, node = sze[v], GetMid(v, u), rht[x] = mid, solve(mid);
	}
}

namespace LCA {
	struct Edge { int v, nxt, w; } edge[N1];
	int head[N1], tot = 1, node, dep[N1];
    int f[N1], sze[N1], son[N1], top[N1];
    /*
    struct Node {
        int u, dep;
        Node(int a = 0, int b = 0) { u = a, dep = b; }
        bool operator <(Node b) const { return dep < b.dep; }
    } f[N1][21];
    */
	long long dis[N1];

	void addedge(int u, int v, int w) { edge[++tot] = (Edge){ v, head[u], w }, head[u] = tot; }
	void insedge(int u, int v, int w) { Tree1::insedge(u, v, w), addedge(u, v, w), addedge(v, u, w); }

    #define v edge[i].v
	void dfs(int u, int fa, long long len) {
        dep[u] = dep[fa] + 1, dis[u] = len, sze[u] = 1, f[u] = fa;
		for(int i = head[u]; i; i = edge[i].nxt)
            if(v != fa) dfs(v, u, len + edge[i].w), sze[u] += sze[v], son[u] = sze[v] > sze[son[u]]? v : son[u];
	}
    
    void df5(int u, int fa) {
        top[u] = fa;
        if(son[u]) df5(son[u], fa);
        for(int i = head[u]; i; i = edge[i].nxt) if(!top[v]) df5(v, v);
    }
    #undef v

	int lca(int x, int y) {
        while(top[x] != top[y]) dep[top[x]] > dep[top[y]]? x = f[top[x]] : y = f[top[y]];
        return dep[x] < dep[y]? x : y;
	}

	long long dist(int x, int y) { return dis[x] + dis[y] - 2 * dis[lca(x, y)]; }
	int len(int x, int y) { return dep[x] + dep[y] - 2 * dep[lca(x, y)]; }
}

namespace Tree0 {
	struct Edge { int v, nxt, w; } edge[N << 1];
	int head[N], tot, node;

	void addedge(int u, int v, int w) { edge[++tot] = (Edge){ v, head[u], w }, head[u] = tot; }
	void insedge(int u, int v, int w) { addedge(u, v, w), addedge(v, u, w); }

	void build(int u, int fa) {
		int lst = u;
		for(int i = head[u]; i; i = edge[i].nxt) {
			int v = edge[i].v, w = edge[i].w;
			if(v == fa) continue;
			LCA::insedge(lst, ++node, 0), LCA::insedge(node, v, w), lst = node;
			build(v, u);
		}
	}
}

int insert(int pre, int u, int x) {
	int rt = ++tot;
	t[rt] = t[pre], t[rt].sze++;
	if(!u) return rt;
	int lenl = LCA::len(x, nx[u]), lenr = LCA::len(x, ny[u]);
	if(lenl < lenr) {
		t[rt].lc = insert(t[pre].lc, lft[u], x);
		t[rt].S1 += LCA::dist(x, nx[u]), t[t[rt].lc].S2 += LCA::dist(x, nx[u]);
	}
	else {
		t[rt].rc = insert(t[pre].rc, rht[u], x);
		t[rt].S1 += LCA::dist(x, ny[u]), t[t[rt].rc].S2 += LCA::dist(x, ny[u]);
	}
	return rt;
}

long long query(int p, int u, int x) {
	if(!p || !u) return 0;
	if(LCA::len(x, nx[u]) < LCA::len(x, ny[u]))
		return query(t[p].lc, lft[u], x) + LCA::dist(x, ny[u]) * (t[p].sze - t[t[p].lc].sze) + t[p].S1 - t[t[p].lc].S2;
	else
		return query(t[p].rc, rht[u], x) + LCA::dist(x, nx[u]) * (t[p].sze - t[t[p].rc].sze) + t[p].S1 - t[t[p].rc].S2;
}

long long ask(int l, int r, int x) {
	long long ans = query(T[r], root, x) - query(T[l - 1], root, x);
	return ans;
}

void update(int x) {
	swap(p[x], p[x + 1]);
	T[x] = insert(T[x - 1], root, p[x]), T[x + 1] = insert(T[x], root, p[x + 1]);
}

int decode(int x, long long lst) {
	return (lst % P) ^ x;
}

int main() {
	n = get(), q = get();
	for(int i = 1; i <= n; i++) p[i] = get();
	for(int i = 1, u, v, w; i < n; i++) u = get(), v = get(), w = get(), Tree0::insedge(u, v, w);
	Tree0::node = n, Tree0::build(1, 0), LCA::dfs(1, 0, 0), LCA::df5(1, 1);
	Tree1::node = Tree1::mx[0] = Tree0::node, Tree1::GetMid(1, 0), root = Tree1::mid, Tree1::solve(Tree1::mid);
	for(int i = 1; i <= n; i++) T[i] = insert(T[i - 1], root, p[i]);
	long long lst = 0;
	for(int i = 1; i <= q; i++) {
		int t = get(), l, r, x;
		if(t == 1) l = decode(get(), lst), r = decode(get(), lst), x = decode(get(), lst), lst = ask(l, r, x), printf("%lld\n", lst);
		else update(decode(get(), lst));
	}
	return 0;
}