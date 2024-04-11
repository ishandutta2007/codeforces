#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	char grid[n][m];
	string line;
	for (int i = 0; i < n; i++) {
		cin >> line;
		for (int j = 0; j < m; j++) {
			grid[i][j] = line[j];
		}
	}
	bool cols = true, rows = true;
	for (int i = 1; i < m; i++) {
		if (grid[0][i] != grid[0][0]) rows = false;
	}
	for (int i = 1; i < n; i++) {
		if (grid[i][0] != grid[0][0]) cols = false;
	}
	int rs = -1, re = -1, bs = -1, be = -1, gs = -1, ge = -1;
	int bt = 0, rt = 0, gt = 0;
	if (rows) {
		
		for (int i = 0; i < n; i++) {
			bool ok = true;
			for (int j = 0; j < m; j++) {
				if (grid[i][j] != grid[i][0]) ok = false;
			}
			if (!ok) rows = false;
			if (grid[i][0] == 'R') {
				if (rs == -1) rs = i;
				re = i;
				rt++;
			}
			if (grid[i][0] == 'G') {
				if (gs == -1) gs = i;
				ge = i;
				gt++;
			}
			if (grid[i][0] == 'B') {
				if (bs == -1) bs = i;
				be = i;
				bt++;
			}
		}
	}
	else {
		for (int i = 0; i < m; i++) {
			bool ok = true;
			for (int j = 0; j < n; j++) {
				if (grid[j][i] != grid[0][i]) ok = false;
			}
			if (!ok) cols = false;
			if (grid[0][i] == 'R') {
				if (rs == -1) rs = i;
				re = i;
				rt++;
			}
			if (grid[0][i] == 'G') {
				if (gs == -1) gs = i;
				ge = i;
				gt++;
			}
			if (grid[0][i] == 'B') {
				if (bs == -1) bs = i;
				be = i;
				bt++;
			}
		}
	}
	if (!rows && !cols) {
		cout << "NO" << endl;
	}
	else if (rt != gt || rt != bt || gt != bt) {
		cout << "NO" << endl;
	}
	else if (gs-ge != bs-be || gs-ge != rs - re || rs-re != bs-be) {
		cout << "NO" << endl;
	}
	else if ((gs <= bs && bs <= ge) || (bs <= gs && gs <= be) || (rs <= bs && bs <= re) || 
		(bs <= rs && rs <= bs) || (gs <= rs && rs <= ge) || (rs <= gs && gs <= re)) {
		cout << "NO" << endl;
	}
	else cout << "YES" << endl;
	cin >> n;
}