#pragma comment(linker, "/STACK:20000000")
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

const int NUM = 2048;
const int LEN = 512;
const int VERTS = NUM * LEN;
const int TVERTS = 2*NUM;
const int CHARS = 'z' - 'a' + 1;

int n, k;

int v;
int move[VERTS][CHARS];
int cnt[VERTS];

struct Edge {
	int son;
	int len;
};
int t;
int tcnt[TVERTS];
vector<Edge> edges[TVERTS];

void DFS(int u, int key, int len) {
	int deg = 0;
	for (int c = 0; c<CHARS; c++)
		deg += (move[u][c] >= 0);

	bool imp = (deg != 1 || u == 0 || cnt[u]);

	int currkey = -1;
	if (imp) {
		currkey = t++;
		tcnt[currkey] = cnt[u];
		if (u > 0) {
			Edge e;
			e.son = currkey;
			e.len = len;
			edges[key].push_back(e);
		}
	}

	for (int c = 0; c<CHARS; c++) {
		int s = move[u][c];
		if (s < 0) continue;
		
		if (!imp) DFS(s, key, len+1);
		else DFS(s, currkey, 1);
	}
}

void Merge(int *res, const int *a, const int *b, int hgt) {
	int as, bs;
	for (as = 0; a[as]>=0; as++);
	for (bs = 0; b[bs]>=0; bs++);

	for (int i = 0; i<as; i++) {
		int deltacurr = 0;
		int deltastep = i * hgt;
		int upj = min(bs, k-i+1);
		for (int j = 0; j<upj; j++) {
			int tres = a[i] + b[j] + deltacurr;
			res[i+j] = max(res[i+j], tres);
			deltacurr += deltastep;
		}
	}
}

int res[TVERTS][NUM];

int buff[NUM];
void Solve(int u, int hgt) {
	for (int i = 0; i<edges[u].size(); i++) {
		const Edge &e = edges[u][i];
		Solve(e.son, hgt + e.len);
	}
	
	memset(buff, -63, sizeof(buff));
	int cc = tcnt[u];
	for (int i = 0; i<=cc; i++)
		buff[i] = (i * (i-1)) / 2 * hgt;

	int *arr[2] = {buff, res[u]};
	for (int i = 0; i<edges[u].size(); i++) {
		const Edge &e = edges[u][i];

		memset(arr[1], -63, sizeof(buff));
		Merge(arr[1], arr[0], res[e.son], hgt);
		swap(arr[0], arr[1]);
	}
	
	if (arr[0] != res[u])
		memcpy(res[u], arr[0], sizeof(buff));
}

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%d%d", &n, &k);

	int v = 1;
	memset(move, -1, sizeof(move));

	for (int i = 0; i<n; i++) {
		char buff[LEN];
		scanf("%s", buff);

		int curr = 0;
		for (int j = 0; buff[j]; j++) {
			int q = buff[j] - 'a';
			if (move[curr][q] < 0)
				move[curr][q] = v++;
			curr = move[curr][q];
		}
		cnt[curr]++;
	}

	t = 0;
	DFS(0, -1, -1);

/*	for (int i = 0; i<t; i++) {
		printf("(%d) [%d] : ", i, tcnt[i]);
		for (int j = 0; j<edges[i].size(); j++)
			printf(" <%d;%d>", edges[i][j].son, edges[i][j].len);
		printf("\n");
	}*/

	Solve(0, 0);

/*	for (int u = 0; u<t; u++) {
		printf("%d : ", u);
		for (int i = 0; res[u][i] >= 0; i++)
			printf(" (%d->%d)", i, res[u][i]);
		printf("\n");
	}*/

	printf("%d\n", res[0][k]);
	return 0;
}