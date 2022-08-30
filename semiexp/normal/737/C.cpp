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

int N, S;
int A[202020];

int cnt[202020];
int acnt[202020];
int ki[202020];

int main()
{
	scanf("%d%d", &N, &S);
	for (int i = 0; i < N; ++i) scanf("%d", A + i);
	--S;

	int ww = 0;
	if (A[S] != 0) {
		A[S] = 0;
		++ww;
	}

	for (int i = 0; i < N; ++i) cnt[i] = 0;

	for (int i = 0; i < N; ++i) if (i != S) {
		++cnt[A[i]];
	}
	acnt[N - 1] = cnt[N - 1];
	for (int i = N - 2; i >= 0; --i) acnt[i] = acnt[i + 1] + cnt[i];
	ki[0] = 0;
	for (int i = 1; i < N; ++i) ki[i] = ki[i - 1] + (cnt[i] == 0 ? 1 : 0);

	int ret = N;
	if (N == 1) {
		ret = 0;
	} else {
		for (int i = 1; i <= N - 1; ++i) {
			int tmp = max(ki[i], acnt[i + 1] + cnt[0]);
			ret = min(ret, tmp);
		}
	}

	printf("%d\n", ret + ww);

	return 0;
}