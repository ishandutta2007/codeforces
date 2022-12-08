#include <bits/stdc++.h>

using namespace std;

int a[200005];
int c[200005];
int s[200005];

void solve() {
	memset(c, 0, sizeof c);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &s[i]);
		++c[s[i]];
	}
	int p = 0;
	int q = 0;
	for (int i = 1; i < n; ++i) {
		if (c[i] == 2)++p;
		else break;
	}
	for (int i = p + 1; i < n; ++i) {
		if (c[i] == 1)++q;
		else break;
	}
	for (int i = p + q + 1; i < n; ++i) {
		if (c[i]) {
			printf("0\n");
			return;
		}
	}
	if (!p) {
		printf("0\n");
		return;
	}
	int ok1 = 1, ok2 = 1;
	memset(a, 0, sizeof a);
	for (int i = 0; i < p; ++i) {
		++a[s[i]];
		if (a[s[i]] == 2 || s[i] > p) {
			ok1 = 0;
			break;
		}
	}
	memset(a, 0, sizeof a);
	for (int i = n - 1; i >= n - p; --i) {
		++a[s[i]];
		if (a[s[i]] == 2 || s[i] > p) {
			ok2 = 0;
			break;
		}
	}
	if (p + p == n && ok1 && ok2) {
		printf("1\n");
		printf("%d %d\n", p, p);
	} else {
		printf("%d\n", ok1 + ok2);
		if (ok1)printf("%d %d\n", p, n - p);
		if (ok2)printf("%d %d\n", n - p, p);
	}
}

int main() {
//	freopen("in.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}