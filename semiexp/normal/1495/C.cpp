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

int H, W;
char S[550][550];
char ans[550][550];

void bridge(int y, bool is_last) {
	int cnt = 0;
	for (int i = 0; i < W; ++i) {
		if (ans[y][i] == 'X') {
			if (is_last) ans[y - 1][i] = 'X';
			else {
				if (cnt++ == 0) ans[y - 1][i] = 'X';
			}
		}
	}
	if (cnt == 0) {
		if (ans[y - 1][1] != 'X') {
			ans[y - 1][0] = ans[y][0] = 'X';
		} else {
			ans[y][1] = 'X';
		}
	}
}

int main()
{
	scanf("%d", &T);
	for (;T--;) {
		scanf("%d%d", &H, &W);
		for (int i = 0; i < H; ++i) {
			scanf("%s", S[i]);
		}

		for (int i = 0; i < H; ++i) {
			for (int j = 0; j < W; ++j) {
				ans[i][j] = S[i][j];
			}
			ans[i][W] = 0;
		}
		for (int i = 0; i < H; ++i) {
			if (i % 3 == 0) {
				for (int j = 0; j < W; ++j) ans[i][j] = 'X';
			}
			if (i % 3 == 2) {
				bridge(i, i == H - 1);
			}
		}
		for (int i = 0; i < H; ++i) puts(ans[i]);
	}
	return 0;
}