#include <bits/stdc++.h>

using namespace std;

int a[10005];
vector<int> k;

void solve() {
	k.clear();
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%1d", &a[i]);
		if (a[i])
			k.push_back(i);
	}
	for (int i = 0; i < k.size(); ++i) {
		int l, r;
		if (i == 0) {
			l = min(m, k[i]);
		} else {
			l = min(m, (k[i] - k[i - 1] - 1) / 2);
		}
		for (int j = 0; j <= l; ++j) {
			a[k[i] - j] = 1;
		}
		if (i == k.size() - 1) {
			r = min(m, n - 1 - k[i]);
		} else {
			r = min(m, (k[i + 1] - k[i] - 1) / 2);
		}
		for (int j = 0; j <= r; ++j) {
			a[k[i] + j] = 1;
		}
	}
	for (int i = 0; i < n; ++i) {
		printf("%d", a[i]);
	}
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