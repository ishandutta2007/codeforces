#include <bits/stdc++.h>

using namespace std;

struct dt {
	int l, r, d;

	dt(int ll, int rr, int dd) {
		l = ll, r = rr, d = dd;
	}
};

int a[55], b[55];

void solve() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	vector<dt> v;
	for (int i = 1; i <= n; ++i) {
		int mn = i;
		for (int j = i + 1; j <= n; ++j) if (a[j] < a[mn]) mn = j;
		if (mn == i) continue;
		int d = mn - i;
		v.emplace_back(i, n, d);
		for (int j = i; j <= n; ++j) {
			if (j - d >= i) b[j - d] = a[j];
			else b[n + 1 + j - d - i] = a[j];
		}
		for (int j = i; j <= n; ++j) a[j] = b[j];
	}
	printf("%d\n", v.size());
	for (auto &i: v) printf("%d %d %d\n", i.l, i.r, i.d);
}

int main() {
//	freopen("in.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) solve();
	return 0;
}