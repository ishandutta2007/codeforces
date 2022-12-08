#include <bits/stdc++.h>

using namespace std;

int a[10005];

int ask(int t, int i, int j, int x) {
	printf("? %d %d %d %d\n", t, i, j, x);
	fflush(stdout);
	int r;
	scanf("%d", &r);
	return r;
}

void ans(int n) {
	printf("!");
	for (int i = 1; i <= n; ++i) {
		printf(" %d", a[i]);
	}
	printf("\n");
	fflush(stdout);
}

void solve() {
	int n;
	scanf("%d", &n);
	memset(a, 0, sizeof a);
	int s = ask(1, 1, 2, n - 1);
	int t = ask(1, 2, 3, n - 1);
	int u = ask(1, 3, 1, n - 1);
	int v, w;
	if (s == n) {
		v = 2;
		w = n;
	} else if (t == n) {
		v = 3;
		w = n;
	} else if (u == n) {
		v = 1;
		w = n;
	} else if (s == t) {
		v = 2;
		w = s;
	} else if (t == u) {
		v = 3;
		w = t;
	} else {
		v = 1;
		w = u;
	}
	a[v] = w;
	if (w < n / 2) {
		for (int i = 1; i <= n; ++i) {
			if (i == v)
				continue;
			s = ask(1, v, i, n - 1);
			if (s == w) {
				t = ask(2, i, v, 1);
				a[i] = t;
			} else {
				a[i] = s;
			}
		}
	} else {
		for (int i = 1; i <= n; ++i) {
			if (i == v)
				continue;
			s = ask(2, i, v, 1);
			if (s == w) {
				t = ask(1, v, i, n - 1);
				a[i] = t;
			} else {
				a[i] = s;
			}
		}
	}
	ans(n);
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