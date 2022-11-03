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

const int SIZE = 1024;
const int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int n, m;
char matr[SIZE][SIZE];

int dist[SIZE][SIZE][4];
int qarr[4*SIZE*SIZE][3];
int qs;

bool good(int x, int y) {
	return x>=0 && x < n && y>=0 && y < m;
}

void DFS(int x, int y, int d, int dst) {
	if (!good(x, y)) return;
	if (dist[x][y][d] < 1000000000) return;
	dist[x][y][d] = dst;
	qarr[qs][0] = x;
	qarr[qs][1] = y;
	qarr[qs][2] = d;
	qs++;
	DFS(x + dir[d][0], y + dir[d][1], d, dst);
}

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%d%d", &n, &m);
	for (int i = 0; i<n; i++) scanf("%s", matr[i]);

	memset(dist, 63, sizeof(dist));
	DFS(0, 0, 0, 0);
	for (int i = 0; i<qs; i++) {
		int x = qarr[i][0];
		int y = qarr[i][1];
		int d = qarr[i][2];
		if (matr[x][y] == '.') continue;

        for (int nd = 0; nd<4; nd++) {
        	int ndist = dist[x][y][d] + 1;
			if (dist[x][y][nd] > ndist)
				DFS(x, y, nd, ndist);
        }
	}

	int ans = dist[n-1][m-1][0];
	if (ans > 1000000000) ans = -1;
	printf("%d\n", ans);
                       	
	return 0;
}