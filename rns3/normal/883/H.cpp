#include <bits/stdc++.h>
using namespace std;

#define N 1001001

int n, cnt[256];
char s[N], prt[N], mid[N];

void solve(int k) {
	if (n % k) return;
	int m = n / k;
	int odd = 0;
	for (int i = 0; i < 256; i ++) if (cnt[i] & 1) odd ++;
	if (!odd) {
		if (m & 1) return;
		printf("%d\n", k);
		for (int i = 0, len = 0; i < 256; i ++) {
			while (cnt[i]) {
				prt[len++] = i;
				cnt[i] -= 2;
				if (len * 2 == m) {
					for (int j = 0; j < len; j ++) putchar(prt[j]);
					for (int j = len - 1; j >= 0; j --) putchar(prt[j]);
					putchar(' ');
					len = 0;
				}
			}
		}
		exit(0);
	}
	if (m % 2 == 0) return;
	if (odd > k) return;
	if ((k - odd) & 1) return;
	int runs = 0;
	for (int i = 0; i < 256; i ++) if (cnt[i] & 1) mid[++runs] = i, cnt[i] --;
	while (runs < k) {
		for (int i = 0; i < 256; i ++) if (cnt[i]) {
			mid[++runs] = i, mid[++runs] = i, cnt[i] -= 2;
			break;
		}
	}
	printf("%d\n", k);
	if (m == 1) {
		for (int i = 1; i <= runs; i ++) putchar(mid[i]), putchar(' ');
		exit(0);
	}
	for (int i = 0, len = 0; i < 256; i ++) {
		while (cnt[i]) {
			prt[len++] = i;
			cnt[i] -= 2;
			if (len == m / 2) {
				for (int j = 0; j < len; j ++) putchar(prt[j]);
				putchar(mid[runs--]);
				for (int j = len - 1; j >= 0; j --) putchar(prt[j]);
				putchar(' ');
				len = 0;
			}
		}
	}
	exit(0);
}

int main() {
//	freopen("h.in", "r", stdin);
	scanf("%d %s", &n, s);
	for (int i = 0; i < n; i ++) cnt[s[i]] ++;
	for (int i = 1; i <= n; i ++) solve(i);
	return 0;
}