#include <bits/stdc++.h>
#define REV(x) ((x) == '0' ? '1' : '0')
using namespace std;

char a[200010], b[200010], c[200010], ans[300010];
int cnt[300010], ccc[300010];

void SWP(char *a, char *b, int n) {
	for (int i = 0; i < n + n; i++) swap(a[i], b[i]);
}

void Check(char *ans, int n, char *a, int m) {
	int cur = 0;
	for (int i = 0; i < n; i++) {
		if (cur < m && ans[i] == a[cur]) cur++;
	}
	assert(cur == m);
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d%s%s%s", &n, a, b, c);
		int ca = 0, cb = 0, cc = 0;
		for (int i = 0; i < n + n; i++) ca += a[i] == '1', cb += b[i] == '1', cc += c[i] == '1';
		if (ca > cb) swap(ca, cb), SWP(a, b, n);
		if (cb > cc) swap(cb, cc), SWP(b, c, n);
		if (ca > cb) swap(ca, cb), SWP(a, b, n);
		int flag = 0;
		if (cb <= n) {
			flag = 1;
			ca = n + n - ca, cb = n + n - cb, cc = n + n - cc;
			for (int i = 0; i < n + n; i++) a[i] = REV(a[i]), b[i] = REV(b[i]), c[i] = REV(c[i]);
			swap(ca, cc), SWP(a, c, n);
		}
		for (int i = 0; i < n + n + n; i++) cnt[i] = ccc[i] = 0;
		int cur = 0;
		for (int i = 0; i < n + n; i++) {
			if (b[i] == '0') cnt[cur]++;
			else cur++;
		}
		int N = cur;
		cur = 0;
		for (int i = 0; i < n + n; i++) {
			if (c[i] == '0') ccc[cur]++;
			else cur++;
		}
		N = max(N, cur);
		int tp = 0;
		for (int i = 0; i < N; i++) {
			int tmp = max(cnt[i], ccc[i]);
			while (tmp--) ans[tp++] = '0';
			ans[tp++] = '1';
		}
		while (tp < n + n + n) ans[tp++] = '0';
		Check(ans, n + n + n, b, n + n), Check(ans, n + n + n, c, n + n);
		if (flag) {
			for (int i = 0; i < n + n + n; i++) ans[i] = REV(ans[i]);
		}
		ans[n + n + n] = '\0';
		printf("%s\n", ans);
	}
	return 0;
}