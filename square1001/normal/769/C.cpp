#include <queue>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
const int inf = 1012345678;
int dx[4] = { 1, 0, 0, -1 };
int dy[4] = { 0, -1, 1, 0 };
string e = "DLRU";
int H, W, K, sx, sy, d[1009][1009]; string s[1009];
int main() {
	cin >> H >> W >> K;
	for (int i = 0; i < H; i++) {
		cin >> s[i];
		for (int j = 0; j < W; j++) {
			d[i][j] = inf;
			if (s[i][j] == 'X') sx = i, sy = j;
		}
	}
	queue<pair<int, int> > que; que.push(make_pair(sx, sy)); d[sx][sy] = 0;
	while (!que.empty()) {
		pair<int, int> u = que.front(); que.pop();
		for (int i = 0; i < 4; i++) {
			int tx = u.first + dx[i], ty = u.second + dy[i];
			if (0 <= tx && tx < H && 0 <= ty && ty < W && s[tx][ty] != '*' && d[tx][ty] == inf) {
				d[tx][ty] = d[u.first][u.second] + 1;
				que.push(make_pair(tx, ty));
			}
		}
	}
	string ret; bool flag = true;
	while (K--) {
		bool ok = false;
		for (int i = 0; i < 4; i++) {
			int tx = sx + dx[i], ty = sy + dy[i];
			if (0 <= tx && tx < H && 0 <= ty && ty < W && s[tx][ty] != '*' && d[tx][ty] <= K) {
				sx = tx, sy = ty; ok = true; ret += e[i];
				break;
			}
		}
		if (!ok) {
			flag = false;
			break;
		}
	}
	cout << (flag ? ret : "IMPOSSIBLE") << endl;
	return 0;
}