#include <bits/stdc++.h>

using namespace std;
#define maxn 300010
#define endl '\n'
int n, m;

vector<int> grid[maxn];

int byrow[maxn][4][4]; //what is first, what is second
int bycol[maxn][4][4];

const bool debug = false;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	string s;
	string st = "ACGT";
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			int v;
			if (s[j] == 'A')  v = 0;
			else if (s[j] == 'C') v = 1;
			else if (s[j] == 'G') v = 2;
			else v = 3;

			grid[i].push_back(v);
		}
	}


	if (debug) {
		for (int i = 0; i < n; i++) {
			cout << "    ";
			for (int v : grid[i]) cout << v;
			cout << endl;
		}
	}

	//alternate in horizontal or in vertical
	for (int i = 0; i < n; i++) {

		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				if (j == k) {
					byrow[i][j][k] = maxn;
					continue;
				} 
				int cc = 0;
				for (int spot = 0; spot < m; spot++) {
					if (spot % 2 == 0) {
						if (grid[i][spot] != j) cc++;
					}
					else {
						if (grid[i][spot] != k) cc++;
					}
				}
				byrow[i][j][k] = cc;

			}
		}

	}

	if (debug) cout << "HERE " << endl;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < 4; j++) {

			for (int k = 0; k < 4; k++) {
				if (j == k) {
					bycol[i][j][k] = maxn;
					continue;
				}
				int cc = 0;
				for (int spot = 0; spot < n; spot++) {
					if (spot % 2 == 0) {
						if (grid[spot][i] != j) cc++;
					}
					else {
						if (grid[spot][i] != k) cc++;
					}
				}
				bycol[i][j][k] = cc;
			}
			
		}	
	}

	int mincost = maxn;

	vector<int> nums;
	nums.push_back(0);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);

	if (debug) cout << "HERE HERE" << endl;
	
	do {

		int cc = 0;
		for (int i = 0; i < n; i++) {
			if (i%2 == 0) {
				cc += min(byrow[i][nums[0]][nums[1]], 
					byrow[i][nums[1]][nums[0]]);
			}
			else {
				cc += min(byrow[i][nums[2]][nums[3]], 
					byrow[i][nums[3]][nums[2]]);
			}
		}

		mincost = min(mincost, cc);

	} while (next_permutation(nums.begin(), nums.end()));

	sort(nums.begin(), nums.end());

	if (debug) cout << "HERE HERE HERE" << endl;

	do {

		int cc = 0;
		for (int i = 0; i < m; i++) {
			if (i%2 == 0) {
				cc += min(bycol[i][nums[0]][nums[1]], 
					bycol[i][nums[1]][nums[0]]);
			}
			else {
				cc += min(bycol[i][nums[2]][nums[3]], 
					bycol[i][nums[3]][nums[2]]);
			}
		}

		mincost = min(mincost, cc);

	} while (next_permutation(nums.begin(), nums.end()));

	if (debug) cout << "MINCOST: " << mincost << endl;
	if (debug) cout << "val : " << byrow[0][0][2] << endl;

	bool found = false;

	sort(nums.begin(), nums.end());

	do {
		if (found) break;

		int cc = 0;
		for (int i = 0; i < n; i++) {
			if (i%2 == 0) {
				cc += min(byrow[i][nums[0]][nums[1]], 
					byrow[i][nums[1]][nums[0]]);
			}
			else {
				cc += min(byrow[i][nums[2]][nums[3]], 
					byrow[i][nums[3]][nums[2]]);
			}
		}

		if (cc == mincost) {
			found = true;

			for (int i = 0; i < n; i++) {
				if (i%2 == 0) {

					if (byrow[i][nums[0]][nums[1]] < 
						byrow[i][nums[1]][nums[0]]) {

						for (int j = 0; j < m; j++) {
							if (j%2 == 0) cout << st[nums[0]];
							else cout << st[nums[1]];
						}

					}
					else {
						for (int j = 0; j < m; j++) {
							if (j%2 == 0) cout << st[nums[1]];
							else cout << st[nums[0]];
						}
					}

					
				}
				else {
					if (byrow[i][nums[2]][nums[3]] < 
						byrow[i][nums[3]][nums[2]]) {

						for (int j = 0; j < m; j++) {
							if (j%2 == 0) cout << st[nums[2]];
							else cout << st[nums[3]];
						}

					}
					else {
						for (int j = 0; j < m; j++) {
							if (j%2 == 0) cout << st[nums[3]];
							else cout << st[nums[2]];
						}
					}
				}
				cout << endl;
			}

		}

	} while (next_permutation(nums.begin(), nums.end()));

	sort(nums.begin(), nums.end());

	do {
		if (found) break;

		int cc = 0;
		for (int i = 0; i < m; i++) {
			if (i%2 == 0) {
				cc += min(bycol[i][nums[0]][nums[1]], 
					bycol[i][nums[1]][nums[0]]);
			}
			else {
				cc += min(bycol[i][nums[2]][nums[3]], 
					bycol[i][nums[3]][nums[2]]);
			}
		}

		if (cc == mincost) {
			found = true;

			vector<string> stuff;

			for (int i = 0; i < m; i++) {

				string cur = "";
				if (i%2 == 0) {

					if (bycol[i][nums[0]][nums[1]] < 
						bycol[i][nums[1]][nums[0]]) {

						for (int j = 0; j < n; j++) {
							if (j%2 == 0) cur += st[nums[0]];
							else cur +=  st[nums[1]];
						}

					}
					else {
						for (int j = 0; j < n; j++) {
							if (j%2 == 0) cur += st[nums[1]];
							else cur += st[nums[0]];
						}
					}

					
				}
				else {
					if (bycol[i][nums[2]][nums[3]] < 
						bycol[i][nums[3]][nums[2]]) {

						for (int j = 0; j < n; j++) {
							if (j%2 == 0) cur += st[nums[2]];
							else cur += st[nums[3]];
						}

					}
					else {
						for (int j = 0; j < n; j++) {
							if (j%2 == 0) cur += st[nums[3]];
							else cur += st[nums[2]];
						}
					}
				}
				stuff.push_back(cur);
			}

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					cout << stuff[j][i];
				}
				cout << endl;
			}

		}

	} while (next_permutation(nums.begin(), nums.end()));

	if (!found && debug) cout << "CONFUSED" << endl;
	cout.flush();

}