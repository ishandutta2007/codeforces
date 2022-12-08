#include <bits/stdc++.h>

using namespace std;

char grid[2010][2010];
int vert[2010][2010];
int hori[2010][2010];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
	string line;
	for (int i = 0; i < n; i++) {
		cin >> line;
		for (int j = 0; j < m; j++) {
			grid[i][j] = line[j];
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == '*') vert[i][j] = 0;
			else {
				vert[i][j] = j == 0 ? 1 : vert[i][j-1] + 1;
			}
			if (vert[i][j] >= k) ans++;
		}
	}
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {
			if (grid[i][j] == '*') hori[i][j] = 0;
			else {
				hori[i][j] = i == 0 ? 1 : hori[i-1][j] + 1;
			}
			if (hori[i][j] >= k && k != 1) ans++;
		}
	}
	
	cout << ans << endl;
	cin >> ans;
}