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
#include <random>

using namespace std;
#define MOD
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

const bool MOCK = false;
const bool MOCK_RANDOM = true;

const i64 MMAX = 100000000000000LL;

int TC;
mt19937 rng(42);

// M in [lb, rb]
i64 lb, rb, balance;
i64 mock_m;
int ask_count;

bool ask(i64 X) {
	++ask_count;
	if (MOCK) {
		if (X > mock_m) {
			balance -= X;
			return false;
		} else {
			balance += X;
			return true;
		}
	} else {
		printf("? %lld\n", X);
		fflush(stdout);
		char buf[20];
		scanf("%s", buf);

		if (buf[0] == 'L') {
			balance += X;
			return true;
		} else {
			if (buf[1] == 'i') {
				throw 5;
			}
			balance -= X;
			return false;
		}
	}
}

i64 dp[110][110];  // num query, 

int main()
{
	for (int i = 0; i <= 105; ++i) dp[0][i] = 1;
	for (int i = 1; i <= 105; ++i) {
		for (int j = 0; j <= 105; ++j) {
			if (j == 0) dp[i][j] = dp[i - 1][j + 1];
			else {
				dp[i][j] = min(MMAX, dp[i - 1][j + 1] + dp[i - 1][j - 1]);
			}
		}
		// printf("%d: %lld\n", i, dp[i][0]);
	}
	scanf("%d", &TC);
	for (;TC--;) {
		if (MOCK) {
			if (MOCK_RANDOM) {
				mock_m = uniform_int_distribution<i64>(1, MMAX)(rng);
				// mock_m = 42999120584191;
				// mock_m = TC + 1;
				// mock_m = 8191;
			} else {
				scanf("%lld", &mock_m);
			}
		}
		lb = 0;
		rb = MMAX;
		ask_count = 0;
		balance = 1;

		if (!ask(1)) {
			puts("! 0");
			fflush(stdout);
			continue;
		}
		lb = 1;
		while (lb * 2 < rb) {
			if (ask(lb * 2)) {
				lb *= 2;
			} else {
				rb = lb * 2 - 1;
			}
		}
		if (balance == 0) {
			ask(lb);
		}
		int advantage = 0;
		int arem = 1000;
		while (lb < rb) {
			int rem = 105 - ask_count;
			rem = min(rem, arem);
			if (advantage == 0) {
				--rem;
				advantage = 1;
			}
			if (rem <= 0) {
				// fprintf(stderr, "sadparrot %lld %lld %lld\n", mock_m, lb, rb);
				throw 2;
				return 0;
			}
			i64 nxt;
			do {
				nxt = lb + dp[rem - 1][advantage - 1];
			} while (nxt > rb && --rem >= 1);
			nxt = max(nxt, lb + 1);
			// printf("[%d] %lld %lld %d -> %lld (%lld / %lld)\n", rem, lb, rb, advantage, nxt, nxt - lb, rb - lb);
			while (balance < nxt) {
				ask(lb);
				// puts("charge");
			}
			arem = rem - 1;
			// printf("%lld %lld -> %lld\n", lb, rb, nxt);
			if (ask(nxt)) {
				lb = nxt;
				++advantage;
			} else {
				rb = nxt - 1;
				--advantage;
			}
		}
		if (MOCK) {
			// fprintf(stderr, "cost: %d\n", ask_count);
			if (lb != mock_m) throw 2;
			if (ask_count > 105) {
				// fprintf(stderr, "fail: %lld (%d)\n", mock_m, ask_count);
				throw 3;
			}
			if (!MOCK_RANDOM) puts("ok");
		} else {
			printf("! %lld\n", lb);
			fflush(stdout);
		}
	}
	// fprintf(stderr, "finish\n");
	return 0;
}