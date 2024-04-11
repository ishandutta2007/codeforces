#include <bits/stdc++.h>

using namespace std;

char s[10000];

void solve() {
	int n;
	scanf("%d", &n);
	scanf("%s", s);
	bool ok = true;
	for (int i = 1; i < n; ++i) {
		if (s[i] < s[i - 1]) {
			ok = false;
			break;
		}
	}
	if (ok) {
		puts("0");
		return;
	}
	vector<int> v, u;
	int l = 0, r = n - 1;
	while (l < r) {
		while (l < n && s[l] == '0') ++l;
		while (r >= 0 && s[r] == '1') --r;
		if (l >= r) break;
		v.push_back(l), u.push_back(r);
		++l, --r;
	}
	puts("1");
	printf("%d ", v.size() * 2);
	for (int i: v) printf("%d ", i + 1);
	for (int i = u.size() - 1; i >= 0; --i) printf("%d ", u[i] + 1);
	puts("");
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