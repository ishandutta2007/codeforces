#include <bits/stdc++.h>

using namespace std;

void solve() {
	string s;
	cin >> s;
	int a[26];
	memset(a, 0, sizeof a);
	for (char c: s) {
		if (c >= 'a' && c <= 'z') a[c - 'a'] = 1;
		else if (!a[c - 'A']) {
			cout << "no\n";
			return;
		}
	}
	cout << "yes\n";
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