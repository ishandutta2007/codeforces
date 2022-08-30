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
i64 K, A[101010];

int main()
{
	scanf("%d%lld", &N, &K);
	for (int i = 0; i < N; ++i) scanf("%lld", A + i);
	i64 lo = A[0];
	for (int i = 0; i < N; ++i) lo = min(lo, A[i]);

	i64 ans = 0;
	for (int i = 0; i < N; ++i) {
		i64 d = A[i] - lo;
		if (d % K != 0) {
			puts("-1");
			return 0;
		}
		ans += d / K;
	}
	printf("%lld\n", ans);
	return 0;
}