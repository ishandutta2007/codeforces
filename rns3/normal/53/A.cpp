#include <bits/stdc++.h>
using namespace std;

string s, t, ans;

int main() {
	cin >> t;
	int n, sz = t.size(), vis = 1;
	ans = t;
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		cin >> s;
		int tag = 1;
		for (int i = 0; i < sz && tag; i ++) if (s[i] != t[i]) tag = 0;
		if (tag && vis) {
			ans = s;
			vis = 0;
		}
		if (tag && !vis) {
			ans = min(ans, s);
		}
	}
	cout << ans;
	return 0;
}