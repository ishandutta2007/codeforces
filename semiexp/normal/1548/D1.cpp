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
#include <random>
using namespace std;
#define MOD
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

int N;
int X[6060], Y[6060];

int mygcd(int a, int b) {
	if (a < 0) a = -a;
	if (b < 0) b = -b;
	while (b) {
		int tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}

int edgecnt(int i, int j) {
	return mygcd(X[j] - X[i], Y[j] - Y[i]);
}

i64 naive() {
	i64 ret = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			for (int k = j + 1; k < N; ++k) {
				i64 tri = (i64)(X[j] - X[i]) * (Y[k] - Y[i]) - (i64)(X[k] - X[i]) * (Y[j] - Y[i]);
				if (tri < 0) tri = -tri;
				tri = (tri + 16) % 4;

				int chi = (tri + 2 + 3 * (edgecnt(i, j) + edgecnt(j, k) + edgecnt(k, i))) % 4;
				if (chi == 2) ++ret;
			}
		}
	}
	return ret;
}

void easy_fast() {
	i64 xs[16], ys[16], cnt[16];
	for (int i = 0; i < 16; ++i) {
		xs[i] = i % 4;
		ys[i] = i / 4;
		cnt[i] = 0;
	}

	for (int i = 0; i < N; ++i) {
		int grp = (X[i] % 4) + (Y[i] % 4) * 4;
		++cnt[grp];
	}

	i64 ret = 0;
	for (int i = 0; i < 16; ++i) {
		for (int j = i; j < 16; ++j) {
			for (int k = j; k < 16; ++k) {
				if (cnt[i] == 0 || cnt[j] == 0 || cnt[k] == 0) continue;
				int b = (i == j ? 0 : 2) + (j == k ? 0 : 2) + (i == k ? 0 : 2);
				// printf("%d %d %d %d\n", i, j, k, b);
				if (b % 4 == 0) {
					i64 tmp = cnt[i];
					tmp *= cnt[j] - (i == j ? 1 : 0);
					tmp *= cnt[k] - (j == k ? (i == j ? 2 : 1) : 0);
					if (i == j && j == k) {
						tmp /= 6;
					} else if (i == j || j == k) {
						tmp /= 2;
					}
					ret += tmp;
				}
			}
		}
	}
	printf("%lld\n", ret);
}

int main()
{
	if (true) {
		scanf("%d", &N);
		for (int i = 0; i < N; ++i) scanf("%d%d", X + i, Y + i);
	} else {
		mt19937 rng(42);
		N = 500;
		for (int i = 0; i < N; ++i) {
			X[i] = uniform_int_distribution<int>(0, 5000000)(rng) * 2;
			Y[i] = uniform_int_distribution<int>(0, 5000000)(rng) * 2;
		}
	}

	// solves D1 only
	// printf("%lld\n", naive());
	easy_fast();

	return 0;
}