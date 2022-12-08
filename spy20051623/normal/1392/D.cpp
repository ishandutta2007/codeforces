#include <bits/stdc++.h>

using namespace std;
int n;

int nxt(int x) {
	return x + 1 >= n ? 0 : x + 1;
}

int lst(int x) {
	return x - 1 < 0 ? n - 1 : x - 1;
}

void solve() {
	cin >> n;
	string s;
	cin >> s;
	int p = -1;
	for (int i = 0; i < n; ++i) {
		if (s[i] != s[nxt(i)]) {
			p = i + 1;
			break;
		}
	}
	if (p == -1) {
		cout << (n + 2) / 3 << '\n';
		return;
	}
	int ans = 0;
	for (int i = p; i != lst(p); i = nxt(i)) {
		if (s[i] == s[lst(i)] && s[i] == s[nxt(i)]) {
			int q = 0, r;
			for (int j = i; s[j] == s[lst(j)] && s[j] == s[nxt(j)]; j = nxt(j)) {
				++q;
				r = j;
			}
			ans += (q + 2) / 3;
			i = r;
		}
	}
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