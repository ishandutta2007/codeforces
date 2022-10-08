#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int N = 1005;

const int dCx[] = {-2, -1, -1, 0, 0, 1, 1, 2};
const int dCy[] = {0, -1, 1, -1, 1, -1, 1, 0};
const int dRy[] = {-2, -1, -1, 0, 0, 1, 1, 2};
const int dRx[] = {0, -1, 1, -1, 1, -1, 1, 0};
bool vis[N][N];
pair<int, int> list[N * N];
char map[N][N];
int m, n, clist;

bool inRange(int i, int j)
{return 1 <= i && i <= m && 1 <= j && j <= n;}

bool canPutRow(int i, int j)
{
	if (!inRange(i, j - 1) || !inRange(i, j) || !inRange(i, j + 1)) return false;
	if (map[i][j - 1] != 'w' || map[i][j] != 'b' || map[i][j + 1] != 'w') return false;
	return true;
}

bool canPutCol(int i, int j)
{
	if (!inRange(i - 1, j) || !inRange(i, j) || !inRange(i + 1, j)) return false;
	if (map[i - 1][j] != 'w' || map[i][j] != 'b' || map[i + 1][j] != 'w') return false;
	return true;
}

void putRow(int x, int y)
{
	bool vis[4];
	memset(vis, 0, sizeof(vis));
	for (int k = 0; k < 8; ++k) {
		int ux = x + dRx[k];
		int uy = y + dRy[k];
		if (inRange(ux, uy) && map[ux][uy] >= 'c' && map[ux][uy] <= 'f') 
			vis[map[ux][uy] - 'c'] = true;
	}
	for (int t = 0; t < 4; ++t) if (!vis[t]) {
		map[x][y - 1] = map[x][y] = map[x][y + 1] = t + 'c';
		return;
	}
}

void putCol(int x, int y)
{
	bool vis[4];
	memset(vis, 0, sizeof(vis));
	for (int k = 0; k < 8; ++k) {
		int ux = x + dCx[k];
		int uy = y + dCy[k];
		if (inRange(ux, uy) && map[ux][uy] >= 'c' && map[ux][uy] <= 'f') 
			vis[map[ux][uy] - 'c'] = true;
	}
	for (int t = 0; t < 4; ++t) if (!vis[t]) {
		map[x - 1][y] = map[x][y] = map[x + 1][y] = t + 'c';
		return;
	}
}

void noans()
{
	printf("NO\n");
	//for (int i = 1; i <= m; ++i) printf("%s\n", map[i] + 1);
	exit(0);
}

int main()
{
	//freopen("J.in", "r", stdin);
	scanf("%d%d\n", &m, &n);
	for (int i = 1; i <= m; ++i) gets(map[i] + 1);
	for (int i = 1; i <= m; ++i) for (int j = 1; j <= n; ++j) if (map[i][j] == 'b') {
		bool fRow = canPutRow(i, j);
		bool fCol = canPutCol(i, j);
		if (fRow && fCol) continue;
		if (!fRow && !fCol) noans();
		list[++clist] = make_pair(i, j);
		vis[i][j] = true;
	}
	for (int l = 1; l <= clist; ++l) {
		int x = list[l].first, y = list[l].second;
		bool fRow = canPutRow(x, y);
		bool fCol = canPutCol(x, y);
		if (!fRow && !fCol) {
			noans();
		}
		if (fRow)
			putRow(x, y);
		else
			putCol(x, y);
		for (int k = 0; k < 8; ++k) {
			int ux = x;
			int uy = y;
			if (fRow) {
				ux += dRx[k];
				uy += dRy[k];
			} else {
				ux += dCx[k];
				uy += dCy[k];
			}
			if (!inRange(ux, uy) || map[ux][uy] != 'b' || vis[ux][uy]) continue;
			bool fRow = canPutRow(ux, uy);
			bool fCol = canPutCol(ux, uy);
			if (fRow && fCol) continue;
			if (!fRow && !fCol) noans();
			list[++clist] = make_pair(ux, uy);
			vis[ux][uy] = true;
		}
	}
	for (int i = 1; i <= m; ++i) for (int j = 1; j <= n; ++j) {
		if (map[i][j] == 'b' || map[i][j] == 'w') 
			noans();
		if (map[i][j] >= 'c' && map[i][j] <= 'f') map[i][j] -= 2;
	}
	printf("YES\n");
	for (int i = 1; i <= m; ++i) printf("%s\n", map[i] + 1);
}