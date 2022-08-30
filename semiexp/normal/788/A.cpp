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

int N;
i64 A[101010];
i64 acc[101010];

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) scanf("%lld", A + i);

	i64 ret = 0;
	acc[0] = 0;
	int sgn = 1;
	for (int i = 1; i < N; ++i) {
		acc[i] = acc[i - 1] + abs(A[i] - A[i - 1]) * sgn;
		sgn *= -1;
	}

	i64 lo = 0;
	for (int i = 0; i < N; ++i) {
		if (i % 2 == 0) lo = min(lo, acc[i]);
		ret = max(ret, acc[i] - lo);
	}
	lo = acc[1];
	for (int i = 1; i < N; ++i) {
		if (i % 2 == 1) lo = max(lo, acc[i]);
		ret = max(ret, -(acc[i] - lo));
	}

	printf("%lld\n", ret);

	return 0;
}