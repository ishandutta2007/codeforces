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

const int SIZE = 312;
const int AREA = SIZE * SIZE;

typedef map<int, int> iiMap;
typedef iiMap::iterator mIter;

int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int n, m;
int sx, sy;

struct Symbol {
	int x, y;
	int col;

	int spind;
	inline bool operator< (const Symbol &oth) const {
		return spind < oth.spind;
	}
};

struct Node {
	int father;
	int pop;
	int color;
	int stind;
};
int nk;
Node nodes[2*AREA];
vector<Symbol> stands[AREA];

int GetRoot(int x) {
	if (nodes[x].father == x) return x;
	return nodes[x].father = GetRoot(nodes[x].father);
}

map<int, int> cnode;
int npict[SIZE][SIZE];

int GetIndex(int tcol) {
	if (cnode.find(tcol) == cnode.end()) {
		cnode[tcol] = nk;
		nodes[nk].father = nk;
		nodes[nk].pop = 0;
		nodes[nk].color = tcol;
		nodes[nk].stind = -1;
		nk++;
	}
	return cnode[tcol];
}

Symbol qarr[AREA];
int qs;

int spiral[2*SIZE][2*SIZE];

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	for (int i = 0; i<n; i++) for (int j = 0; j<m; j++) {
		int tc = 0;
		scanf("%d", &tc);
		npict[i][j] = GetIndex(tc);
		nodes[npict[i][j]].pop++;
	}
	for (int i = 0; i<n; i++) for (int j = 0; j<m; j++) {
		int tc;
		scanf("%d", &tc);
		if (tc < 0) continue;

		Symbol s;
		s.x = i;  s.y = j;  s.col = tc;
		int ni = npict[i][j];
		nodes[ni].stind = ni;
		stands[ni].push_back(s);
	}
	scanf("%d%d", &sx, &sy);
	sx--;  sy--;

	int cx = SIZE;
	int cy = SIZE;
	int spk = 0;
	for (int w = 0; w<4*SIZE; w++) {
		int r = w/2 + 1;
		int d = w%4;
		for (int i = 0; i<r; i++) {
			if (cx >= 0 && cy >= 0 && cx < 2*SIZE && cy < 2*SIZE)
				spiral[cx][cy] = spk++;
			cx += dir[d][0];
			cy += dir[d][1];
		}
	}

	qs = 1;
	vector<Symbol> &stv = stands[npict[sx][sy]];
	for (int u = 0; u<stv.size(); u++)
		if (stv[u].x == sx && stv[u].y == sy) {
			qarr[0] = stv[u];
			for (int v = u; v+1<stv.size(); v++)
				stv[v] = stv[v+1];
			stv.pop_back();
			break;
		}

	int64 ans = 0;
	for (int qi = 0; qi < qs; qi++) {
		int tx = qarr[qi].x;
		int ty = qarr[qi].y;
		int tcol = qarr[qi].col;

		int ni = GetRoot(npict[tx][ty]);
		int tcc = nodes[ni].color;
		Ef("X%d Y%d C%d on N%d C%d\n", tx, ty, tcol, ni, tcc);

		if (tcc != tcol && tcc != 0) {
			int ai = GetIndex(tcol);
			Ef("paint N%d P%d C%d to N%d P%d C%d\n", ni, nodes[ni].pop, nodes[ni].color, ai, nodes[ai].pop, nodes[ai].color);

			ans += nodes[ni].pop;
			if (nodes[ni].stind >= 0) {
				vector<Symbol> added;

				int &sti = nodes[ni].stind;
				for (int i = 0; i<stands[sti].size(); i++) {
					Symbol ts = stands[sti][i];
					ts.spind = spiral[SIZE + ts.x - tx][SIZE + ts.y - ty];
					added.push_back(ts);
				}
				sti = -1;

				sort(added.begin(), added.end());
				for (int i = 0; i<added.size(); i++) {
					Ef("  + (X%d Y%d C%d [%d])\n", added[i].x, added[i].y, added[i].col, added[i].spind);
					qarr[qs++] = added[i];
				}
			}

			cnode.erase(tcc);
			cnode[tcol] = nk;

			nodes[nk].father = nodes[ai].father = nodes[ni].father = nk;
			nodes[nk].pop = nodes[ai].pop + nodes[ni].pop;
			nodes[nk].color = tcol;
			nodes[nk].stind = nodes[ai].stind;
			nk++;
		}
	}

	printf("%I64d\n", ans);
	return 0;
}