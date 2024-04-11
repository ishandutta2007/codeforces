#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define MOD
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

int N, A[100], Abas[100];

int primes[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53 };
vector<int> valids[1<<16];
int masks[60];
int dp[101][1 << 16], from[100][1 << 16];

int Mabs(int p) { return max(p, -p); }

int main()
{
	int sz = 0;
	for (int j = 1; j <= 58; j++){
		masks[j] = 0;
		for (int k = 0; k < 16; k++) if (j % primes[k] == 0) masks[j] |= 1 << k;
	}
	for (int i = 0; i < (1 << 16); i++) {
		for (int j = 1; j <= 58; j++) {
			bool flg = false;
			for (int k = 0; k < 16; k++) if (j % primes[k] == 0 && (i & (1<<k))) flg = true;

			if (!flg) valids[i].push_back(j);
		}
		sz += valids[i].size();
	}

	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", A + i);
	for (int i = 0; i < N; i++) Abas[i] = A[i];

	for (int i = 0; i < (1 << 16); i++) dp[0][i] = 1000000;
	dp[0][0] = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < (1 << 16); j++){
			dp[i + 1][j] = 1000000;
			from[i + 1][j] = -1;
		}
		for (int j = 0; j < (1 << 16); j++){
			for (int k : valids[j]) {
				int tmp = dp[i][j] + Mabs(A[i] - k);

				if (dp[i + 1][j | masks[k]] > tmp) {
					dp[i + 1][j | masks[k]] = tmp;
					from[i + 1][j | masks[k]] = k;
				}
			}
		}
	}

	vector<int> ret;
	pair<int, int> bp = make_pair(10000000, 0);
	for (int i = 0; i < (1 << 16); i++) bp = min(bp, make_pair(dp[N][i], i));

	int ps = bp.second;
	for (int i = N; i > 0; i--) {
		ret.push_back(from[i][ps]);
		ps ^= masks[from[i][ps]];
	}
	reverse(ret.begin(), ret.end());

	printf("%d", ret[0]);
	for (int i = 1; i < ret.size(); i++) printf(" %d", ret[i]);
	puts("");
	return 0;
}