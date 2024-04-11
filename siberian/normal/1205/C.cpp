#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

int query(int x1, int y1, int x2, int y2) {
	cout << "? " << x1 + 1 << " " << y1 + 1 << " " << x2 + 1 << " " << y2 + 1 << endl;
	int ans;
	cin >> ans;
	return ans;
}

char get(int x) {
	return x + '0';
}

void out_ans(vector<vector<int> > & table) {
	cout << "!" << endl;
	for (auto i : table) {
		for (auto j : i) {
			cout << j;
		}
		cout << endl;
	}
	exit(0);
}

const vector<int> dx1 = {1, 0}, dy1 = {0, 1};
const vector<int> dx2 = {-1, 0}, dy2 = {0, -1};
const vector<int> dx = {2, 1, 0}, dy = {0, 1, 2};

int n;

vector<vector<int> > table1, table2;
vector<vector<vector<vector<int> > > > dp1, dp2;

vector<vector<int> > ans;

void read() {
	cin >> n;
}

bool check(int x1, int y1, int x2, int y2, int x, int y) {
	return x1 <= x && x2 >= x && y1 <= y && y2 >= y;
}

void make_table(vector<vector<int> > & table) {
	table.assign(n, vector<int> (n, -1));
}

void calc(vector<vector<int> > & table, int num) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (((i + j) & 1) == num && table[i][j] != -1) {
				for (int k = 0; k < 3; k++) {
					if (i + dx[k] < n && j + dy[k] < n && table[i + dx[k]][j + dy[k]] == -1) {
						int q = query(i, j, i + dx[k], j + dy[k]);
						table[i + dx[k]][j + dy[k]] = table[i][j] ^ 1 ^ q;
					}
				}
			}
		}
	}
}

void make(vector<vector<vector<vector<int> > > > & dp) {
	dp.assign(n, vector<vector<vector<int> > > (n, vector<vector<int> > (n, vector<int> (n, false))));
}

void build(vector<vector<vector<vector<int> > > > & dp, vector<vector<int> > & table) {
	make(dp);
	for (int x2 = 0; x2 < n; x2++) {
		for (int y2 = 0; y2 < n; y2++) {
			for (int x1 = x2; x1 >= 0; x1--) {
				for (int y1 = y2; y1 >= 0; y1--) {
					if (table[x1][y1] != table[x2][y2]) continue;
					if (x2 - x1 + y2 - y1 <= 1) {
						dp[x1][y1][x2][y2] = true;
						continue;
					}
	
					for (int i = 0; i < 2; i++) {
						for (int j = 0; j < 2; j++) {
							if (!check(x1, y1, x2, y2, x1 + dx1[i], y1 + dy1[i])) continue;
							if (!check(x1, y1, x2, y2, x2 + dx2[j], y2 + dy2[j])) continue;
							dp[x1][y1][x2][y2] |= dp[x1 + dx1[i]][y1 + dy1[i]][x2 + dx2[j]][y2 + dy2[j]];
						}
					}
				}
			}
		}
	}
}

void run() {
	make_table(table1);
	make_table(table2);

	table1[0][0] = 1;
	table1[n - 1][n - 1] = 0;
	calc(table1, 0);

	table1[0][1] = 0;
	calc(table1, 1);

	int q = query(1, 0, 1, 2);
	table1[1][0] = table1[1][2] ^ 1 ^ q;
	calc(table1, 1);

	table2 = table1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if ((i + j) & 1) {
				table2[i][j] ^= 1;
			}
		}
	}

	build(dp1, table1);
	build(dp2, table2);	

	for (int x2 = 0; x2 < n; x2++) {
		for (int y2 = 0; y2 < n; y2++) {
			for (int x1 = x2; x1 >= 0; x1--) {
				for (int y1 = y2; y1 >= 0; y1--) {
					if (x2 - x1 + y2 - y1 <= 1) continue;
					if (dp1[x1][y1][x2][y2] != dp2[x1][y1][x2][y2]) {
						int q = query(x1, y1, x2, y2);
						if (q == dp1[x1][y1][x2][y2]) {
							ans = table1;
						}
						else {
							ans = table2;
						}
						return;
					}
				}
			}
		}
	}
	assert(false);
}

void write() {
	out_ans(ans);
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	read();
	run();
	write();
	return 0;
}