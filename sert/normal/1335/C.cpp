#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> num(n + 1, 0);
	while (n--) {
		int x;
		cin >> x;
		num[x]++;
	}

	int mx = 0, uniq = 0;
	for (int i = 0; i < (int)num.size(); i++) {
		if (num[i] > 0) uniq++;
		mx = max(mx, num[i]);
	}

	cout << min(mx, uniq) - (mx == uniq ? 1 : 0) << "\n";
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