#include <bits/stdc++.h>

using namespace std;

int a[105], b[105];

void solve() {
	int n;
	scanf("%d", &n);
	int s1 = 0, s2 = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		s1 += a[i];
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &b[i]);
		s2 += b[i];
	}
	if (s1 != s2) {
		printf("-1\n");
		return;
	}
	vector<int> v, u;
	for (int i = 1; i <= n; ++i) {
		while (a[i] < b[i])v.push_back(i), ++a[i];
		while (b[i] < a[i])u.push_back(i), --a[i];
	}
	printf("%d\n", (int) v.size());
	for (int i = 0; i < v.size(); ++i) {
		printf("%d %d\n", u[i], v[i]);
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