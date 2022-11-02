#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int dir[4] = { 0, 1, 0, -1 };
int H, W, X, z[55][55]; string s[55], t[55];
void dfs1(int x, int y) {
	t[x][y] = '*';
	for (int i = 0; i < 4; i++) {
		int tx = x + dir[i], ty = y + dir[i ^ 1];
		if (0 <= tx && tx < H && 0 <= ty && ty < W && t[tx][ty] == '.') {
			dfs1(tx, ty);
		}
	}
}
int cnt2;
void dfs2(int x, int y, int c) {
	t[x][y] = '*'; z[x][y] = c; cnt2++;
	for (int i = 0; i < 4; i++) {
		int tx = x + dir[i], ty = y + dir[i ^ 1];
		if (0 <= tx && tx < H && 0 <= ty && ty < W && t[tx][ty] == '.') {
			dfs2(tx, ty, c);
		}
	}
}
int main() {
	cin >> H >> W >> X;
	for (int i = 0; i < H; i++) cin >> s[i], t[i] = s[i];
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
				if (t[i][j] != '*') dfs1(i, j);
			}
			z[i][j] = -1;
		}
	}
	vector<pair<int, int> > v;
	int cnt = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (t[i][j] != '*') {
				cnt2 = 0;
				dfs2(i, j, cnt);
				v.push_back(make_pair(cnt2, cnt)); cnt++;
			}
		}
	}
	sort(v.begin(), v.end());
	int ret = 0;
	for (int i = 0; i < v.size() - X; i++) {
		ret += v[i].first;
		for (int j = 0; j < H; j++) {
			for (int k = 0; k < W; k++) {
				if (z[j][k] == v[i].second) s[j][k] = '*';
			}
		}
	}
	cout << ret << endl;
	for (int i = 0; i < H; i++) cout << s[i] << endl;
	return 0;
}