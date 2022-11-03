//#pragma comment(linker, "/STACK:20000000")
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

const int SIZE = 320;

int n;
int matr[SIZE][SIZE];
int res[2][SIZE][SIZE];

inline void relax(int &a, int b) {
	a = max(a, b);
}

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%d", &n);
	for (int i = 0; i<n; i++)
		for (int j = 0; j<n; j++)
			scanf("%d", &matr[i][j]);

	memset(res, -63, sizeof(res));
	res[0][0][0] = matr[0][0];
	for (int s = 0; s < 2*n-2; s++) {
		memset(res[(s+1)&1], -63, sizeof(res[0]));
		for (int i = 0; i<=min(s, n-1); i++)
			for (int j = 0; j<=min(s, n-1); j++) {
				int tres = res[s&1][i][j];
				if (tres < -1000000000) continue;
				for (int di = 0; di<2; di++)
					for (int dj = 0; dj<2; dj++) {
						int ni = i + di;
						int na = s+1 - ni;
						int nj = j + dj;
						int nb = s+1 - nj;
						if (ni < 0 || ni >= n || nj < 0 || nj >= n) continue;
						if (na < 0 || na >= n || nb < 0 || nb >= n) continue;
						int nres = tres + matr[ni][na];
						if (ni != nj) nres += matr[nj][nb];
						relax(res[(s+1)&1][ni][nj], nres);
					}
			}
	}

	printf("%d\n", res[(2*n-2)&1][n-1][n-1]);

	return 0;
}