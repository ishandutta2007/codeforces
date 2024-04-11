#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <stack>
#include <ctime>
#include <unordered_map>
#include <unordered_set>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int P = 1000000007LL;

const int maxN = 1100;
long long c[maxN][maxN];
long long f[maxN];

const int maxK = 50;
int d[maxK][maxN][maxN], ways[maxK][maxN];

void add(int &x, int value) {
	x += value;
	if (x >= P) {
		x -= P;
	}
}

long long r[maxK][maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	for (int i = 0; i < maxN; ++i) {
		c[i][0] = 1;
		for (int j = 1; j <= i; ++j) {
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % P;
		}
	}
	f[0] = 1;
	for (int i = 1; i < maxN; ++i) {
		f[i] = (f[i - 1] * (long long)(i)) % P;
	}

	d[0][0][0] = 1;
	d[1][0][0] = 1;
	for (int cnt = 0; cnt + 1 < maxK; ++cnt) {
		for (int total = 0; total < maxN; ++total) {
			for (int value = 0; value < maxN; ++value) {
				if (value + 1 < maxN) {
					add(d[cnt][total][value + 1], d[cnt][total][value]);
				}
				if (total + value + 1 < maxN && value + 1 < maxN) {
					add(d[cnt + 1][total + value + 1][value + 1], d[cnt][total][value]);
				}
			}
		}
	}
	for (int cnt = 1; cnt < maxK; ++cnt) {
		for (int total = 0; total < maxN; ++total) {
			ways[cnt][total] = ((long long)(d[cnt][total][total]) * f[cnt]) % (long long)(P);
		}
	}

	for (int i = 1; i < maxK; ++i) {
		for (int j = 1; j < maxN; ++j) {
			for (int s = 0; s + i - 1 <= j; ++s) {
				if (ways[i][s] == 0) {
					continue;
				}
				long long coef = c[j - s][i];
				r[i][j] += coef * ways[i][s];
				r[i][j] %= P;
			}
		}
	}

	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		int n, k;
		scanf("%d%d", &n, &k);
		if (k >= maxK) {
			printf("0\n");
		} else {
			printf("%d\n", r[k][n]);
		}
	}

	return 0;
}