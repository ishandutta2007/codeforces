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

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}

int N, A[202020];
i64 ret;
int gtbl[202020];

int grp[202020];
int oklen[202020];
int appc[202020];

void solve(int g)
{
	for (int i = 0; i < g; ++i) grp[i] = -1;
	for (int i = 0; i < N; ++i) grp[i % g] = max(grp[i % g], A[i]);

	bool isall = true;
	for (int i = 0; i < N; ++i) {
		if (grp[i % g] == A[i]) oklen[i] = 1;
		else oklen[i] = 0;
		if (oklen[i] == 0) isall = false;
	}

	if (isall) {
		for (int i = 0; i < N; ++i) oklen[i] = N;
	} else {
		for (int i = N - 1; i >= 0; --i) {
			if (oklen[i] > 0) oklen[i] = 1 + oklen[(i + 1) % N];
		}
		for (int i = N - 1; i >= 0; --i) {
			if (oklen[i] > 0) oklen[i] = 1 + oklen[(i + 1) % N];
		}
	}

	appc[0] = 0;
	for (int i = 1; i <= N; ++i) appc[i] = (gtbl[i] == g ? 1 : 0) + appc[i - 1];

	for (int i = 0; i < N; ++i) ret += appc[oklen[i]];
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) scanf("%d", A + i);

	for (int i = 1; i < N; ++i) gtbl[i] = gcd(i, N);
	gtbl[N] = -1;

	ret = 0;
	for (int i = 1; i < N; ++i) if (N % i == 0) {
		solve(i);
	}
	printf("%lld\n", ret);

	return 0;
}