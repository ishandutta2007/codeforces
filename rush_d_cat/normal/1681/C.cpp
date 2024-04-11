#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);

	int t;
	cin >> t;
	while (t --) {
		int n;
		cin >> n;
		vector< pair<int,int> > a(n);
		for (int i = 0; i < n; i ++) cin >> a[i].first;
		for (int i = 0; i < n; i ++) cin >> a[i].second;

		vector<pair<int,int> > b = a;
		sort(b.begin(), b.end());
		bool ok = 1;
		for (int i = 0; i + 1 < b.size(); i ++) {
			if (b[i].second > b[i+1].second) ok = 0;
		}
		if (!ok) {
			cout << -1 << "\n"; continue;
		} 
		vector<pair<int,int> > res;
		for (int i = 0; i < n; i ++) {
			pair<int,int> mn = a[i];
			int idx = i;
			for (int j = i; j < n; j ++) {
				if (a[j] < mn) {
					mn = a[j], idx = j;
				}
			}
			if (i != idx) {
				res.push_back({i+1, idx+1});
				swap(a[i], a[idx]);
			}
		}
		cout << res.size() << "\n";
		for (auto p: res) cout << p.first << " " << p.second << "\n";
	}
}
/*
2 3 1 2
2 3 2 3

1 3 2 2
2 3 2 2

*/