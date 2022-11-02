#include <bits/stdc++.h>

using namespace std;
#define int long long

int sq(int a) {
	return a * a;
}

int per(int a, int b) {
	return (a + b) * 2;
}

int sq(int a, int b) {
	return a * b;
}

void solve() {
	int n;
	cin >> n;
	map <int, int> a;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a[x]++;
	}
	vector <int> help;
	for (auto i : a) {
		if (i.second >= 2) {
			help.push_back(i.first);
		} 
		if (i.second >= 4) {
			help.push_back(i.first);
		}
	}
	pair <int, int> ans = {1, 1e5};
	int sq_ans = 1;
	int per_ans = 1e5;

	for (int i = 0; i < help.size() - 1; i++) {
		int per_help = per(help[i], help[i + 1]);
		int sq_help = sq(help[i], help[i + 1]);
		if (sq(per_help) * sq_ans < sq(per_ans) * sq_help) {
			ans = {help[i], help[i + 1]};
			sq_ans = sq_help;
			per_ans = per_help;
		}
	}
	cout << ans.first << " " << ans.first << " " << ans.second << " " << ans.second << endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}