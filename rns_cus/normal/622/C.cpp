#include <bits/stdc++.h>
using namespace std;

int n, q, a[1001001], nxt[1001001], l, r, x;

int main() {
//	freopen("c.in", "r", stdin);
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	for (int i = n; i >= 1; i --) {
		if (a[i] != a[i+1]) nxt[i] = i + 1;
		else nxt[i] = nxt[i+1];
	}
	while (q --) {
		scanf("%d %d %d", &l, &r, &x);
		if (a[l] != x) {
			printf("%d\n", l);
		}
		else {
			if (nxt[l] <= r) printf("%d\n", nxt[l]);
			else printf("%d\n", -1);
		}
	}
	return 0;
}