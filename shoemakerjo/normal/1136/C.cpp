#include <bits/stdc++.h>

using namespace std;

int m1[502][502];
int m2[502][502];

int n, m;


vector<int> v1[1004], v2[1004];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> m1[i][j];

			v1[i + j].push_back(m1[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> m2[i][j];
			v2[i+j].push_back(m2[i][j]);
		}
	}

	bool ok = true;
	for (int i = 0; i <= 1000; i++) {
		if (v1[i].size() == 0) continue;
		sort(v1[i].begin(), v1[i].end());
		sort(v2[i].begin(), v2[i].end());
		for (int j = 0; j < v1[i].size(); j++) {
			if (v1[i][j] != v2[i][j]) ok = false;
		}
	}
	if (ok) {
		cout << "YES" << endl;
	}
	else cout << "NO" << endl;
}