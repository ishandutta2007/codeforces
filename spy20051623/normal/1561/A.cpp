#include <bits/stdc++.h>

using namespace std;

int a[1005];

void f(int x) {
	if (a[x] > a[x + 1]) swap(a[x], a[x + 1]);
}

bool check(int n) {
	for (int i = 1; i < n; ++i) {
		if (a[i] > a[i + 1]) return false;
	}
	return true;
}

void solve() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	int cnt = 0;
	while (!check(n)) {
		++cnt;
		for (int i = cnt & 1 ? 1 : 2; i < n; i += 2) {
			f(i);
		}
	}
	printf("%d\n", cnt);
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