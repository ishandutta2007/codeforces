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
#define MOD
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

int N, T, A[303];

int P[303][303], Q[303][303];

int dp[303];

int main()
{
	scanf("%d%d", &N, &T);
	for (int i = 0; i < N; ++i) scanf("%d", A + i);

	vector<int> Ns;
	for (int i = 0; i < N; ++i) Ns.push_back(A[i]);
	sort(Ns.begin(), Ns.end());
	Ns.erase(unique(Ns.begin(), Ns.end()), Ns.end());
	for (int i = 0; i < N; ++i) A[i] = lower_bound(Ns.begin(), Ns.end(), A[i]) - Ns.begin();

	vector<int> seq;
	for (int i = 0; i <= N; ++i) {
		for (int j = 0; j < N; ++j) {
			seq.push_back(A[j]);
			P[i][j] = Q[i][j] = 0;
		}
	}
	for (int i = 0; i < N; ++i) dp[i] = 0;
	for (int i = 0; i < seq.size(); ++i) {
		int v = 0;
		for (int j = 0; j <= seq[i]; ++j) v = max(v, dp[j]);
		v += 1;
		P[i / N + 1][seq[i]] = max(P[i / N][seq[i]], v);
		dp[seq[i]] = max(dp[seq[i]], v);
	}
	reverse(seq.begin(), seq.end());
	for (int i = 0; i < N; ++i) dp[i] = 0;
	for (int i = 0; i < seq.size(); ++i) {
		int v = 0;
		for (int j = seq[i]; j < N; ++j) v = max(v, dp[j]);
		v += 1;
		Q[i / N + 1][seq[i]] = max(Q[i / N][seq[i]], v);
		dp[seq[i]] = max(dp[seq[i]], v);
	}

	for (int i = 0; i <= N; ++i) {
		for (int j = 1; j < N; ++j) P[i][j] = max(P[i][j], P[i][j - 1]);
		for (int j = N - 2; j >= 0; --j) Q[i][j] = max(Q[i][j], Q[i][j + 1]);
	//	for (int j = 0; j < N; ++j) printf("%d/%d ", P[i][j], Q[i][j]);
	//	puts("");
	}

	int ret = 0;
	for (int i = 0; i < N; ++i) {
		int rc = 0;
		for (int j = 0; j < N; ++j) if (A[j] == i) ++rc;

		for (int j = 0; j <= N; ++j) {
			for (int k = 0; k <= N; ++k) if (j + k <= T) {
		//		printf("%d %d %d: %d %d %d\n", i, j, k, rc * (T - j - k) + P[j][i] + Q[k][i], P[j][i], Q[k][i]);
				ret = max(ret, rc * (T - j - k) + P[j][i] + Q[k][i]);
			}
		}
	}
	printf("%d\n", ret);
	return 0;
}