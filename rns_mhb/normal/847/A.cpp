#include <bits/stdc++.h>
using namespace std;

#define N 10101

int n, a[N], le[N], ri[N];

int main() {
	//freopen("r.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d %d", &le[i], &ri[i]);
	int cnt = 0;
	for (int i = 1; i <= n; i ++) if (!le[i]) {
		int now = i;
		while (now) {
			a[++cnt] = now;
			now = ri[now];
		}
	}
	//for (int i = 1; i <= n; i ++) printf("%d ", a[i]);puts("");
	memset(le, 0, sizeof le);
	memset(ri, 0, sizeof ri);
	for (int i = 1; i < n; i ++) ri[a[i]] = a[i+1], le[a[i+1]] = a[i];
	for (int i = 1; i <= n; i ++) printf("%d %d\n", le[i], ri[i]);

	return 0;
}