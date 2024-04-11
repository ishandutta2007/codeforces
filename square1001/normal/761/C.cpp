#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int H, W, p[55], a[55][55], x[55][3]; string s[55];
int main() {
	cin >> H >> W;
	for (int i = 0; i < W; i++) p[i] = min(i, W - i);
	for (int i = 0; i < H; i++) {
		cin >> s[i];
		for (int j = 0; j < W; j++) {
			if ('a' <= s[i][j] && s[i][j] <= 'z') a[i][j] = 0;
			else if ('0' <= s[i][j] && s[i][j] <= '9') a[i][j] = 1;
			else a[i][j] = 2;
		}
	}
	for (int i = 0; i < H; i++) {
		x[i][0] = x[i][1] = x[i][2] = 99999999;
		for (int j = 0; j < W; j++) {
			x[i][a[i][j]] = min(x[i][a[i][j]], p[j]);
		}
	}
	int ret = 99999999;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < H; j++) {
			for (int k = 0; k < H; k++) {
				if (i == j || j == k || k == i) continue;
				ret = min(ret, x[i][0] + x[j][1] + x[k][2]);
			}
		}
	}
	cout << ret << endl;
	return 0;
}