#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr ll MOD = 1000000007;
constexpr int NMAX = 500010;

char s[NMAX], t[NMAX], ans[NMAX];
ll basePow[NMAX];
int occInS[2];

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<int> distrib(1, MOD - 1);

void outputAnswer() {
	printf("%s", ans);
	for (int j = 0; j < 2; ++j) {
		for (int i = 0; i < occInS[j]; ++i) printf("%c", j + '0');
	}
	printf("\n");
	exit(0);
}

int main() {
	scanf("%s", s);
	scanf("%s", t);
	ll HASH_BASE = distrib(rng);
	basePow[0] = 1;
	for (int i = 1; i < NMAX; ++i) basePow[i] = (basePow[i - 1] * HASH_BASE) % MOD;
	int n = strlen(t);
	vector<ll> prefixHashes(n), suffixHashes(n);
	prefixHashes[0] = t[0];
	for (int i = 1; i < n; ++i) {
		prefixHashes[i] = (prefixHashes[i - 1] + t[i] * basePow[i]) % MOD;
	}
	suffixHashes[n - 1] = t[n - 1];
	for (int i = n - 2; i >= 0; --i) {
		suffixHashes[i] = (suffixHashes[i + 1] * HASH_BASE + t[i]) % MOD;
	}
	int equalPoint = 0;
	for (int i = n - 2; i >= 0; --i) {
		if (prefixHashes[i] == suffixHashes[n - i - 1]) {
			equalPoint = i + 1;
			break;
		}
	}
	for (int i = 0; s[i]; ++i) {
		occInS[s[i] - '0']++;
	}
	// try to place one copy of t
	for (int i = 0; i < n; ++i) {
//		printf("s has %d %d\n", occInS[0], occInS[1]);
		if (occInS[t[i] - '0'] > 0) {
			--occInS[t[i] - '0'];
			ans[i] = t[i];
		} else {
			outputAnswer();
		}
	}
	int curIndex = n;
	// keep attempting to place the suffix [equalPoint:]
	while (true) {
		for (int i = equalPoint; i < n; ++i) {
//			printf("s has %d %d\n", occInS[0], occInS[1]);
			if (occInS[t[i] - '0'] > 0) {
				--occInS[t[i] - '0'];
//				printf("placing character t[%d] = %c in %d\n", i, t[i], curIndex);
				ans[curIndex++] = t[i];
//				printf("%s\n", ans);
			} else {
				outputAnswer();
			}
		}
	}
	return 0;
}