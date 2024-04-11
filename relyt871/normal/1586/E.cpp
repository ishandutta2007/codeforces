#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const int MAXN = 300005;

template <typename T> inline void read(T &WOW) {
	T x = 0, flag = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') flag = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	WOW = flag * x;
}

int n, m, q, ufs[MAXN], fa[MAXN], dep[MAXN];
int cov[MAXN], in[MAXN], vis[MAXN], additional;
vector<int> tree[MAXN], ans[MAXN];

int getf(int x) {
	return (ufs[x] == x)? x : ufs[x] = getf(ufs[x]);
}

void DFS(int u) {
	for (auto v : tree[u]) {
		if (v == fa[u]) continue;
		fa[v] = u;
		dep[v] = dep[u] + 1;
		DFS(v);
	}
}

inline bool needless(int u, int v) {
	if (fa[u] == v) swap(u, v);
	return !cov[v];
}

void DFS2(int u, int ff, int rt) {
	vis[u] = 1;
	int chd = 0;
	for (auto v : tree[u]) {
		if (v == ff || needless(u, v)) continue;
		DFS2(v, u, rt);
		++chd;
	}
	additional += chd / 2;
	if (u == rt) {
		additional += (chd & 1);
	}
}

void solve() {
	read(n); read(m);
	for (int i = 1; i <= n; ++i) {
		ufs[i] = i;
	}
	for (int i = 1, u, v; i <= m; ++i) {
		read(u); read(v);
		int x = getf(u), y = getf(v);
		if (x == y) continue;
		tree[u].push_back(v);
		tree[v].push_back(u);
		ufs[x] = y;
	}
	DFS(1);
	read(q);
	for (int i = 1, u, v; i <= q; ++i) {
		read(u); read(v);
		vector<int> tmp;
		while (u != v) {
			if (dep[u] >= dep[v]) {
				ans[i].push_back(u);
				cov[u] ^= 1;
				u = fa[u];
			} else {
				tmp.push_back(v);
				cov[v] ^= 1;
				v = fa[v];
			}
		}
		ans[i].push_back(u);
		while (tmp.size()) {
			ans[i].push_back(tmp.back());
			tmp.pop_back();
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (!vis[i]) {
			DFS2(i, 0, i);
		}
	}
	if (!additional) {
		puts("YES");
		for (int i = 1; i <= q; ++i) {
			printf("%d\n", ans[i].size());
			for (auto u : ans[i]) {
				printf("%d ", u);
			}
			printf("\n");
		}
	} else {
		puts("NO");
		printf("%d\n", additional);
	}
}

int main() {
	solve();
	return 0;
}