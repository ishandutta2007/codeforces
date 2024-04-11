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

int N;
i64 A[202020];

i64 modpow(i64 a, int p = MOD - 2)
{
	if (p == 0) return 1;
	i64 tmp = modpow(a, p / 2);
	tmp = tmp * tmp % MOD;
	if (p % 2 == 1) tmp = tmp * a % MOD;
	return tmp;
}

i64 fact[202020], facti[202020];

i64 C(int a, int b)
{
	return fact[a] * facti[b] % MOD * facti[a - b] % MOD;
}

i64 corr(int i)
{
	return C(N / 2 - 1, i / 2);
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) scanf("%lld", A + i);

	fact[0] = facti[0] = 1;
	for (int i = 1; i <= N; ++i) {
		fact[i] = fact[i - 1] * i % MOD;
		facti[i] = modpow(fact[i]);
	}

	i64 ret = 0;
	switch (N % 4) {
	case 0:
		for (int i = 0; i < N; ++i) {
			i64 base = A[i] * C(N / 2 - 1, i / 2) % MOD;
			if (i % 2) base = MOD - base;
			ADD(ret, base);
		}
		break;
	case 1:
		for (int i = 0; i < N; ++i) if (i % 2 == 0) {
			i64 base = A[i] * C(N / 2, i / 2);
			ADD(ret, base);
		}
		break;
	case 2:
		for (int i = 0; i < N; ++i) {
			i64 base = A[i] * C(N / 2 - 1, i / 2);
			ADD(ret, base);
		}
		break;
	case 3:
		for (int i = 0; i < N; ++i) {
			i64 co = 0;
			if (i != N - 1) ADD(co, corr(i));
			if (i > 0) {
				if (i % 2 == 0) ADD(co, MOD - corr(i - 1));
				else ADD(co, corr(i - 1));
			}
			i64 base = A[i] * co;
			ADD(ret, base);
		}
		break;
	}
	printf("%lld\n", ret);
	return 0;
}