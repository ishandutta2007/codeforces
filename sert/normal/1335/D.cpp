#include <bits/stdc++.h>
using namespace std;

void solve() {
	vector<string> s(9);
	for (int i = 0; i < 9; i++) {
		cin >> s[i];
	}
	
	vector<int> a = {0, 3, 6, 1, 4, 7, 2, 5, 8};
	for (int i = 0; i < 9; i++) {
		if (s[i][a[i]] == '9') s[i][a[i]] = '1';
		else s[i][a[i]]++;
	}

	for (auto ss : s) cout << ss << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}