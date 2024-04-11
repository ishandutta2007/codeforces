#include <bits/stdc++.h>
using namespace std;

int m;
long long n;
pair <int, int> p[22];

int main() {
//	freopen("b.in", "r", stdin);
	scanf("%I64d %d", &n, &m);
	for (int i = 0; i < m; i ++) scanf("%d %d", &p[i].second, &p[i].first);
	sort(p, p + m);
	long long ans = 0;
	for (int i = m - 1; i >= 0; i --) {
		if (n > p[i].second) ans += 1ll * p[i].first * p[i].second, n -= p[i].second;
		else {ans += 1ll * p[i].first * n; break;}
	}
	printf("%d\n", ans);
	return 0;
}