#include <bits/stdc++.h>
using namespace std;

#define N 100010

typedef long long LL;

LL a[N], q;
int type[N], x[N], c[N], le[N], m, n;

int solve(LL q) {
    int i = lower_bound(a, a + m + 1, q) - a;
    if (type[i] == 1) return x[i];
    else return solve((q - a[i-1] + le[i] - 1) % le[i] + 1);
}

int main() {
	scanf("%d", &m);
	for (int i = 1; i <= m; i ++) {
		scanf("%d", &type[i]);
		if (type[i] == 1) {
			scanf("%d", &x[i]);
			a[i] = a[i-1] + 1;
		}
		else {
			scanf("%d %d", &le[i], &c[i]);
			a[i] = a[i-1] + 1ll * le[i] * c[i];
		}
	}
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
		scanf("%I64d", &q);
		printf("%d ", solve(q));
    }
	return 0;
}