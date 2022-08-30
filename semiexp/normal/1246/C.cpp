#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define MOD 1000000007
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

int H, W;
char S[2020][2020];
int rockD[2020][2020], rockR[2020][2020];
int nxtD[2020][2020], nxtR[2020][2020];

int main()
{
	scanf("%d%d", &H, &W);
	for (int i = 0; i < H; ++i) scanf("%s", S[i]);

	if (H == 1 && W == 1) {
		puts("1");
		return 0;
	}

	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			rockD[i][j] = rockR[i][j] = (S[i][j] == 'R' ? 1 : 0);
		}
	}
	for (int i = 0; i < H; ++i) {
		for (int j = W - 2; j >= 0; --j) rockR[i][j] += rockR[i][j + 1];
	}
	for (int i = H - 2; i >= 0; --i) {
		for (int j = 0; j < W; ++j) rockD[i][j] += rockD[i + 1][j];
	}

	for (int i = H - 1; i >= 0; --i) {
		for (int j = W - 1; j >= 0; --j) {
			if (i == H - 1 && j == W - 1) {
				nxtD[i][j] = nxtR[i][j] = 1;
				continue;
			}
			// compute nxtD
			int dlim = H - 1 - rockD[i + 1][j];
			nxtD[i][j] = (nxtR[i + 1][j] - nxtR[dlim + 1][j] + MOD) % MOD;

			// compute nxtR
			int rlim = W - 1 - rockR[i][j + 1];
			nxtR[i][j] = (nxtD[i][j + 1] - nxtD[i][rlim + 1] + MOD) % MOD;

			//printf("%d %d: %d %d\n", i, j, nxtD[i][j], nxtR[i][j]);

			if (!(i == 0 && j == 0)) {
				ADD(nxtD[i][j], nxtD[i][j + 1]);
				ADD(nxtR[i][j], nxtR[i + 1][j]);
			}
		}
	}
	int ans = (nxtD[0][0] + nxtR[0][0]) % MOD;
	printf("%d\n", ans);
	return 0;
}