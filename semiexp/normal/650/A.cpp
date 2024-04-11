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

int N, X[202020], Y[202020];
map<int, int> xs, ys;
map<pair<int, int>, int> pts;

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%d%d", X + i, Y + i);
		xs[X[i]] += 1;
		ys[Y[i]] += 1;
		pts[{X[i], Y[i]}] += 1;
	}
	i64 ret = 0;
	for (auto a : xs) ret += a.second * (i64)(a.second - 1) / 2;
	for (auto a : ys) ret += a.second * (i64)(a.second - 1) / 2;
	for (auto a : pts) ret -= a.second * (i64)(a.second - 1) / 2;
	printf("%lld\n", ret);

	return 0;
}