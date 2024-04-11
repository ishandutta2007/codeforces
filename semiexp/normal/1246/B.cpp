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

int N, K, A[101010];
int cnts[101010];

const i64 MX = 1001001001;

pair<int, int> canonize(int v)
{
	i64 ret = 1;
	i64 ret2 = 1;
	for (int i = 2; i * i <= v; ++i) {
		if (v % i == 0) {
			int deg = 0;
			while (v % i == 0) {
				++deg;
				v /= i;
			}
			for (int j = 0; j < deg % K; ++j) {
				ret2 *= i;
			}
			deg = (K - deg % K) % K;
			for (int j = 0; j < deg; ++j) {
				ret = min(ret * i, MX);
			}
		}
	}
	if (v != 1) {
		ret2 *= v;
		for (int j = 0; j < K - 1; ++j) {
			ret = min(ret * v, MX);
		}
	}
	return {ret, ret2};
}

int main()
{
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; ++i) scanf("%d", A + i);

	i64 ret = 0;
	for (int i = 0; i < N; ++i) {
		pair<int, int> par = canonize(A[i]);
		//printf("%d %d %d\n", A[i], par.first, par.second);
		if (par.first <= 100000) ret += cnts[par.first];
		++cnts[par.second];
	}
	printf("%lld\n", ret);
	return 0;
}