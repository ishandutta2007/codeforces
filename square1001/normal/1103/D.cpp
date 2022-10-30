#include <cstdio>
#include <vector>
#include <algorithm>
#include <unordered_map>
#pragma warning(disable : 4996)
using namespace std;
const long long inf = 1LL << 62;
long long gcd(long long a, long long b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
int N, S, perm[1000009]; long long K, pm[15], A[1000009], E[1000009], mul[2055], cnt[2055], dp[13][2055], ndp[13][2055];
int main() {
	scanf("%d %lld", &N, &K);
	for (int i = 0; i < N; ++i) scanf("%lld", &A[i]);
	for (int i = 0; i < N; ++i) scanf("%lld", &E[i]);
	long long G = A[0];
	for (int i = 1; i < N; ++i) {
		G = gcd(G, A[i]);
	}
	for (int i = 2; (long long)(i) * i <= G; ++i) {
		if (G % i == 0) {
			while(G % i == 0) G /= i;
			pm[S++] = i;
		}
	}
	if (G >= 2) pm[S++] = G;
	for (int i = 0; i < N; ++i) perm[i] = i;
	sort(perm, perm + N, [&](int i, int j) { return E[i] < E[j]; });
	for (int i = 0; i <= S; ++i) {
		for (int j = 0; j < 1 << S; ++j) {
			dp[i][j] = inf;
		}
	}
	unordered_map<long long, int> fastcnt;
	dp[0][0] = 0;
	for (int i = 0; i < N; ++i) {
		++fastcnt[A[perm[i]]];
		if (fastcnt[A[perm[i]]] > S) continue; // fast pruning
		mul[0] = 1;
		for (int j = 0; j < S; ++j) {
			long long mult = 1;
			while (A[perm[i]] % pm[j] == 0) A[perm[i]] /= pm[j], mult *= pm[j];
			for (int k = 1 << j; k < 2 << j; ++k) {
				mul[k] = mul[k - (1 << j)] * mult;
			}
		}
		bool useit = false;
		for (int j = 0; j < 1 << S; ++j) {
			if (mul[j] <= K) {
				++cnt[j];
				if (cnt[j] <= S) useit = true;
			}
		}
		if (useit) {
			for (int j = S - 1; j >= 0; --j) {
				for (int k = 1; k < 1 << S; ++k) {
					if (mul[k] > K) continue;
					for (int l = k; l < 1 << S; l = (l + 1) | k) {
						dp[j + 1][l] = min(dp[j + 1][l], dp[j][l - k] + E[perm[i]]);
					}
				}
			}
		}
	}
	long long ans = inf;
	for (int i = 0; i <= S; ++i) {
		if (dp[i][(1 << S) - 1] != inf) {
			ans = min(ans, dp[i][(1 << S) - 1] * i);
		}
	}
	if (ans == inf) printf("-1\n");
	else printf("%lld\n", ans);
	return 0;
}