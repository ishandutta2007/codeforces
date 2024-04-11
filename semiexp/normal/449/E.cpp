#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cmath>
#include <cstring>
using namespace std;
#define MOD 1000000007
#define ADD(X, Y) ((X) = ((X) + (Y)) % MOD)
typedef long long i64;

int N, M;
i64 tblX[1001001];
int minp[1001001];
i64 gs[1001001];
i64 bsum[1001001];

i64 bsums0[1001001];
i64 bsums1[1001001];
i64 bsums2[1001001];

i64 linsum(i64 K)
{
	i64 P = K, Q = K+1;
	if(P%2==0) P /= 2;
	else Q /= 2;

	return (P * Q) % MOD;
}

i64 sqrsum(i64 K)
{
	i64 ret = K;
	ret = ret * (K+1) % MOD;
	ret = ret * ((2*K+1) % MOD) % MOD;

	return ret * ((MOD + 1) / 6) % MOD;
}

void erat()
{
	for(int i=0;i<=1000000;i++) minp[i] = -1;
	for(int i=2;i<=1000000;i++) if(minp[i] == -1) {
		for(int j=i;j<=1000000;j+=i) if(minp[j] == -1) minp[j] = i;
	}
}

i64 gcd(i64 a, i64 b)
{
	return b == 0 ? a : gcd(b, a % b);
}

i64 count(i64 a, i64 b)
{
	if(min(N, M) <= a + b - 1) return 0;
	i64 pat = (i64)(N - (a + b - 1)) * (M - (a + b - 1)) % MOD;

	i64 ec = a*a + b*b - 2*(a+b) + 2*gcd(a, b);
	ec %= MOD;

	return pat * ec % MOD;
}

void calc_gs()
{
	gs[1] = 1;
	for(int i=2;i<=1000000;i++) {
		int p = i, q = i;
		i64 aux = 0;
		int ord = 0;
		while(q % minp[i] == 0) {
			++ord;
			q /= minp[i];
		}

		i64 pow = 1;
		for(int j=0;j<ord-1;j++) pow = (pow * minp[i]);
		aux += pow * minp[i];
		aux += pow * (minp[i]-1) * ord;
		aux %= MOD;

		aux = aux * gs[q] % MOD;
		gs[i] = aux;

	}
}

void calc_bsum()
{
	bsum[0] = 0;
	for(int i=1;i<=1000000;i++) {
		i64 tmp = sqrsum(i) + sqrsum(i-1) + 2 * MOD - (2 * i * (i64)i % MOD) + 2 * gs[i];
		bsum[i] = tmp % MOD;
	}
}

void totalize()
{
	bsums0[0] = bsums1[0] = bsums2[0] = 0;
	for(int i=1;i<=1000000;i++) {
		bsums0[i] = (bsums0[i-1] + bsum[i]) % MOD;
		bsums1[i] = (bsums1[i-1] + bsum[i] * i % MOD) % MOD;
		bsums2[i] = (bsums2[i-1] + bsum[i] * i % MOD * i % MOD) % MOD;
	}
}

int main()
{
	erat();
	calc_gs();
	calc_bsum();
	totalize();

	int T;
	scanf("%d", &T);

	for(int i=0;i<T;i++) {
		scanf("%d%d", &N, &M);

		if(N > M) swap(N, M);

		i64 ret = (i64)(N+1) * (M+1) % MOD * bsums0[N];
		ret += MOD - ((i64)(N+M+2) * bsums1[N] % MOD);
		ret += bsums2[N];
		ret %= MOD;

		printf("%d\n", (int) ret);
	}

	return 0;
}