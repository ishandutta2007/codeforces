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

const int SIZE = 512;

int n, m;
int matr[SIZE][SIZE];
int sqsum[SIZE][SIZE];
int spiral[SIZE][SIZE];

int SumSquare(int x1, int y1, int x2, int y2) {
	return sqsum[x2][y2] - sqsum[x1][y2] - sqsum[x2][y1] + sqsum[x1][y1];
}

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%d%d", &n, &m);
	for (int i = 0; i<n; i++)
		for (int j = 0; j<m; j++)
			scanf("%d", &matr[i][j]);

	for (int i = 0; i<=n; i++)
		for (int j = 0; j<=m; j++) {
			if (!i || !j) sqsum[i][j] = 0;
			else sqsum[i][j] = sqsum[i-1][j] + sqsum[i][j-1] - sqsum[i-1][j-1] + matr[i-1][j-1];
		}

	int ans = -1000000000;

	memcpy(spiral, matr, sizeof(matr));
	for (int k = 3; k<=n && k<=m; k+=2) {
		for (int i = 0; i<n; i++)
			for (int j = 0; j<m; j++) {
				int r = k / 2;
				int li = i - r;
				int ri = i + r;
				int lj = j - r;
				int rj = j + r;
				if (li < 0 || lj < 0 || ri >= n || rj >= m) continue;

				int tres = -spiral[i][j] + SumSquare(li, lj, ri+1, rj+1);
				tres -= matr[li+1][lj];
				if (ans < tres) ans = tres;

				spiral[i][j] = tres;
			}
	}

	printf("%d\n", ans);

	return 0;
}