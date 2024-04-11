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

int T;
int N;
i64 X[505050];
int dig[60];

i64 pows[62];

int main()
{
	pows[0] = 1;
	for (int i = 1; i <= 60; ++i) pows[i] = pows[i - 1] * 2 % MOD;

	scanf("%d", &T);
	for (;T--;) {
		scanf("%d", &N);
		for (int i = 0; i < N; ++i) scanf("%lld", X + i);
		for (int i = 0; i < 60; ++i) {
			dig[i] = 0;
		}
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < 60; ++j) {
				if ((X[i] >> j) & 1) ++dig[j];
			}
		}
		i64 ret = 0;
		for (int i = 0; i < N; ++i) {
			i64 lf = 0;
			{
				for (int j = 0; j < 60; ++j) {
					if ((X[i] >> j) & 1) {
						ADD(lf, pows[j] * dig[j]);
					}
				}
			}
			i64 rg = 0;
			{
				for (int j = 0; j < 60; ++j) {
					if ((X[i] >> j) & 1) {
						ADD(rg, pows[j] * N);
					} else {
						ADD(rg, pows[j] * dig[j]);
					}
				}
			}
			ADD(ret, lf * rg);
		}
		printf("%lld\n", ret);
	}
	return 0;
}