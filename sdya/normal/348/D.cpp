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

const int maxN = 3100;
const int P = 1000000007;
char s[maxN][maxN];
int n, m;
int d[maxN][maxN];

long long getWays(int x1, int y1, int x2, int y2) {
	memset(d, 0, sizeof(d));
	if (s[x1][y1] != '#') {
		d[x1][y1] = 1;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (s[i][j] == '#' || (i == x1 && j == y1)) {
				continue;
			}
			if (i > 0) {
				d[i][j] += d[i - 1][j];
				if (d[i][j] >= P) {
					d[i][j] -= P;
				}
			}
			if (j > 0) {
				d[i][j] += d[i][j - 1];
				if (d[i][j] >= P) {
					d[i][j] -= P;
				}
			}
		}
	}
	return d[x2][y2];
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%s", &s[i]);
	}

	long long res = getWays(0, 1, n - 2, m - 1) * getWays(1, 0, n - 1, m - 2) - getWays(0, 1, n - 1, m - 2) * getWays(1, 0, n - 2, m - 1);
	res %= (long long)(P);
	if (res < 0) {
		res += P;
	}
	cout << res << endl;

	return 0;
}