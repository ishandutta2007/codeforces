#include <bits/stdc++.h>

using namespace std;

char grid[102][102];
int ans[102][102];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	string line;
	for (int i = 0; i < n; i++) {
		cin >> line;
		for (int j = 0; j < n; j++) {
			grid[i][j] = line[j];
			ans[i][j] = 0;
		}
	}
	int most = 0;
	int x = 0;
	int y = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			bool ok = true;
			for (int m = i; m < i+k; m++) {
				if (m >= n || grid[m][j] == '#') ok = false;
			}
			if (ok) {
				for (int m = i; m < i+k; m++) {
					ans[m][j]++;
				}
			}
			ok = true;
			for (int m = j; m < j+k; m++) {
				if (m >= n || grid[i][m] == '#') ok = false;
			}
			if (ok) {
				for (int m = j; m < j+k; m++) {
					ans[i][m]++;
				}
			}

		}

	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (ans[i][j] > most) {
				most = ans[i][j];
				x = i;
				y = j;
			}
		}
	}
	cout << x+1<< " " << y+1 << endl;
	cin >> x;
}