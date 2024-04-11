#include <bits/stdc++.h>

using namespace std;

int a[100];

void solve() {
	string s, t;
	cin >> s >> t;
	memset(a, 0, sizeof a);
	for (char i: s) {
		++a[i - 'a'];
	}
	if (!a[0] || !a[1] || !a[2]) {
		for (int i = 0; i < a[0]; ++i) {
			cout << 'a';
		}
		for (int i = 0; i < a[1]; ++i) {
			cout << 'b';
		}
		for (int i = 0; i < a[2]; ++i) {
			cout << 'c';
		}
	} else {
		for (int i = 0; i < a[0]; ++i) {
			cout << 'a';
		}
		if (t == "abc") {
			for (int i = 0; i < a[2]; ++i) {
				cout << 'c';
			}
			for (int i = 0; i < a[1]; ++i) {
				cout << 'b';
			}
		} else {
			for (int i = 0; i < a[1]; ++i) {
				cout << 'b';
			}
			for (int i = 0; i < a[2]; ++i) {
				cout << 'c';
			}
		}
	}
	for (int i = 3; i < 26; ++i) {
		for (int j = 0; j < a[i]; ++j) {
			cout << char('a' + i);
		}
	}
	cout << '\n';
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