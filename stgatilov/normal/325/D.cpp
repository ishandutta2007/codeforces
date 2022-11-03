#pragma comment(linker, "/STACK:100000000")
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long int64;
#ifdef HOME
	#define E(c) cerr<<#c
	#define Eo(x) cerr<<#x<<" = "<<(x)<<endl
	#define Ef(...) fprintf(stderr, __VA_ARGS__)
#else
	#define E(c) ((void)0)
	#define Eo(x) ((void)0)
	#define Ef(...) ((void)0)
#endif

const int SIZE = 3<<10;

struct Cell {
	int d[2];
};

int r, c, n;
Cell matr[SIZE][SIZE];
bool dead[SIZE][SIZE];

struct Change {
	int x, y;
	int old[2];
};
vector<Change> journal;

int ModC(int x) {
    if (x < 0) x += c;
    if (x >= c) x -= c;
    if (x >= 0 && x < c)
    	return x;
    x %= c;
    if (x < 0) x += c;
    assert(x >= 0 && x < c);
    return x;
}

void Rollback() {
	for (int i = journal.size()-1; i>=0; i--) {
		const Change &q = journal[i];
		matr[q.x][q.y].d[0] = q.old[0];
		matr[q.x][q.y].d[1] = q.old[1];
	}
}

void FindHead(int x, int y, int *res) {
	Cell &cell = matr[x][ModC(y)];
	if (cell.d[0] == 0 && cell.d[1] == 0) {
		res[0] = res[1] = 0;
		return;
	}
	int xf = x + cell.d[0];
	int yf = y + cell.d[1];

	int fres[2];
	FindHead(xf, yf, fres);

	res[0] = cell.d[0] + fres[0];
	res[1] = cell.d[1] + fres[1];

	Change mod;
	mod.x = x;
	mod.y = ModC(y);
	mod.old[0] = cell.d[0];
	mod.old[1] = cell.d[1];
	journal.push_back(mod);

	cell.d[0] = res[0];
	cell.d[1] = res[1];
}

bool Merge(int x1, int y1, int x2, int y2) {
	int d1[2], d2[2];
	FindHead(x1, y1, d1);
	FindHead(x2, y2, d2);
	int h1[2] = {x1 + d1[0], y1 + d1[1]};
	int h2[2] = {x2 + d2[0], y2 + d2[1]};

	if (h1[0] == h2[0] && h1[1] == h2[1])
		return false;
	bool cycle = (h1[0] == h2[0] && ModC(h1[1]) == ModC(h2[1]));
	
	Change mod;
	if (rand() & 1) {
		mod.x = h1[0];
		mod.y = ModC(h1[1]);
		Cell &cell = matr[mod.x][mod.y];
		mod.old[0] = cell.d[0];
		mod.old[1] = cell.d[1];
        cell.d[0] = h2[0] - h1[0];
        cell.d[1] = h2[1] - h1[1];
	}
	else {
		mod.x = h2[0];
		mod.y = ModC(h2[1]);
		Cell &cell = matr[mod.x][mod.y];
		mod.old[0] = cell.d[0];
		mod.old[1] = cell.d[1];
        cell.d[0] = h1[0] - h2[0];
        cell.d[1] = h1[1] - h2[1];
	}
	journal.push_back(mod);

	return cycle;
}

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%d%d%d", &r, &c, &n);

	int ans = 0;
	for (int i = 0; i<n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--;  y--;

        dead[x][y] = true;
		int nk = 0;
		int nbr[8][2];
		for (int dx = -1; dx <= 1; dx++) {
			for (int dy = -1; dy <= 1; dy++) {
				if (dx == 0 && dy == 0) continue;
				int nx = x + dx;
				int ny = y + dy;
				if (nx < 0 || nx >= r) continue;
				if (!dead[nx][ModC(ny)]) continue;

                nbr[nk][0] = nx;
                nbr[nk][1] = ny;
                nk++;
			}
		}

		journal.clear();
		bool bad = false;
		for (int j = 0; j<nk; j++) {
			bool cycle = Merge(x, y, nbr[j][0], nbr[j][1]);
			if (cycle) {
				bad = true;
				break;
			}
		}

		if (bad) {
			Rollback();
	        dead[x][y] = false;
		}
		else {
			ans++;
		}

/*		Ef("Cell (%d;%d) added: %s\n", x, y, bad ? "NO" : "YES");
		for (int i = 0; i<r; i++) {
			for (int j = 0; j<c; j++) {
				if (dead[i][j]) {
					int qq[2];
					FindHead(i, j, qq);
					Ef("[%2d;%2d] ", i+qq[0], j+qq[1]);
				}
				else
					Ef("[XX;XX] ");
			}
			Ef("\n");
		}
		Ef("\n");
		fflush(stderr);*/
	}

	printf("%d\n", ans);


	return 0;
}