#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 20;
int a[maxN][maxN], b[maxN][maxN];
int n, m, res;

bool valid(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

int dx[] = {-2,-2,-1,-1, 1, 1, 2, 2};
int dy[] = {-1, 1,-2, 2,-2, 2,-1, 1};

void rec(int filled, int cnt) {
	if (filled == n * m) {
		res = max(res, cnt);
		return;
	}

	int x = filled / m;
	int y = filled % m;
	rec(filled + 1, cnt);
	if (b[x][y] == 0) {
		for (int i = 0; i < 8; ++i) {
			if (valid(x + dx[i], y + dy[i])) {
				++b[x + dx[i]][y + dy[i]];
			}
		}
		rec(filled + 1, cnt + 1);
		for (int i = 0; i < 8; ++i) {
			if (valid(x + dx[i], y + dy[i])) {
				--b[x + dx[i]][y + dy[i]];
			}
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n >> m;
	if (n > m) {
		swap(n, m);
	}
	if (n == 1) {
		cout << m << endl;
		return 0;
	}
	if (n == 2) {
		if (m % 4 == 2) {
			cout << 2 + m << endl;
		}
		if (m % 4 == 3 || m % 4 == 1) {
			cout << 1 + m << endl;
		}
		if (m % 4 == 0) {
			cout << m << endl;
		}
		return 0;
	}
	/*res = 0;
	rec(0, 0);
	cout << res << endl;*/

	int x = 0, y = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if ((i + j) % 2 == 0) {
				++x;
			} else {
				++y;
			}
		}
	}

	cout << max(x, y) << endl;

	return 0;
}