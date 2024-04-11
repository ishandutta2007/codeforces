#include <bits/stdc++.h>

using namespace std;

int a[200005];
char s[200005];

void solve() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	scanf("%s", s);
	vector<int> u, v;
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'B') u.push_back(a[i]);
		else v.push_back(a[i]);
	}
	sort(u.begin(), u.end());
	sort(v.begin(), v.end(), greater<int>());
	for (int i = 0; i < u.size(); ++i) {
		if (u[i] < i + 1) {
			puts("NO");
			return;
		}
	}
	for (int i = 0; i < v.size(); ++i) {
		if (v[i] > n - i) {
			puts("NO");
			return;
		}
	}
	puts("YES");
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}