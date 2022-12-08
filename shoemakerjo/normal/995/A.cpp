#include <bits/stdc++.h>

using namespace std;
#define maxn 52
#define mp make_pair
#define pp pair<int, pair<int, int>>
#define maxk 123
int n, k;
int grid[4][maxn];
int nx[4][maxn];
int ny[4][maxn];
bool fin[maxk];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		nx[1][i] = 1;
		ny[1][i] = i+1;
		nx[2][i] = 2;
		ny[2][i] = i-1;
	}
	nx[2][0] = 1;
	ny[2][0] = 0;
	nx[1][n-1] = 2;
	ny[1][n-1] = n-1;

	vector<pp> ans;
	int ox, oy;
	if (k == 2*n) {
		//then we might have an issue
		for (int i = 0; i < n; i++) {
			if (grid[1][i] == grid[0][i]) {
				ans.push_back(mp(grid[1][i], mp(0, i)));
				grid[1][i] = 0;
				// k--;

				
				ox = 1;
				oy = i;
				break;
			}
			if (grid[2][i] == grid[3][i]) {
				ans.push_back(mp(grid[2][i], mp(3, i)));
				grid[2][i] = 0;
				// k--;
				
				ox = 2;
				oy = i;
				break;
			}
			if (i == n-1) {
				cout << -1 << endl;
				cin >> n;
				return 0;
			}
		}
	}
	for (int i = 1; i <= 2; i++) {
		for (int j = 0; j < n; j++) {
			if (grid[i][j] == 0) {
				ox = i;
				oy = j;
			}
		}
	}
	//process everything
	for (int i = 0; i < 2*n; i++) {

		for (int r = 1; r <= 2; r++) {
			for (int c = 0; c < n; c++) {
				if (r == 1) {
					if (grid[r][c] != 0 && grid[r][c] == grid[0][c]) {
						ans.push_back(mp(grid[r][c], mp(0,  c)));
						grid[r][c] = 0;
					}
				}
				else {
					if (grid[r][c] != 0 && grid[r][c] == grid[3][c]) {
						ans.push_back(mp(grid[r][c], mp(3, c)));
						grid[r][c] = 0;
					}
				}
			}
		}
		for (int i = 0; i < 2*n-1; i++) {
				// if (pr) cout << "o:  " << ox << " " << oy << endl;
			int xc = nx[ox][oy];
			int yc = ny[ox][oy];
			if (grid[xc][yc] != 0) {
				ans.push_back(mp(grid[xc][yc], mp(ox, oy) ));
				grid[ox][oy] = grid[xc][yc];
				grid[xc][yc] = 0;
			}
			ox = xc;
			oy = yc;
			//guaranteed that ox, oy is empty after this
		}
			
	}
	
	cout << ans.size() << endl;

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i].first << " " << ans[i].second.first+1 << " " << 
			ans[i].second.second+1 << endl;
	}
	cin >> n;
}