#include <bits/stdc++.h>

using namespace std;

using llint = long long;
int p[505];
int b[505][505];
const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> p[i];
	memset(b, 0, sizeof b);
	for (int i = 1; i <= n; i++) {
		int x = i, y = i;
		b[x][y] = p[i];
		for (int j = 2; j <= p[i]; j++) {
			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k], ny = y + dy[k];
				if (nx < 1 || ny < 1 || nx > n || ny > n) continue;
				if (b[nx][ny]) continue;
				x = nx, y = ny;
				break;
			}
			b[x][y] = p[i];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) cout << b[i][j] << ' ';
		cout << endl;
	}
	
	return 0;
}