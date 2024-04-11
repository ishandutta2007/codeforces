#include <bits/stdc++.h>
#define ll long long

using namespace std;


const int D = 4;
const int N = 1007;
int c[N][N];
char a[N][N];
int now = 1;

vector <int> res;
vector <int> dx = {0, 1, 0, -1};
vector <int> dy = {1, 0, -1, 0};

int n, m, k;
int cnt = 0;

bool isCorrect(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(int x, int y) {
	if (c[x][y]) return;
	c[x][y] = now;
	for (int d = 0; d < D; d++) {
		int x1 = dx[d] + x, y1 = dy[d] + y;
		if (!isCorrect(x1, y1)) continue;
		if (a[x1][y1] == '*') {
			cnt++;
		} else {
			dfs(x1, y1);
		}
	}
}

int main() {
	//freopen("D.in", "r", stdin);
	//freopen("D.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == '*') continue;
			cnt = 0;
			dfs(i, j);
			now++;
			res.push_back(cnt);
		}
	}
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		cout << res[c[x][y] - 1] << "\n";
	}
}