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
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 4100;
const int inf = 1000000000;
int n, k;
int a[maxN][maxN];
int s[maxN][maxN], d[maxN][maxN];
int t[maxN];
int dp[2][maxN];

void calc(int d1[], int d2[], int l1, int r1, int l2, int r2) {
	if (l2 > r2) {
		return ;
	}
	if (l2 == r2) {
		for (int i = l1; i <= r1 && i < l2; ++i) {
			d2[l2] = min(d2[l2], d1[i] + d[i + 1][l2]);
		}
		return ;
	}

	int m = (l2 + r2) / 2;

	int best = inf, index = -1;
	for (int i = l1; i <= r1 && i < m; ++i) {
		int value = d1[i] + d[i + 1][m];
		if (value < best) {
			index = i;
			best = value;
		}
	}
	d2[m] = best;
	calc(d1, d2, l1, index, l2, m - 1);
	calc(d1, d2, index, r1, m + 1, r2);
}

void gen() {
	int n = 4000, m = 800;
	printf("%d %d\n", n, m);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j < i; ++j) {
			a[i][j] = a[j][i] = rand() % 10;
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

char c[9000];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	//gen();

	scanf("%d%d\n", &n, &k);
	for (int i = 1; i <= n; ++i) {
		gets(c);
		int m = strlen(c);
		for (int j = 0; j < m; j += 2) {
			a[i][j / 2 + 1] = c[j] - '0';
		}
		for (int j = 1; j <= n; ++j) {
			s[i][j] = a[i][j] + s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1];
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = i; j <= n; ++j) {
			d[i][j] = s[j][j] - s[i - 1][j] - s[j][i - 1] + s[i - 1][i - 1];
		}
	}

	

	int u = 0, v = 1;
	for (int i = 0; i <= n; ++i) {
		dp[u][i] = inf;
	}
	dp[0][0] = 0;
	for (int step = 0; step < k; ++step, swap(u, v)) {
		for (int i = 0; i <= n; ++i) {
			dp[v][i] = inf;
		}

		calc(dp[u], dp[v], 0, n, step + 1, n);
	}

	printf("%d\n", dp[u][n] / 2);


	return 0;
}