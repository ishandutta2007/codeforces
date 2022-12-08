#include <bits/stdc++.h>

using namespace std;

int a[3000];

void solve() {
	int n;
	scanf("%d", &n);
	bool ok = true;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		if ((a[i] + i) & 1) ok = false;
	}
	if (!ok) {
		puts("-1");
		return;
	}
	vector<int> v;
//	for (int i = 1; i <= n; ++i) {
//		if (a[i] == n) {
//			v.push_back(i);
//			reverse(a + 1, a + i + 1);
//			v.push_back(n);
//			reverse(a + 1, a + n + 1);
//		}
//	}
	int p = n;
	while (p > 1) {
		int x, y;
		for (int i = 1; i <= p; ++i) {
			if (a[i] == p) x = i;
		}
		v.push_back(x);
		reverse(a + 1, a + x + 1);
		for (int i = 1; i <= p; ++i) {
			if (a[i] == p - 1) y = i;
		}
		v.push_back(y - 1);
		reverse(a + 1, a + y);
		v.push_back(y + 1);
		reverse(a + 1, a + y + 2);
		v.push_back(3);
		reverse(a + 1, a + 4);
		v.push_back(p);
		reverse(a + 1, a + p + 1);
		p -= 2;
	}
	printf("%d\n", v.size());
	for (int i : v) printf("%d ", i);
	putchar('\n');
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