#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	char grid[n][n];
	string line;
	for (int i = 0; i < n ; i++) {
		cin >> line;
		for (int j = 0; j < n; j++) {
			grid[i][j] = line[j];
		}

	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (grid[i][j]=='.') continue;
			for (int k = i+1; k < n; k++) {
				if (grid[k][j] == 'C') ans++;
			}
			for (int k = j+1; k < n; k++) {
				if (grid[i][k]=='C') ans++;
			}
		}
	}
	cout << ans << endl;
	cin >> ans;
}