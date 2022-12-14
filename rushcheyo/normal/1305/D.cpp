#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 200005;
const int P = 998244353;
const int inf = 0x3f3f3f3f;

int power(int a, ll x) {
	int ans = 1;
	for (; x; x >>= 1, a = 1ll * a * a % P)
		if (x & 1) ans = 1ll * ans * a % P;
	return ans;
}
int gcd(int a, int b) {
	return !b ? a : gcd(b, a % b);
}

int n, a[N], b[N], fa[N], size[N], deg[N];
bool del[N];
vector<int> g[N];

void dfs(int u) {
	size[u] = 1;
	for (int v : g[u])
		if (!del[v] && v != fa[u]) {
			fa[v] = u, dfs(v);
			size[u] += size[v];
		}
}

int main() {
	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		cin >> a[i] >> b[i];
		g[a[i]].push_back(b[i]), g[b[i]].push_back(a[i]);
	}
	for (int i = 1; i <= n; ++i) deg[i] = (int)g[i].size();
	int left = n;
	while (left > 1) {
		if (left > 2) {
			int rt;
			for (int i = 1; i <= n; ++i) if (!del[i] && deg[i] > 1) rt = i;
			fa[rt] = 0, dfs(rt);
		}
		int a = -1, b = -1;
		for (int i = 1; i <= n; ++i)
			if (deg[i] == 1 && !del[i]) {
				if (a == -1) a = i;
				else b = i;
			}
		printf("? %d %d\n", a, b);
		fflush(stdout);
		int x;
		scanf("%d", &x);
		if (x == a || x == b) {
			printf("! %d\n", x), fflush(stdout);
			return 0;
		}
		del[a] = del[b] = true;
		--deg[fa[a]], --deg[fa[b]];
		left -= 2;
	}
	int rt;
	for (int i = 1; i <= n; ++i) if (!del[i]) rt = i;
	printf("! %d\n", rt);
	fflush(stdout);
}