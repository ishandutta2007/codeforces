#include <cstdio>
#include <algorithm>

using namespace std;

int rd() {
	int x = 0; char c = getchar();
	while (c > '9' || c < '0') c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x;
}

const int N = 2e5 + 10;

struct edge {
	int nxt, to;
}e[N];
int head[N], dep[N], a[N], app[20000000];
int n, sum, mxdep, cnt, tot, tot2;
long long ans;
bool ina[N];

void add_edge(int u, int v) {
	e[++cnt].nxt = head[u], e[head[u] = cnt].to = v;
}

void dfs(int u) {
	for (int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].to;
		dep[v] = dep[u] + 1;
		dfs(v);
	}
}

int main() {
//	freopen("1.in", "r", stdin);
	n = rd();
	for (int i = 1; i <= n; i ++) a[i] = rd();
	for (int i = 2; i <= n; i ++) {
		int p = rd();
		add_edge(p, i);
	}
	dfs(1);
	for (int i = 1; i <= n; i ++) mxdep = max(mxdep, dep[i]);
	for (int i = 1; i <= n; i ++) if ((dep[i] & 1) == (mxdep & 1)) ina[i] = 1;
	for (int i = 1; i <= n; i ++) if (ina[i]) sum ^= a[i], tot ++; else app[a[i]]++, tot2 ++;
	if (!sum) ans += 1ll * tot * (tot - 1) / 2 + 1ll * tot2 * (tot2 - 1) / 2;
	for (int i = 1; i <= n; i ++) {
		if (!ina[i]) continue;
		int t = sum ^ a[i] ^ 0;
//		printf("%d\n", t);
		ans += app[t];
	}
	printf("%I64d\n", ans);
	return 0;
}