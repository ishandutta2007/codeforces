#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr ll MOD = 998244353;
constexpr int NMAX = 501;

ll cts[NMAX][NMAX];
int colors[NMAX];

ll getCount(int i, int j) {
	if (j - i < 1) return 1;
	else if (cts[i][j] != -1) return cts[i][j];
	int firstShade = i;
	for (int k = i + 1; k <= j; ++k) {
		if (colors[k] < colors[firstShade]) {
			firstShade = k;
		}
	}
	ll lhans = 0;
	for (int lhst = i; lhst <= firstShade; ++lhst) {
		lhans = (lhans + getCount(i, lhst - 1) * getCount(lhst, firstShade - 1) % MOD) % MOD;	
	}
	ll rhans = 0;
	for (int rhst = j; rhst >= firstShade; --rhst) {
		rhans = (rhans + getCount(firstShade + 1, rhst) * getCount(rhst + 1, j) % MOD) % MOD;
	}
	return (cts[i][j] = lhans * rhans % MOD);
}

int main() {
	memset(cts, -1, sizeof cts);
	int n, m; scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d", &colors[i]);
	}
	printf("%lld\n", getCount(0, n-1));
	return 0;
}