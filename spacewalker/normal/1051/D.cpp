#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
constexpr int MOD = 998244353;

// each col is in 4 states:
// BB, WW, BW, WB
// BB -> WW BW WB + 1, BB +0
// WW -> BB WB BW + 1, WW +0
// BW -> WB + 2, BB WW BW +0
// WB -> BW + 2, BB WW WB +0
// f(n, k) is computed for each of these 4 accdg to the answer
// base cases: bb(1, 1), ww(1, 1) = 1
// bw(1, 2), wb(1, 2) = 1

// BB = 0
// BW = 1
// WB = 2
// WW = 3

int counts[4][1010][2010];

int getCount(int i, int j, int k) {
	if (j < 0 || k < 0) return 0;
	else return counts[i][j][k];
}

/*
11
10
*/

int main() {
	int n, k; scanf("%d %d", &n, &k);
	counts[0][1][1] = counts[1][1][2] = counts[2][1][2] = counts[3][1][1] = 1;
	for (int i = 2; i <= n; ++i) {
		for (int k = 1; k <= 2*i; ++k) {
			counts[0][i][k] = ((getCount(3, i-1, k-1) + getCount(2, i-1, k)) % MOD
							  + (getCount(0, i-1, k) + getCount(1, i-1, k)) % MOD) % MOD;
			counts[3][i][k] = ((getCount(0, i-1, k-1) + getCount(2, i-1, k)) % MOD
							  + (getCount(1, i-1, k) + getCount(3, i-1, k)) % MOD) % MOD;
			counts[2][i][k] = ((getCount(1, i-1, k-2) + getCount(2, i-1, k)) % MOD
							  + (getCount(3, i-1, k-1) + getCount(0, i-1, k-1)) % MOD) % MOD;
			counts[1][i][k] = ((getCount(2, i-1, k-2) + getCount(0, i-1, k-1)) % MOD
							  + (getCount(1, i-1, k) + getCount(3, i-1, k-1)) % MOD) % MOD;
		}
	}
	printf("%d\n", ((counts[0][n][k] + counts[1][n][k]) % MOD + (counts[2][n][k] + counts[3][n][k]) % MOD) % MOD);
	return 0;
}