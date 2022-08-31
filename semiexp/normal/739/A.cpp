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

int N, M;
int L[101010], R[101010];
int ans[101010];

int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; ++i) {
		scanf("%d%d", L + i, R + i);
		--L[i];
	}
	int mex = N;
	for (int i = 0; i < M; ++i) mex = min(mex, R[i] - L[i]);
	printf("%d\n", mex);
	for (int i = 0; i < N; ++i) ans[i] = i % mex;

	for (int i = 0; i < N; ++i) printf("%d%c", ans[i], i == N - 1 ? '\n' : ' ');

	return 0;
}