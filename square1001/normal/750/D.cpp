#include <vector>
#include <iostream>
using namespace std;
vector<int> dx = { 0, 1, 1, 1, 0, -1, -1, -1 };
vector<int> dy = { 1, 1, 0, -1, -1, -1, 0, 1 };
int n;
int main() {
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	vector<vector<int> > d(301, vector<int>(301)); d[150][150] = 1;
	vector<vector<bool> > vis(301, vector<bool>(301));
	for (int i = 0; i < n; i++) {
		vector<vector<int> > e(301, vector<int>(301));
		for (int j = 0; j <= 300; j++) {
			for (int k = 0; k <= 300; k++) {
				for (int l = 0; l < 8; l++) {
					if (d[j][k] & (1 << l)) {
						int tx = j, ty = k;
						for (int t = 0; t < a[i]; t++) {
							tx += dx[l], ty += dy[l];
							vis[tx][ty] = true;
						}
						e[tx][ty] |= 1 << ((l + 7) & 7);
						e[tx][ty] |= 1 << ((l + 1) & 7);
					}
				}
			}
		}
		d = e;
	}
	int ret = 0;
	for (int i = 0; i <= 300; i++) {
		for (int j = 0; j <= 300; j++) {
			if (vis[i][j]) ret++;
		}
	}
	cout << ret << endl;
	return 0;
}