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

const int maxN = 505;
const long long P = 1000000007LL;

long long d[2][maxN][maxN];
long long p[maxN];
long long w[maxN], sw[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	p[0] = 1;
	for (int i = 1; i < maxN; ++i) {
		p[i] = (2 * p[i - 1]) % P;
	}

	int u = 0, v = 1;
	int n, m;
	scanf("%d%d", &n, &m);
	if (m == 0) {
		printf("1\n");
		return 0;
	}

	d[u][1][1] = 1;
	for (int i = 2; i <= n; ++i, swap(u, v)) {
		for (int j = i; j >= 1; --j) {
			w[j] = sw[j] = p[i - j];
			if (j + 1 <= i) {
				sw[j] = (sw[j] + sw[j + 1]) % P;
			}
		}
		for (int pos = 2; pos <= i; ++pos) {
			d[v][1][pos] = (sw[pos] + 1) * d[u][1][pos - 1];
			d[v][1][pos] %= P;
		}
		d[v][1][1] = sw[1];
		for (int j = 2; j <= i; ++j) {
			for (int pos = 2; pos <= i; ++pos) {
				d[v][j][pos] = (sw[pos] + 1LL) * d[u][j][pos - 1];
				d[v][j][pos] %= P;
			}

			d[v][j][1] = 0;
			long long total = 0;
			for (int x = i; x >= 1; --x) {
				total += d[u][j - 1][x];
				if (total >= P) {
					total -= P;
				}
				d[v][j][1] += w[x] * total;
				d[v][j][1] %= P;
			}
		}
	}

	long long res = 0;
	for (int j = 1; j <= n; ++j) {
		res += d[u][m][j];
		res %= P;
	}
	cout << res << endl;


	return 0;
}