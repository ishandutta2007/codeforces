#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <list>

using namespace std;
typedef long long int64;
#define E(c) fprintf(stderr, #c)

const int MOD = 1000000007;

inline void Add(int &a, int b) {
	a += b;
	if (a >= MOD) a -= MOD;
}

const int SIZE = 1<<20;
int n;
int res[SIZE][2];

int main() {
#ifdef _CRT_SECURE_NO_DEPRECATE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	int ans = 0;
	res[0][0] = 1;
	for (int i = 0; i<n; i++)
		for (int j = 0; j<2; j++) {
//			printf("%d %d: %d\n", i, j, res[i][j]);
			Add(ans, res[i][j]);
			Add(res[i+1][j], res[i][j]);
			if ((i&1) == j)
				Add(res[i+1][!j], res[i][j]);
		}
	printf("%d\n", ans);
	return 0;
}