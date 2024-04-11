#include <bits/stdc++.h>

using namespace std;
#define maxn 1001
int n;
bool isbad[maxn][maxn];
bool canreach[maxn][maxn];
#define pii pair<int, int>
queue<pii> q;
int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	int ax, ay, bx, by, fx, fy;
	cin >> ax >> ay >> bx >> by >> fx >> fy;
	ax--; ay--;
	bx--; by--;
	fx--;
	fy--;
	isbad[ax][ay] = true;

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < 8; j++) {
			int cx = ax + i*dx[j];
			int cy = ay + i*dy[j];

			if (cx >= 0 && cx < n && cy >= 0 && cy < n) {
				isbad[cx][cy] = true;
			}
		}
	}
	canreach[bx][by] = true;
	q.push(pii(bx, by));

	while (q.size()) {
		pii cur = q.front(); q.pop();
		int cx = cur.first;
		int cy = cur.second;

		for (int i = 0; i < 8; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
				if (!canreach[nx][ny] && !isbad[nx][ny]) {
					q.push(pii(nx, ny));
					canreach[nx][ny] = true;
				}
			}
		}
	}

	if (canreach[fx][fy]) cout << "YES" << endl;
	else cout << "NO" << endl;
}