#include <bits/stdc++.h>

using namespace std;
#define maxr 1010
#define pii pair<int, int>

char grid[maxr][maxr];
int dist[maxr][maxr];
int r, c;
queue<pii> q;

void go(int x, int y, int d) {
	if (x < 0 || y < 0 || x >= r || y >= c) return;
	if (dist[x][y] != -1) return;
	if (grid[x][y] == 'T') return;
	dist[x][y] = d+1;
	q.push(pii(x, y));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> r >> c;
	string line;
	int sx, sy;
	int ex, ey;
	for (int i = 0; i < r; i++) {
		cin >> line;
		for (int j = 0; j < c; j++) {
			grid[i][j] = line[j];
			if (line[j] == 'S') {
				sx = i;
				sy = j;
			}
			if (line[j] == 'E') {
				ex = i;
				ey = j;
			}
			dist[i][j] = -1;

		}
	}
	dist[ex][ey] = 0;
	q.push(pii(ex, ey));
	while (!q.empty()) {
		pii cur = q.front(); q.pop();
		int x = cur.first;
		int y = cur.second;
		int dc = dist[x][y];
		go(x-1, y, dc);
		go(x+1, y, dc);
		go(x, y-1, dc);
		go(x, y+1, dc);
	}
	int ans = 0;
	int d = dist[sx][sy];
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (grid[i][j] - '0' >= 0 && grid[i][j]-'0' <= 9) {
				if (dist[i][j] <= d && dist[i][j] != -1) {
					ans += grid[i][j]-'0';
				}
			}
		}
	}
	cout << ans << endl;
	cin >> r;


}