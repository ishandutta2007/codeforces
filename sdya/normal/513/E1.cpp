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

const int maxN = 31000;
const int maxD = 400;
int d[2][maxD][maxN];
int s[maxN];
int a[maxN];
int n, k;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}

	int step = maxD;
	if (n > 1000) {
		step = 50;
	}
	int u = 0, v = 1;
	for (int steps = 1; steps < k; ++steps, swap(u, v)) {
		for (int i = 0; i < step; ++i) {
			for (int j = 1; j <= n; ++j) {
				d[v][i][j] = -1000000000;
			}
		}
		for (int i = 0; i < step; ++i) {
			for (int j = 1 + i; j <= n; ++j) {
				int A = s[j] - s[j - i - 1];
				int a = j + 1;
				for (int b = j + 1; b <= j + step && b <= n; ++b) {
					int B = s[b] - s[a - 1];
					d[v][b - a][b] = max(d[v][b - a][b], d[u][i][j] + abs(B - A));
				}
			}
		}
	}
	int res = 0;
	for (int i = 0; i < maxD; ++i) {
		for (int j = 1 + i; j <= n; ++j) {
			res = max(res, d[u][i][j]);
		}
	}
	cout << res << endl;

	return 0;
}