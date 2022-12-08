#include <bits/stdc++.h>

using namespace std;

void solve() {
	string s;
	cin >> s;
	int x[2] = {0, 0};
	for (char c: s) ++x[c - '0'];
	cout << min(x[0], x[1]) - (x[0] == x[1]) << '\n';
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