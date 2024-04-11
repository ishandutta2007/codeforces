#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int D = 4;
vector <int> dx = {0, -1, 0, 1};
vector <int> dy = {1, 0, -1, 0};

int cnt[3];

int need = -1;

vector <vector <int>> used;
vector <vector <int>> field;

int n;	

void dfs(int x, int y) {
	if (used[x][y] || !field[x][y]) return;
	used[x][y] = 1;
	cnt[(x + y + field[x][y]) % 3]++;
	for (int d = 0; d < D; ++d) {
		int xx = dx[d] + x, yy = dy[d] + y;
		if (xx < 0 || xx >= n) continue;
		if (yy < 0 || yy >= n) continue;
		dfs(xx, yy);
	}
}

void recolor_dfs(int x, int y) {
	if (used[x][y] == 2 || !field[x][y]) return;
	used[x][y] = 2;
	cnt[(x + y + field[x][y]) % 3]--;
	if ((x + y + field[x][y]) % 3 == need) {
		field[x][y] = 3 - field[x][y];
		//cout << "RECOLOR: " << x << " " << y << "\n";
	}
	for (int d = 0; d < D; ++d) {
		int xx = dx[d] + x, yy = dy[d] + y;
		if (xx < 0 || xx >= n) continue;
		if (yy < 0 || yy >= n) continue;
		recolor_dfs(xx, yy);
	}
}


void solve() {
	cin >> n;
	used.clear();
	used.resize(n, vector <int> (n, 0));

	field.clear();
	field.resize(n, vector<int>(n, 0));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			char c;
			cin >> c;
			if (c == 'X') {
				field[i][j] = 1;
			} else if (c == 'O') {
				field[i][j] = 2;
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (!field[i][j] || used[i][j]) continue;
			dfs(i, j);
			if (cnt[0] <= cnt[1] && cnt[0] <= cnt[2]) {
				need = 0;
			} else if (cnt[1] <= cnt[0] && cnt[1] <= cnt[2]) {
				need = 1;
			} else {
				need = 2;
			}
			//cout << need << "\n";
			recolor_dfs(i, j);
		}
	}


	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (field[i][j] == 0) {
				cout << ".";
			} else if (field[i][j] == 1) {
				cout << "X";
			} else {
				cout << "O";
			}
		}
		cout << "\n";
	}

}

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		solve();
	}

}