#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	char grid[n][m];
	string line;
	for (int i = 0; i < n; i++) {
		cin >> line;
		for (int j = 0; j < m; j++) {
			grid[i][j] = line[j];
		}
	}
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	x1--; y1--; x2--; y2--;
	//dir 0, 1, 2, 3
	int dist[n][m][4];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dist[i][j][0] = dist[i][j][1] = 
				dist[i][j][2] = dist[i][j][3] = 123456789;
		}
	}
	priority_queue<tuple<int, int, int, int, int>> pq;
	pq.push(make_tuple(0, 0, x1, y1, 0));
	dist[x1][y1][0] = dist[x1][y1][1] = dist[x1][y1][2] = dist[x1][y1][3] = 1;
	while (pq.size() != 0) {
		tuple<int, int, int, int, int> ti = pq.top();
		pq.pop();
		int di = 0-get<0>(ti);
		int numleft = get<1>(ti);
		int x = get<2>(ti);
		int y = get<3>(ti);
		int dir = get<4>(ti);
		if (dist[x][y][dir] < di) {
			continue;
		}
		if (grid[x][y] == '#') continue;
		//0 decreases x, 1 increases x, 2 decreases y, 3 increases y
		
		if (x > 0) {
			if (di + 1 < dist[x-1][y][0]) {
				dist[x-1][y][0] = di+1;
				pq.push(make_tuple(0-(di+1), k-1, x-1, y, 0));
			}
		}
		if (x < n-1) {
			if (di + 1 < dist[x+1][y][1]) {
				dist[x+1][y][1] = di+1;
				pq.push(make_tuple(0-(di+1), k-1, x+1, y, 1));
			}
		}
		if (y > 0) {
			if (di + 1 < dist[x][y-1][2]) {
				dist[x][y-1][2] = di+1;
				pq.push(make_tuple(0-(di+1), k-1, x, y-1, 2));
			}
		}
		if (y < m-1) {
			if (di + 1 < dist[x][y+1][3]) {
				dist[x][y+1][3] = di+1;
				pq.push(make_tuple(0-(di+1), k-1, x, y+1, 3));
			}
		}
		if (numleft > 0) {
			if (dir == 0) {
				if (x > 0) {
					if (di < dist[x-1][y][0]) {
						dist[x-1][y][0] = di;
						pq.push(make_tuple(0-di, numleft-1, x-1, y, 0));
					}
				}
			}
			if (dir == 1) {
				if (x < n-1) {
					if (di < dist[x+1][y][1]) {
						dist[x+1][y][1] = di;
						pq.push(make_tuple(0-(di), numleft-1, x+1, y, 1));
					}
				}
			}
			if (dir == 2) {
				if (y > 0) {
					if (di < dist[x][y-1][2]) {
						dist[x][y-1][2] = di;
						pq.push(make_tuple(0-(di), numleft-1, x, y-1, 2));
					}
				}
			}
			if (dir == 3) {
				if (y < m-1) {
					if (di < dist[x][y+1][3]) {
						dist[x][y+1][3] = di;
						pq.push(make_tuple(0-(di), numleft-1, x, y+1, 3));
					}
				}
			}
		}

	}
	int ans = dist[x2][y2][0];
	ans = min(ans, dist[x2][y2][1]);
	ans = min(ans, dist[x2][y2][2]);
	ans = min(ans, dist[x2][y2][3]);
	if (x1 == x2 && y1 == y2) {
		cout << 0 << endl;
	}
	else if (ans == 123456789) {
		cout << -1 << endl;
	}
	else cout << ans << endl;
	// cin >> ans;
}