#include <bits/stdc++.h>

using namespace std;

int a[200005];

void solve() {
	int n;
	scanf("%d", &n);
	vector<int> v;
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		cnt += a[i];
	}
	if (cnt & 1) {
		printf("NO\n");
		return;
	}
	for (int i = 1; i <= n - 2; ++i) {
		if (a[i]) {
			if (!a[i + 1]) {
				v.push_back(i);
				a[i] = a[i + 1] = a[i + 2] = a[i] ^ a[i + 1] ^ a[i + 2];
			}
			++i;
		}
	}
	for (int i = 1; i <= n - 2; ++i) {
		if (!a[i] && a[i + 1] && a[i + 2]) {
			v.push_back(i);
			a[i] = a[i + 1] = a[i + 2] = a[i] ^ a[i + 1] ^ a[i + 2];
		}
	}
	for (int i = n - 2; i >= 1; --i) {
		if (a[i] && a[i + 1] && !a[i + 2]) {
			v.push_back(i);
			a[i] = a[i + 1] = a[i + 2] = a[i] ^ a[i + 1] ^ a[i + 2];
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (a[i]) {
			printf("NO\n");
			return;
		}
	}
	printf("YES\n");
	printf("%d\n", v.size());
	if (!v.empty()) {
		for (int i: v) printf("%d ", i);
		printf("\n");
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