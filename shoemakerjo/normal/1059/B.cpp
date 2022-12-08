#include <bits/stdc++.h>

using namespace std;

#define maxn 1010
int n, m;
bool grid[maxn][maxn];
bool canstamp[maxn][maxn];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	string line;
	for (int i = 0; i < n; i++)  {
		cin >> line;
		for (int j = 0; j < m; j++) grid[i][j] = line[j] == '#';
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			canstamp[i][j] = true;
			// if (grid[i][j]) {
				// canstamp[i][j] = false;
				// continue;
			// }
			for (int ii = -1; ii <= 1; ii++) {
				for (int jj = -1; jj <= 1; jj++) {
					if (ii == 0 && jj == 0) continue;
					int nx = i + ii;
					int ny = j + jj;
					if (nx < 0 || ny < 0 || nx >= n || ny >= m || 
						!grid[nx][ny]) {
						canstamp[i][j] = false;
						ii = 1234;
						break;
					}
				}
			}
		}
	}
	bool ok = true;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!grid[i][j]) continue;
			bool cok = false;
			for (int ii = -1; ii <= 1; ii++) {
				for (int jj = -1; jj <= 1; jj++) {
					if (ii == 0 && jj == 0) continue;
					int nx = i + ii;
					int ny = j + jj;
					if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
						if (canstamp[nx][ny]) cok = true;
					}
				}
			}
			if (!cok) {
				ok = false;
				i = n+m;
				break;
			}
		}
	}

	if (ok) cout << "YES" << endl;
	else cout << "NO" << endl;
}