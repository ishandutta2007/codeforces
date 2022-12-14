#include <bits/stdc++.h>
using namespace std;

#define N 1001001

int n, a[N], an, b[N], bn, f[N];
char s[N];

bool ok(int limit) {
	memset(f, 0, sizeof f);
	for (int i = 1; i <= an; i ++) {
		int last = f[i-1];
		if (b[last+1] < a[i]) {
			int d = a[i] - b[last+1];
			if (d > limit && f[i] <= last) return 0;
			f[i] = max(f[i], lower_bound(b + 1, b + bn + 1, a[i]) - b - 1);
			if (i < an && a[i+1] <= b[last+1] + limit) {
				f[i+1] = max(f[i+1], lower_bound(b + 1, b + bn + 1, a[i] + limit + 1) - b - 1);
			}
		}
		else f[i] = max(f[i], lower_bound(b + 1, b + bn + 1, a[i] + limit + 1) - b - 1);
		if (f[i] >= bn) return 1;
	}
	return f[an] >= bn;
}

int main() {
//	freopen("d.in", "r", stdin);
	scanf("%d %s", &n, s + 1);
	for (int i = 1; i <= n; i ++) {
		if (s[i] == 'P') a[++an] = i;
		else if (s[i] == '*') b[++bn] = i;
	}
	if (an == 1) {
		int x = a[1];
		int cntl = 0, dl, cntr = 0, dr;
		for (int i = x - 1; i >= 1; i --) if (s[i] == '*') cntl ++, dl = x - i;
		for (int i = x + 1; i <= n; i ++) if (s[i] == '*') cntr ++, dr = i - x;
		if (cntl > cntr) printf("%d %d\n", cntl, dl);
		else if (cntl < cntr) printf("%d %d\n", cntr, dr);
		else printf("%d %d\n", cntl, min(dl, dr));
		return 0;
	}
	int st = 0, en = n;
	while (en - st > 1) {
		int mid = st + en >> 1;
		if (ok(mid)) en = mid;
		else st = mid;
	}
	printf("%d %d\n", bn, en);
	return 0;
}