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

int H, W;
int A[110][110];
int rc[110], cc[110];

int main()
{
	scanf("%d%d", &H, &W);
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			scanf("%d", &(A[i][j]));
		}
	}

	int rbase = 0;
	for (int i = 0; i < H; ++i) {
		if (A[i][0] < A[rbase][0]) rbase = i;
	}

	for (int i = 0; i < H; ++i) rc[i] = A[i][0] - A[rbase][0];
	for (int i = 0; i < W; ++i) cc[i] = A[rbase][i];

	for (int i = 0; i < H; ++i) for (int j = 0; j < W; ++j) {
		if (A[i][j] != rc[i] + cc[j]) {
			puts("-1");
			return 0;
		}
	}

	if (H < W) {
		int lll = cc[0];
		for (int i = 1; i < W; ++i) lll = min(lll, cc[i]);
		for (int i = 0; i < H; ++i) rc[i] += lll;
		for (int i = 0; i < W; ++i) cc[i] -= lll;
	}

	int waf = 0;
	for (int i = 0; i < H; ++i) waf += rc[i];
	for (int i = 0; i < W; ++i) waf += cc[i];
	printf("%d\n", waf);
	for (int i = 0; i < H; ++i) {
		for (int _ = 0; _ < rc[i]; ++_) printf("row %d\n", i + 1);
	}
	for (int i = 0; i < W; ++i) {
		for (int _ = 0; _ < cc[i]; ++_) printf("col %d\n", i + 1);
	}
	return 0;
}