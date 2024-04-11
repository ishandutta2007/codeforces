#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	int t;
	cin >> t;

	while (t --) {
		int n, m;
		cin >> n >> m;
		vector<string> s(n);
		
		for (int i = 0; i < n; i ++)
			cin >> s[i];

		if (s[0][0] == '1') {
			cout << -1 << "\n";
			continue;
		}
		
		vector<vector<int> > res;	
		for (int i = 1; i < n; i ++) {
			for (int j = 0; j < m; j ++) {
				if (s[i][j] == '1') {
					res.push_back({i-1, j, i, j});
				}
			}
		}	
		reverse(res.begin(), res.end());
		for (int j = m - 1; j >= 1; j --) {
			if (s[0][j] == '1') {
				res.push_back({0, j-1, 0, j});
			}
 		}
 		cout << res.size() << "\n";
 		for (auto p: res) {
 			for (auto x: p) cout << x + 1 << " ";
 			cout << "\n";
 		}
	}
}