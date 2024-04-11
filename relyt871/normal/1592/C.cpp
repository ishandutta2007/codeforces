#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const int MAXN = 100005;

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

int n, k, a[MAXN];
vector<int> tree[MAXN];

void DFS1(int u, int fa) {
	for (auto v : tree[u]) {
		if (v == fa) continue;
		DFS1(v, u);
		a[u] ^= a[v];
	}
}

bool DFS2(int u, int fa, int anc) {
	if (u != 1 && anc && a[u] == a[1]) {
		return 1;
	}
	for (auto v : tree[u]) {
		if (v == fa) continue;
		if (DFS2(v, u, anc | (a[u] == 0))) {
			return 1;
		}
	}
	return 0;
}

void solve() {
	read(n); read(k);
	int allxor = 0;
	for (int i = 1; i <= n; ++i) {
		tree[i].clear();
		read(a[i]);
		allxor ^= a[i];
	}
	for (int i = 1, u, v; i < n; ++i) {
		read(u); read(v);
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	if (allxor == 0) {
		puts("YES");
		return;
	}
	if (k == 2) {
		puts("NO");
		return;
	}
	DFS1(1, 0);
	int same = 0;
	for (int i = 2; i <= n; ++i) {
		same += (a[1] == a[i]);
	}
	if (same >= 2) {
		puts("YES");
		return;
	}
	if (DFS2(1, 0, 0)) {
		puts("YES");
	} else {
		puts("NO");
	}
}

int main() {
	int T; read(T);
	while (T--) {
		solve();
	}
	return 0;
}