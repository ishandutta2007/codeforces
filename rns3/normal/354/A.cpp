#include <bits/stdc++.h>
using namespace std;

#define N 100010


const int INF = 1e9 * 2;
int n, w[N], le, ri, ql, qr, s[N];

int main() {
	scanf("%d %d %d %d %d", &n, &le, &ri, &ql, &qr);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &w[i]);
		s[i] = s[i-1] + w[i];
	}
    int ans = INF, now;
    for (int i = 0; i <= n; i ++) {
		now = s[i] * le + (s[n] - s[i]) * ri;
		int k = abs(n - 2 * i);
		k = max(0, k - 1);
        if (i * 2 > n) now += k * ql;
        else now += k * qr;
        ans = min(ans, now);
    }
    printf("%d\n", ans);
	return 0;
}