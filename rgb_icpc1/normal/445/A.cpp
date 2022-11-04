#include<bits/stdc++.h>

using namespace std;

int n, m;

char s[105][105], rlt[105][105], chr[] = "BW";
int vis[105][105], dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

void dfs(int x, int y, int id) {
	if (x < 0 || x >= n || y < 0 || y >= m || s[x][y] != '.') return;
	if (rlt[x][y] == 'B' || rlt[x][y] == 'W') return;
	rlt[x][y] = chr[id];
	for (int d = 0;d < 4; d ++) {
		dfs(x + dx[d], y + dy[d], 1 - id);
	}
}

int main() {
	
	cin >> n >> m;
	for (int i = 0; i < n; i ++) {
		cin >> s[i];
	}
	
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			if (s[i][j] != '.') {
				rlt[i][j] = s[i][j];
				continue;
			}
			if (rlt[i][j] == 'B' || rlt[i][j] == 'W') continue;
			dfs(i, j, 0);
		}
	}
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			cout << rlt[i][j] ;
		}
		cout << endl;
	}
}