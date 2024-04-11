#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr ll MOD = 1000000007;


ll colorWays[800][800][3][3];
bool stored[800][800][3][3];
char braseq[1000];

// how many ways are there to color braseq[i..j] such that
// pBefore and pAfter are met?
// pBefore   condition of braseq[i-1]
// 0     	 uncolored
// 1 		 colored red
// 2 		 colored blue
// similar for pAfter and braseq[j+1]

bool neighAllowed(int st1, int st2) {
	return !(st1 == st2 && st1 > 0); // no 2 neighboring same color
}

vector<pair<int, int>> matchAllowed = {{1, 0}, {0, 1}, {2, 0}, {0, 2}};

ll colorProc(int i, int j, int pBefore, int pAfter) {
	// printf("CP %d %d %d %d\n", i, j, pBefore, pAfter);
	if (i > j) return 1; // one way to color an empty string: don't
	if (stored[i][j][pBefore][pAfter]) return colorWays[i][j][pBefore][pAfter];
	int iMatch = i, bias = 1;
	ll ans = 0;
	for (int k = i + 1; k <= j; ++k) {
		if (braseq[k] == '(') ++bias;
		else --bias;
		if (bias == 0) {
			iMatch = k;
			break;
		}
	}
	// printf("matching state %d %d %d %d\n", i, j, pBefore, pAfter);
	for (auto matchp : matchAllowed) {
		if (neighAllowed(pBefore, matchp.first) && (!(iMatch == j) || neighAllowed(matchp.second, pAfter))) {
			ans = (ans + colorProc(i + 1, iMatch - 1, matchp.first, matchp.second) * 
				colorProc(iMatch + 1, j, matchp.second, pAfter)) % MOD;
			// printf("att ins %d %d ans %lld at %d %d %d %d\n", matchp.first, matchp.second, ans, i, j, pBefore, pAfter);
		}
	}
	// printf("%d %d %d %d ans %lld\n", i, j, pBefore, pAfter, ans);
	stored[i][j][pBefore][pAfter] = true;
	return colorWays[i][j][pBefore][pAfter] = ans;
}

int main() {
	scanf("%s", braseq);
	printf("%lld\n", colorProc(0, strlen(braseq) - 1, 0, 0));
	return 0;
}