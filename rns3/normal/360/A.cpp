#include <bits/stdc++.h>
using namespace std;

#define N 5050

const int INF = 1e9;

int n, m, x[N], y[N], a[N], b[N], c[N], d[N], z[N];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i ++) x[i] = INF;
    for (int i = 1; i <= m; i ++) {
		scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
		if (a[i] == 1) {
			for (int j = b[i]; j <= c[i]; j ++) {
				y[j] += d[i];
			}
		}
		else {
            for (int j = b[i]; j <= c[i]; j ++) {
                x[j] = min(x[j], d[i] - y[j]);
            }
		}
    }
    for (int i = 1; i <= n; i ++) z[i] = x[i];
    bool ans = 1;
    for (int i = 1; i <= m && ans; i ++) {
		if (a[i] == 2) {
            ans = 0;
			for (int j = b[i]; j <= c[i] && !ans; j ++) {
				if (d[i] == x[j]) ans = 1;
			}
		}
		else {
			for (int j = b[i]; j <= c[i]; j ++) x[j] += d[i];
		}
    }
    if (ans) {
		puts("YES");
		for (int i = 1; i <= n; i ++) printf("%d ", z[i]);
    }
    else puts("NO");
	return 0;
}