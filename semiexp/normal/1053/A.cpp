#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define MOD @
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

i64 A, B, K;

int main()
{
	scanf("%lld%lld%lld", &A, &B, &K);

	i64 S = A * B * 2;
	if (S % K != 0 || K == 1) {
		puts("NO");
		return 0;
	}
	S /= K;

	puts("YES");
	if (S % B == 0) {
		printf("%d %d\n", 0LL, 0LL);
		printf("%lld %lld\n", 0LL, B);
		printf("%lld %lld\n", S / B, 0LL);
		return 0;
	}
	i64 p = A;
	i64 q = S / A;
	i64 r = S % A;
	i64 s = q + 1;
	printf("%lld %lld\n", 0LL, q);
	printf("%lld %lld\n", r, 0LL);
	printf("%lld %lld\n", p, s);

	return 0;
}