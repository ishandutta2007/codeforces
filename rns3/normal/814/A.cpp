#include <bits/stdc++.h>
using namespace std;

#define N 202

int n, a[N], b[N], k;

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	for (int i = 1; i <= k; i ++) scanf("%d", &b[i]);
	if (k >= 2) {
		puts("Yes");
		return 0;
	}
	for (int i = 1; i <= n; i ++) {
		if (a[i] == 0) a[i] = b[1];
	}
	bool tag = 1;
	for (int i = 1; i < n; i ++) if (a[i] >= a[i+1]) {
		tag = 0;
		break;
	}
	if (tag) puts("No");
	else puts("Yes");
	return 0;
}