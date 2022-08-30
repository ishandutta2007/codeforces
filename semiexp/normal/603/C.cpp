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
#define MOD
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

int N, K;
int A[101010];

int grundy(int x)
{
	if (K == 0) {
		if (x <= 2) return x;
		if (x % 2 == 1) return 0;
		return 1;
	} else {
		if (x == 0) return 0;
		if (x >= 5 && x % 2 == 1) return 0;

		int cand = 7;
		cand &= ~(1 << grundy(x - 1));
		if (x % 2 == 0) cand &= ~(1 << grundy(x / 2));
		if (cand & 1) return 0;
		if (cand & 2) return 1;
		return 2;
	}
}

int grundy2(int x)
{
	if (x == 0) return 0;

	int cand = 7;
	cand &= ~(1 << grundy2(x - 1));
	if (x % 2 == 0) {
		if (K % 2 == 1) cand &= ~(1 << grundy2(x / 2));
		else cand &= ~1;
	}
	if (cand & 1) return 0;
	if (cand & 2) return 1;
	return 2;
}

int main()
{
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; ++i) scanf("%d", A + i);
	K %= 2;

	int a = 0;
	for (int i = 0; i < N; ++i) a ^= grundy(A[i]);
	puts(a ? "Kevin" : "Nicky");
	return 0;
}