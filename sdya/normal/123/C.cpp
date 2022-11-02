#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <bitset>
#include <ctime>
#include <unordered_map>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const long long inf = 2000000000000000000LL;
const int maxN = 210;
long long n, m, k;
int a[maxN][maxN];
char res[maxN][maxN];

long long c[maxN][maxN];
long long d[maxN][maxN];

int M[maxN];

long long calc() {
	memset(d, 0, sizeof(d));
	d[0][0] = 1;
	for (int i = 0; i < n + m - 1; ++i) {
		for (int j = 0; j < maxN; ++j) {
			if (d[i][j] == 0) {
				continue;
			}
			if (M[i] == 1 || M[i] == 0) {
				d[i + 1][j + 1] += d[i][j];
				if (d[i + 1][j + 1] >= inf) {
					d[i + 1][j + 1] = inf;
				}
			}
			if (j > 0 && (M[i] == 2 || M[i] == 0)) {
				d[i + 1][j - 1] += d[i][j];
				if (d[i + 1][j - 1] >= inf) {
					d[i + 1][j - 1] = inf;
				}
			}
		}
	}
	return d[n + m - 1][0];
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	for (int i = 0; i < maxN; ++i) {
		c[i][0] = 1LL;
		for (int j = 1; j <= i; ++j) {
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
			if (c[i][j] >= inf) {
				c[i][j] = inf;
			}
		}
	}
	cin >> n >> m >> k;
	vector < pair < int, pair < int, int > > > p;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
			p.push_back(make_pair(a[i][j], make_pair(i, j)));
		}
	}
	sort(p.begin(), p.end());

	M[0] = 1;
	M[n + m - 2] = 2;
	for (int i = 0; i < p.size(); ++i) {
		int x = p[i].second.first;
		int y = p[i].second.second;

		int old = M[x + y];
		if (old != 0) {
			res[x][y] = old == 1 ? '(' : ')';
			continue;
		}

		M[x + y] = 1;
		long long ways = calc();
		if (ways >= k) {
			res[x][y] = '(';
			continue;
		}
		res[x][y] = ')';
		k -= ways;
		M[x + y] = 2;
		continue;
	}

	for (int i = 0; i < n; ++i) {
		puts(res[i]);
	}

	return 0;
}