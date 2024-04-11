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

i64 mygcd(i64 a, i64 b) {
	while (b) {
		i64 tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}

int TC;
int N; i64 A[202020];
i64 D[202020];
i64 jump[18][202020];

int main()
{
	scanf("%d", &TC);
	for (;TC--;) {
		scanf("%d", &N);
		for (int i = 0; i < N; ++i) scanf("%lld", A + i);

		for (int i = 0; i < N - 1; ++i) {
			D[i] = A[i + 1] - A[i];
			if (D[i] < 0) D[i] = -D[i];
		}
		--N;

		for (int i = 0; i < N; ++i) jump[0][i] = D[i];
		for (int d = 1; d < 18; ++d) {
			for (int i = 0; i < N; ++i) {
				int i2 = i + (1 << (d - 1));
				if (i2 >= N) jump[d][i] = 1;
				else jump[d][i] = mygcd(jump[d - 1][i], jump[d - 1][i2]);
			}
		}

		int ret = 0;
		for (int i = 0; i < N; ++i) {
			int r = i;
			i64 g = D[i];
			for (int d = 17; d >= 0; --d) {
				if (r >= N) break;
				i64 g2 = mygcd(g, jump[d][r]);
				if (g2 > 1) {
					g = g2;
					r += (1 << d);
				}
			}
			ret = max(ret, r - i);
		}

		printf("%d\n", ret + 1);
	}
	return 0;
}