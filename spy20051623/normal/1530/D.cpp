#include <bits/stdc++.h>

using namespace std;

int a[200005], b[200005], v[200005], g[200005];

void solve() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		b[i] = v[i] = g[i] = 0;
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		g[a[i]] = 1;
	}
	int k = 0;
	vector<int> t;
	for (int i = 1; i <= n; ++i) {
		if (!g[i])t.push_back(i);
	}
	for (int i:t) {
		if (!v[a[i]]) {
			b[i] = a[i];
			v[a[i]] = 1;
			++k;
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (!v[a[i]]) {
			b[i] = a[i];
			v[a[i]] = 1;
			++k;
		}
	}
	vector<int> h;
	t.clear();
	for (int i = 1; i <= n; ++i) {
		if (!b[i] && !v[i]) {
			h.push_back(i);
			t.push_back(i);
			v[i] = 1;
			b[i] = -1;
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (!v[i])t.push_back(i);
		if (!b[i])h.push_back(i);
	}
	for (int i = 0; i < h.size(); ++i) {
		b[h[i]] = t[(i + 1) % h.size()];
		v[h[(i + 1) % t.size()]] = 1;
	}
	printf("%d\n", k);
	for (int i = 1; i <= n; ++i) {
		printf("%d ", b[i]);
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