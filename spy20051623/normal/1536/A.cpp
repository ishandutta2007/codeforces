#include <bits/stdc++.h>

using namespace std;

int a[500];

void solve() {
	int n;
	scanf("%d", &n);
	bool ok = true;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		if (a[i] < 0)
			ok = false;
	}
	if (n == 1) {
		printf("YES\n");
		printf("1\n");
		printf("%d\n", a[0]);
		return;
	}
	if (!ok) {
		printf("NO\n");
		return;
	}
	set<int> s;
	for (int i = 0; i < n; ++i) {
		s.insert(a[i]);
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == j)
				continue;
			if (s.find(abs(a[i] - a[j])) == s.end()) {
				a[n++] = abs(a[i] - a[j]);
				s.insert(abs(a[i] - a[j]));
			}
			if (s.size() > 300) {
				printf("NO\n");
				return;
			}
		}
	}
	printf("YES\n");
	printf("%d\n", n);
	for (int i = 0; i < n; ++i) {
		printf("%d ", a[i]);
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