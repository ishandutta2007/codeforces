#include <cassert>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <bitset>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <stack>
#include <cmath>
#include <ctime>
#include <unordered_set>
#include <unordered_map>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 21;
const int maxM = 110000;

char s[maxN][maxM];
int n, m;
int a[maxM], b[maxM];

int D = 14;
int d[1 << 15];

int cnt[1 << 6][16];

void gen() {
	int n = 20;
	int m = 100000;
	printf("%d %d\n", n, m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			printf("%d", 0);
		}
		printf("\n");
	}
}

int solve() {
	int r = n - D;
	int res = n * m;
	for (int i = 0; i < (1 << r); ++i) {
		int cur = 0;
		for (int j = 0; j < (1 << r); ++j) {
			for (int k = 0; k <= D; ++k) {
				int u = d[i ^ j] + k;
				cur += cnt[j][k] * min(u, n - u);
			}
		}
		res = min(res, cur);
	}
	return res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	//gen();

	//return 0;

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%s", &s[i]);
	}

	D = min(D, n);

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (j < D) {
				a[i] = a[i] * 2 + s[j][i] - '0';
			} else {
				b[i] = b[i] * 2 + s[j][i] - '0';
			}
		}
	}

	for (int i = 0; i < (1 << D); ++i) {
		for (int j = 0; j < D; ++j) {
			if (i & (1 << j)) {
				++d[i];
			}
		}
	}

	int res = n * m;
	for (int i = 0; i < (1 << D); ++i) {
		for (int j = 0; j <= D; ++j) {
			for (int k = 0; k < (1 << (n - D)); ++k) {
				cnt[k][j] = 0;
			}
		}
		for (int j = 0; j < m; ++j) {
			++cnt[b[j]][d[a[j] ^ i]];
		}
		res = min(res, solve());
	}
	printf("%d\n", res);

	//cerr << clock() << endl;


	return 0;
}