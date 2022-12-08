#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int p = 0, c = 0;
	while (p < n - 1) {
		if (s[p] == '(') {
			++c;
			p += 2;
		} else {
			int q = -1;
			for (int i = p + 1; i < n; ++i) {
				if (s[i] == ')') {
					q = i;
					break;
				}
			}
			if (q == -1) break;
			++c;
			p = q + 1;
		}
	}
	cout << c << ' ' << n - p << '\n';
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