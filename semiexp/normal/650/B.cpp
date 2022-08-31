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

int N, A, B;
i64 T;
char S[505050];

i64 lf[505050], rg[505050];

int main()
{
	scanf("%d%d%d%lld%s", &N, &A, &B, &T, S);

	T -= 1 + (S[0] == 'w' ? B : 0);
	if (T < 0) {
		puts("0");
		return 0;
	}

	rg[0] = 0;
	for (int i = 1; i < N; ++i) {
		rg[i] = rg[i - 1] + A + 1 + (S[i] == 'w' ? B : 0);
	}
	rg[N] = rg[N - 1] + T + 10;
	lf[0] = 0;
	for (int i = 1; i < N; ++i) {
		lf[i] = lf[i - 1] + A + 1 + (S[N - i] == 'w' ? B : 0);
	}
	lf[N] = lf[N - 1] + T + 10;

	int ret = 0;
	for (int i = 0; i < N; ++i) {
	//	printf("%lld %lld\n", lf[i], rg[i]);
		if (T - rg[i] >= 0) ret = max(ret, i);
		i64 lal = T - rg[i] - (i64)A * i;
		if (lal < 0) continue;
		int cn = upper_bound(lf, lf + N, lal) - lf - 1;
		ret = max(ret, i + cn);
	}
	for (int i = 0; i < N; ++i) {
		if (T - lf[i] >= 0) ret = max(ret, i);
		i64 lal = T - lf[i] - (i64)A * i;
		if (lal < 0) continue;
		int cn = upper_bound(rg, rg + N, lal) - rg - 1;
		ret = max(ret, i + cn);
	}
	ret += 1;
	ret = min(ret, N);
	printf("%d\n", ret);
	return 0;
}