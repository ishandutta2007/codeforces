#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int x = 1, y = 1;
	for (char c: s) {
		if (c == 'D') ++x;
		else ++y;
	}
	long long ans = 1ll * n * n;
	ans -= 1ll * x * y - s.length() - 1;
	int cnt = 0;
	for (char c: s) {
		if (c == s[0]) ++cnt;
		else break;
	}
	if (cnt == s.length()) ans = n;
	else if (s[0] == 'D') ans -= 1ll * cnt * (n - y);
	else ans -= 1ll * cnt * (n - x);
	cout << ans << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}