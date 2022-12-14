#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;

const int N = 100005;
int n, root;

struct node {
	int ch[2], size, rng;
	ll val, add;
} T[N];

void pushup(int u) {
	T[u].size = T[T[u].ch[0]].size + T[T[u].ch[1]].size + 1;
}
void push(int u, ll v) {
	if (!u) return;
	T[u].val += v, T[u].add += v;
}
void pushdown(int u) {
	if (T[u].add) {
		push(T[u].ch[0], T[u].add);
		push(T[u].ch[1], T[u].add);
		T[u].add = 0;
	}
}
int merge(int p, int q) {
	if (!p || !q) return p ^ q;
	if (T[p].rng < T[q].rng) {
		pushdown(p);
		T[p].ch[1] = merge(T[p].ch[1], q);
		pushup(p);
		return p;
	}
	pushdown(q);
	T[q].ch[0] = merge(p, T[q].ch[0]);
	pushup(q);
	return q;
}

void split(int p, int x, int rk, int &l, int &r) {
	if (!p) { l = r = 0; return; }
	pushdown(p);
	if ((rk + T[T[p].ch[0]].size + 1ll) * x >= T[p].val) r = p, split(T[p].ch[0], x, rk, l, T[p].ch[0]);
	else l = p, split(T[p].ch[1], x, rk + T[T[p].ch[0]].size + 1, T[p].ch[1], r);
	pushup(p);
}
ll ans, sum;
void dfs(int u) {
	if (!u) return;
	pushdown(u);
	dfs(T[u].ch[0]);
	ans = max(ans, sum += T[u].val);
	dfs(T[u].ch[1]);
}

int main() {
	scanf("%d", &n);
	for (int i = 1, x, t; i <= n; ++i) {
		scanf("%d", &x);
		split(root, x, 0, root, t);
		T[i].size = 1, T[i].val = (T[root].size + 1ll) * x, T[i].rng = rng();
		push(t, x);
		root = merge(merge(root, i), t);
	}
	dfs(root);
	printf("%lld\n", ans);
	return 0;
}