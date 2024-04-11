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

int N, A[202020], B[202020];

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) scanf("%d", A + i);
	for (int i = 0; i < N; ++i) scanf("%d", B + i);

	bool flg = true;
	int pos;
	if (B[N - 1] == 0) flg = false;
	for (int i = N - 1; i >= 0; --i) {
		pos = i;
		if (B[i] == 1) break;
		if (i < N - 1 && B[i + 1] != B[i] + 1) {
			flg = false;
			break;
		}
	}
	if (flg) {
		for (int i = 0; i < pos; ++i) {
			if (B[i] != 0 && B[i] <= N - pos + i + 1) flg = false;
		}
		if (flg) {
			printf("%d\n", pos);
			return 0;
		}
	}
	int ret = 0;
	for (int i = 0; i < N; ++i) {
		if (B[i] != 0) ret = max(ret, i - B[i] + 2);
	}

	printf("%d\n", ret + N);
	return 0;
}