#include <bits/stdc++.h>
using namespace std;

#define N 1001001

int n, a[N], an, b[N], bn;
char s[N];

bool ok(int limit) {
	int last = 0;
	for (int i = 1; i <= an && last < bn; i ++) {
		if (b[last+1] < a[i]) {
			int d = a[i] - b[last+1];
			if (d > limit) return 0;
			int tmp1 = lower_bound(b + 1, b + bn + 1, b[last+1] + limit - d + 1) - b - 1;
			int tmp2 = lower_bound(b + 1, b + bn + 1, a[i] + (limit - d) / 2 + 1) - b - 1;
			last = max(tmp1, tmp2);
		}
		else last = lower_bound(b + 1, b + bn + 1, a[i] + limit + 1) - b - 1;
	}
	return last == bn;
}

int main() {
//	freopen("e.in", "r", stdin);
	scanf("%d %s", &n, s + 1);
	for (int i = 1; i <= n; i ++) {
		if (s[i] == 'P') a[++an] = i;
		else if (s[i] == '*') b[++bn] = i;
	}
	int st = 0, en = 2 * n;
	while (en - st > 1) {
		int mid = st + en >> 1;
		if (ok(mid)) en = mid;
		else st = mid;
	}
	printf("%d\n", en);
	return 0;
}