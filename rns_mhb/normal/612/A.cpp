#include <bits/stdc++.h>
using namespace std;

#define N 111

char s[N];
int n, a, b;

int main() {
	scanf("%d %d %d %s", &n, &a, &b, s);
	bool had = 0;
	for (int k = 0; k <= n; k += a) if ((n - k) % b == 0) {
		printf("%d\n", (k / a) + ((n - k) / b));
		for (int i = 0; i < k - 1; i += a) {
			for (int j = i; j < i + a; j ++) printf("%c", s[j]);
			puts("");
		}
		for (int i = k; i < n; i += b) {
			for (int j = i; j < i + b; j ++) printf("%c", s[j]);
			puts("");
		}
		had = 1;
		break;
	}
	if (!had) puts("-1");

	return 0;
}