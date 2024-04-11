#include <bits/stdc++.h>
using namespace std;

char s[100010];
int sum[100010];

int main() {
	int n, q; scanf("%d%d", &n, &q);
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + s[i] - 'a' + 1;
	while (q--) {
		int l, r; scanf("%d%d", &l, &r);
		printf("%d\n", sum[r] - sum[l - 1]);
	}
	return 0;
}