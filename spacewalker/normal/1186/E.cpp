#include <bits/stdc++.h>
#define int ll

using namespace std;
using ll = long long;
constexpr int NMAX = 1010;
constexpr int WIDTH_MAX = 35;

char grid[NMAX][NMAX];

int corSum[NMAX][NMAX];
int n, m; 

ll seqCountFlat(int i, int maxLen, bool ones) {
	if (i < 0) return 0;
	if (maxLen == 0) return (ones ? 0 : 1);
	else if (maxLen == 1) {
		if (i == 1) return 1;
		else return (ones ? 0 : 1);
	}
	else if (i < (1LL << (maxLen - 1))) return (seqCountFlat(i, maxLen - 1, ones));
	else return (1LL << (maxLen - 2)) + seqCountFlat(i - (1LL << (maxLen - 1)), maxLen - 1, !ones);
}

int getElement(int i) {
	return seqCountFlat(i, WIDTH_MAX, true) - seqCountFlat(i - 1, WIDTH_MAX, true);
}

ll seqCount2D(int rows, int cols, bool ones) {
	if (rows < 0 || cols < 0) return 0;
	ll rowStartZero = seqCountFlat(rows, WIDTH_MAX, false);
	ll rowStartOne = rows - rowStartZero + 1;
	ll colAmongOnes = seqCountFlat(cols, WIDTH_MAX, true);
	ll colAmongZeroes = cols - colAmongOnes + 1;
	ll ans = rowStartZero * colAmongOnes + rowStartOne * colAmongZeroes;
	if (!ones) ans = (rows + 1) * (ll)(cols + 1) - ans;
	return ans;
}

ll seqCountSubrect(int i1, int j1, int i2, int j2, bool ones) {
	return seqCount2D(i2, j2, ones) - seqCount2D(i1-1, j2, ones) - seqCount2D(i2, j1 - 1, ones) + seqCount2D(i1-1, j1-1, ones);
}

int gridSum(int i, int j, bool isOne) {
	int ans = corSum[i + 1][j + 1];
	if (!isOne) ans = ((i + 1) * (j + 1)) - ans;
	return ans;
}

ll solveSum(int x, int y) {
	if (x == 0 || y == 0) return 0;
	--x; --y;
	int bigRow = x / n, bigCol = y / m;
	int smallRow = x % n, smallCol = y % m;
	ll fullGridInverted = seqCountSubrect(0, 0, bigRow - 1, bigCol - 1, true);
	ll fullGridNormal = (bigRow) * (bigCol) - fullGridInverted;
	ll fullRowInverted = seqCountSubrect(bigRow, 0, bigRow, bigCol - 1, true);
	ll fullRowNormal = bigCol - fullRowInverted;
	ll fullColInverted = seqCountSubrect(0, bigCol, bigRow - 1, bigCol, true);
	ll fullColNormal = bigRow - fullColInverted;
	fullGridInverted *= gridSum(n - 1, m - 1, false);
	fullGridNormal *= gridSum(n - 1, m - 1, true);
	fullRowInverted *= gridSum(smallRow, m - 1, false); 
	fullRowNormal *= gridSum(smallRow, m - 1, true);
	fullColInverted *= gridSum(n - 1, smallCol, false);
	fullColNormal *= gridSum(n - 1, smallCol, true);
	return (fullGridInverted + fullGridNormal + fullRowInverted + fullRowNormal + fullColInverted + fullColNormal
			+ gridSum(smallRow, smallCol, (getElement(bigRow) + getElement(bigCol)) % 2 == 0));
}

signed main() {
	int q; scanf("%lld %lld %lld", &n, &m, &q);
	for (int i = 0; i < n; ++i) scanf("%s", grid[i]);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			corSum[i][j] = corSum[i-1][j] + corSum[i][j-1] - corSum[i-1][j-1]
				+ (grid[i-1][j-1] == '1' ? 1 : 0);
		}
	}
	for (int qta = 0; qta < q; ++qta) {
		ll x1, x2, y1, y2; scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
		printf("%lld\n", solveSum(x2, y2) - solveSum(x1 - 1, y2) - solveSum(x2, y1 - 1) + solveSum(x1 - 1, y1 - 1));
	}
	return 0;
}