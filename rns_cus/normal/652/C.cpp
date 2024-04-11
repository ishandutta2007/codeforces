#include <bits/stdc++.h>
using namespace std;
#define N 300300

int n, m, p[N], pos[N], a, b, nxt[N];

int main() {
//	freopen("c.in", "r", stdin);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i ++) scanf("%d", &p[i]), pos[p[i]] = i;
	for (int i = 1; i <= n + 1; i ++) nxt[i] = n + 1;
	for (int i = 1; i <= m; i ++) {
		scanf("%d %d", &a, &b);
		a = pos[a], b = pos[b];
	//	if (a > b) continue;
		if (a > b) swap(a, b);
		nxt[a] = min(nxt[a], b);
	}
	for (int i = n; i >= 1; i --) nxt[i] = min(nxt[i], nxt[i+1]);
	long long ans = 0;
	for (int i = 1; i <= n; i ++) ans += nxt[i] - i;
	printf("%I64d\n", ans);
	return 0;
}