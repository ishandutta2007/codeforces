#include <bits/stdc++.h>

using namespace std;

int a[1000], b[1000];

void solve() {
	int k, n, m;
	scanf("%d%d%d", &k, &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < m; ++i) {
		scanf("%d", &b[i]);
	}
	int i = 0, j = 0;
	vector<int> v;
	while (i != n || j != m) {
		if (i < n && a[i] <= k) {
			v.push_back(a[i]);
			if (!a[i])++k;
			++i;
		} else if (j < m && b[j] <= k) {
			v.push_back(b[j]);
			if (!b[j])++k;
			++j;
		} else {
			printf("-1\n");
			return;
		}
	}
	for (auto &p:v)printf("%d ", p);
	printf("\n");
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