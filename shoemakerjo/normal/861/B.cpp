#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> anses;

	int loc[101];
	for (int i = 0; i <= 100; i++) {
		loc[i] = -1;
	}
	int k, f;
	for (int i = 0; i < m; i++) {
		cin >> k >> f;
		loc[k] = f;
	}
	for (int j = 1; j <= 100; j++) {
		int curspot = 0;
		bool ok = true;
		for (int i = 1; i <= 100; i++) {
			int start = (i-1)*j + 1;
			for (int k = start; k < start+j && k <= 100; k++) {
				if (loc[k] == -1) {
					if (k == n) curspot = i;
					continue;
				}
				if (loc[k] != i) {
					ok = false;
					break;
				}
			}
		}
		if (ok) anses.push_back(curspot);
	}
	sort(anses.begin(), anses.end());
	if (loc[n] != -1) {
		cout << loc[n] << endl;
	}
	else {
		if (anses.size() == 0 || anses[0] != anses[anses.size()-1]) {
			cout << -1 << endl;
		}
		else cout << anses[0] << endl;
	}
	// cin >> n;
	
}