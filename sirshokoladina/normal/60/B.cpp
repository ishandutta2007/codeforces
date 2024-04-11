#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define forn(i,n) for (int i = 0; i < (int)(n); i++)

int c[20][20][20];

bool u[20][20][20];

int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int dfs(int x, int y, int z) {
	if (c[x][y][z] || u[x][y][z])
		return 0;
	u[x][y][z] = 1;
	int res = 1;
	forn(i, 6)
		res += dfs(x + dx[i], y + dy[i], z + dz[i]);
	return res;
}

int main() {
//	freopen("input.txt", "rt", stdin);
//	freopen("output.txt", "wt", stdout);
	forn(i,20)
		forn(j,20)
			forn(k,20){
				c[i][j][k] = 1;
				u[i][j][k]=0;
			}
	int k, n, m;
	cin >> k >> n >> m;
	forn (i, k)
		forn (j, n)
			forn (l, m) {
				char cc;
				cin >> cc;
				c[i + 1][j + 1][l + 1] = bool(cc == '#');
			}
	int x, y;
	cin >> x >> y;
	cout << dfs(1, x, y);
}