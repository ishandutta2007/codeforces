#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int H, W, c[5009][5009]; string s[2509];
int sum(int ax, int ay, int bx, int by) {
	return c[ax][ay] + c[bx][by] - c[ax][by] - c[bx][ay];
}
int main() {
	ios::sync_with_stdio(false);
	cin >> H >> W;
	for (int i = 0; i < H; i++) {
		cin >> s[i];
		for (int j = 0; j < W; j++) c[i + 1][j + 1] = s[i][j] - 48;
	}
	int X = max(H, W);
	for (int i = 0; i <= 2 * X; i++) {
		for (int j = 0; j <= 2 * X; j++) {
			c[i + 1][j] += c[i][j];
		}
	}
	for (int i = 0; i <= 2 * X; i++) {
		for (int j = 0; j <= 2 * X; j++) {
			c[i][j + 1] += c[i][j];
		}
	}
	int ret = 1 << 30;
	for (int i = 2; i <= X; i++) {
		int res = 0;
		for (int j = 0; j < H; j += i) {
			for (int k = 0; k < W; k += i) {
				int r = sum(j, k, j + i, k + i);
				res += min(r, i * i - r);
			}
		}
		ret = min(ret, res);
	}
	cout << ret << endl;
	return 0;
}