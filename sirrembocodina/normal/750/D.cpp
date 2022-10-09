#include <iostream>
#include <cmath>
using namespace std;

int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1}, dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
bool used[320][320];
bool was[320][320][30][8];
int ans = 0, n;
int l[40];

void rec(int i, int dir, int x, int y) {
	if (was[x][y][i][dir]) {
		return;
	}
	was[x][y][i][dir] = true;
	for (int j = 0; j < l[i]; ++j) {
		x += dx[dir];
		y += dy[dir];
		ans += !used[x][y];
//		cout  << x << " " << y << endl;
		used[x][y] = true;
	}
	++i;
	if (i == n) {
		return;
	}
	rec(i, (dir + 1) % 8, x, y);
	rec(i, (dir + 7) % 8, x, y);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> l[i];
	}
	rec(0, 0, 160, 160);
	cout << ans << endl;
	return 0;
}