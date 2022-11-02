#include <bits/stdc++.h>
using namespace std;

int n, p, q, a, b;
char s[100100];

int main() {
//	freopen("a.in", "r", stdin);
	scanf("%d %d %d", &n, &p, &q);
	scanf("%s", s);
	bool ok = 0;
	for (int i = 0; i <= n; i ++) {
		for (int j = 0; j <= n; j ++) {
			if (i * p + j * q == n) {
				a = i, b = j;
				ok = 1; break;
			}
		}
		if (ok) break;
	}
	if (ok) {
		printf("%d\n", a + b);
		for (int i = 0; i < a * p; i += p) {
			for (int j = i; j < i + p; j ++) printf("%c", s[j]);
			puts("");
		}
		for (int i = a * p; i < n; i += q) {
			for (int j = i; j < i + q; j ++) printf("%c", s[j]);
			puts("");
		}
	}
	else {
		puts("-1");
	}
	return 0;
}