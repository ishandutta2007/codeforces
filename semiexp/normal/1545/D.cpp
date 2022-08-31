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

int N, K;
i64 X[1010][1010];

i64 Sum(int t) {
	i64 ret = 0;
	for (int i = 0; i < N; ++i) {
		ret += X[t][i];
	}
	return ret;
}

i64 SumSq(int t) {
	i64 ret = 0;
	for (int i = 0; i < N; ++i) ret += X[t][i] * X[t][i];
	return ret;
}

bool test(int a) {
	i64 vs[4];
	int app = max(a - 3, 0);
	for (int i = 0; i < 4; ++i) vs[i] = SumSq(i + app);
	for (int i = 0; i < 3; ++i) {
		vs[i] = vs[i + 1] - vs[i];
	}
	return vs[1] - vs[0] == vs[2] - vs[1];
}

int main()
{
	scanf("%d%d", &N, &K);
	for (int i = 0; i < K; ++i) {
		for (int j = 0; j < N; ++j) {
			int a;
			scanf("%d", &a);
			X[i][j] = a;
		}
	}
	i64 s0 = Sum(0);
	i64 speed = (Sum(K - 1) - s0) / (K - 1);
	int wt = -1;
	i64 extra;
	for (int i = 1; i < K - 1; ++i) {
		i64 expv = s0 + speed * i;
		if (Sum(i) != expv) {
			wt = i;
			extra = Sum(i) - expv;
		}
	}

	for (int i = 0; i < N; ++i) {
		X[wt][i] -= extra;
		if (test(wt)) {
			printf("%d %lld\n", wt, X[wt][i]);
			break;
		}
		X[wt][i] += extra;
	}

	fflush(stdout);
	return 0;
}