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
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 80000;
const int maxD = 300;
const int maxB = 35;
const int P = 777777777;
int n, m;
int w[4][4];

int lB[maxN], rB[maxN], q;
int bucketId[maxN];

int llB[maxD][maxB], rrB[maxD][maxB], cnt[maxD];
int bucketId2[maxN];
int ddp[maxD][maxB][4][4];
int dp[maxD][4][4];

int a[maxN];

int d[2][4];

void calc(int index, int subindex) {
	for (int start = 0; start <= 3; ++start) {
		int u = 0, v = 1;
		int l = llB[index][subindex];
		int r = rrB[index][subindex];
		memset(d[u], 0, sizeof(d[u]));
		d[u][start] = 1;
		for (int i = l; i <= r; ++i, swap(u, v)) {
			memset(d[v], 0, sizeof(d[v]));
			for (int j = 1; j <= 3; ++j) {
				if (a[i] == 0 || a[i] == j) {
					for (int k = 0; k <= 3; ++k) {
						if (w[k][j] && d[u][k]) {
							d[v][j] += d[u][k];
							if (d[v][j] >= P) {
								d[v][j] -= P;
							}
						}
					}
				}
			}
		}
		for (int i = 1; i <= 3; ++i) {
			ddp[index][subindex][start][i] = d[u][i];
		}
	}
}

void calc(int index) {
	for (int start = 0; start <= 3; ++start) {
		int u = 0, v = 1;
		memset(d[u], 0, sizeof(d[u]));
		d[u][start] = 1;
		for (int i = 0; i < cnt[index]; ++i, swap(u, v)) {
			memset(d[v], 0, sizeof(d[v]));
			for (int j = 0; j <= 3; ++j) {
				if (d[u][j] == 0) {
					continue;
				}
				for (int k = 1; k <= 3; ++k) {
					d[v][k] += ((long long)(d[u][j]) * (long long)(ddp[index][i][j][k])) % P;
					if (d[v][k] >= P) {
						d[v][k] -= P;
					}
				}
			}
		}
		for (int i = 1; i <= 3; ++i) {
			dp[index][start][i] = d[u][i];
		}
	}
}

int get() {
	int u = 0, v = 1;
	memset(d[u], 0, sizeof(d[u]));	
	d[u][0] = 1;
	for (int i = 0; i < q; ++i, swap(u, v)) {
		memset(d[v], 0, sizeof(d[v]));
		for (int j = 1; j <= 3; ++j) {
			for (int k = 0; k <= 3; ++k) {
				if (d[u][k]) {
					long long added = (long long)(dp[i][k][j]) * (long long)(d[u][k]);
					added %= P;
					d[v][j] += added;
					if (d[v][j] >= P) {
						d[v][j] %= P;
					}
				}
			}
		}
	}
	int res = 0;
	for (int i = 1; i <= 3; ++i) {
		res += d[u][i];
		res %= P;
	}
	return res;
}

void init(int index) {
	int l = lB[index];
	cnt[index] = 0;
	while (l <= rB[index]) {
		int r = min(rB[index], l + maxB - 1);
		llB[index][cnt[index]] = l;
		rrB[index][cnt[index]] = r;
		for (int i = l; i <= r; ++i) {
			bucketId2[i] = cnt[index];
		}
		calc(index, cnt[index]);
		++cnt[index];
		l = r + 1;
	}
	calc(index);
}

void init() {
	int l = 1;
	while (l <= n) {
		int r = min(l + maxB * maxB - 1, n);
		lB[q] = l;
		rB[q] = r;
		for (int i = l; i <= r; ++i) {
			bucketId[i] = q;
		}
		init(q);
		++q;
		l = r + 1;
	}
}

void gen() {
	int n = 77777;
	int m = n;
	printf("%d %d\n", n, m);
	for (int i = 1; i <= 3; ++i) {
		for (int j = 1; j <= 3; ++j) {
			printf("1 ");
		}
		printf("\n");
	}
	for (int i = 1; i <= m; ++i) {
		int x = (rand() * rand() + rand()) % n + 1;
		int y = rand() % 4;
		printf("%d %d\n", x, y);
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	//gen();

	scanf("%d%d", &n, &m);
	for (int i = 1; i < 4; ++i) {
		for (int j = 1; j < 4; ++j) {
			scanf("%d", &w[i][j]);
		}
	}
	w[0][1] = w[0][2] = w[0][3] = true;

	init();

	for (int i = 1; i <= m; ++i) {
		int index, value;
		scanf("%d%d", &index, &value);
		a[index] = value;
		calc(bucketId[index], bucketId2[index]);
		calc(bucketId[index]);
		printf("%d\n", get());
	}

	cerr << clock() << endl;

	return 0;
}