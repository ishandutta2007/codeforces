#include <bits/stdc++.h>

using namespace std;

vector<int> a;

void solve() {
	int n;
	cin >> n;
	cout << lower_bound(a.begin(), a.end(), n) - a.begin() << "\n";
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	a = {0, 0, 2, 6};
	int p = 1;
	while (a.back() <= 1e9) {
		a.push_back(a.back() + 2 * (p + p));
		a.push_back(a.back() + 2 * (p + p + 1));
		a.push_back(a.back() + 2 * (p + p + 2));
		++p;
	}
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}