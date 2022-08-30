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

int N, C[101];

i64 gcd(i64 a, i64 b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}
i64 lcm(i64 a, i64 b)
{
	return a / gcd(a, b) * b;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%d", C + i);
		--C[i];
	}
	i64 ans = 1;
	for (int i = 0; i < N; ++i) {
		int len = 0;
		int p = i;
		for (;;) {
			p = C[p];
			++len;
			if (p == i) break;
			if (len > N) {
				puts("-1");
				return 0;
			}
		}
		ans = lcm(ans, len % 2 == 0 ? (len / 2) : len);
	}
	printf("%lld\n", ans);
	return 0;
}