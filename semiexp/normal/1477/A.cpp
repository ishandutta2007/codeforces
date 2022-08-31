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

int T;
int N;
i64 K, X[202020];

i64 mygcd(i64 x, i64 y) {
	while (y) {
		i64 tmp = x % y;
		x = y;
		y = tmp;
	}
	return x;
}

int main()
{
	scanf("%d", &T);
	for (;T--;) {
		scanf("%d%lld", &N, &K);
		for (int i = 0; i < N; ++i) scanf("%lld", X + i);
		sort(X, X + N);

		i64 g = X[1] - X[0];
		for (int i = 2; i < N; ++i) g = mygcd(g, X[i] - X[i - 1]);

		puts((K - X[0]) % g == 0 ? "YES" : "NO");
	}
	return 0;
}