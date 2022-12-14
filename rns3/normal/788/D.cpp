#include <bits/stdc++.h>
using namespace std;

#define N 20202
const int INF = 1e8;

int cnt;
int a[N];

int res;
int ask(int x, int y) {
	printf("0 %d %d\n", x, y);
	fflush(stdout);
	scanf("%d", &res);
	return res;
}

void solve(int L, int R) {
	if (L > R) return;
	int mid = (L + R) >> 1;
	int tmp = ask(mid, mid), tmpl = -1, tmpr = -1;
	if (tmp == 0) {
		a[++cnt] = mid;
		solve(L, mid - 1), solve(mid + 1, R);
		return;
	}
	int le = mid - tmp, ri = mid + tmp;
	if (le >= L) {
		tmpl = ask(le, le);
		if (tmpl == 0) {
			a[++cnt] = le;
			solve(L, le - 1), solve(le + 1, R);
			return;
		}
	}
	if (ri <= R) {
		tmpr = ask(ri, ri);
		if (tmpr == 0) {
			a[++cnt] = ri;
			solve(L, ri - 1), solve(ri + 1, R);
		}
	}
}

int x[N], y[N];

int main() {
	solve(-INF, INF);
	sort(a + 1, a + cnt + 1);
	int e = 0;
	for (int i = 1; i <= cnt; i ++) if (i == 1 || a[i] > a[i-1]) a[++e] = a[i];
	int em = -INF;
	int cur = 1;
	while (em == a[cur]) {
		em ++, cur ++;
	}
	int n = 0, m = 0;
	for (int i = 1, u, v; i <= e; i ++) {
		if (!ask(a[i], em)) x[++n] = a[i];
		if (!ask(em, a[i])) y[++m] = a[i];
	}
	printf("1 %d %d\n", n, m);
	for (int i = 1; i <= n; i ++) printf("%d ", x[i]);puts("");
	for (int i = 1; i <= m; i ++) printf("%d ", y[i]);puts("");
	fflush(stdout);


	return 0;
}