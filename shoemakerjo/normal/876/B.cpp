#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k, m;
	cin >> n >> k >> m;
	int cur;
	vector<vector<int>> mods;
	for (int i = 0; i < m; i++) {
		vector<int> b;
		mods.push_back(b);
	}
	for (int i = 0; i < n; i++) {
		cin >> cur;
		mods[cur%m].push_back(cur);
	}
	bool ok = false;
	for (int i = 0; i < m; i++) {
		if (mods[i].size() >= k) {
			ok = true;
			cout << "Yes" << endl;
			for (int j = 0; j < k; j++) {
				if (j > 0) cout << " ";
				cout << mods[i][j];
			}
			cout << endl;
			// ok = true;
			break;
		}

	}
	if (!ok) {
		cout << "No" << endl;
	}
	// cin >> n;
}