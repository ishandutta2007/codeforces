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

const int maxN = 22;

char s[maxN][maxN];
int n, m;

int d[maxN + maxN][maxN + maxN][maxN + maxN][maxN + maxN][2];
int used[maxN * maxN], cnt = 0;

int calc(int l1, int r1, int l2, int r2, int mode) {
	if (l1 + 1 >= r1 || l2 + 1 >= r2) {
		return 0;
	}
	if (d[l1][r1][l2][r2][mode] != -1) {
		return d[l1][r1][l2][r2][mode];
	}
	for (int i = 0; i < n; ++i) {
		int l = 0;
		int r = m - 1;
		l = max(l, max(l1 - i, i + m - r2 + 1));
		r = min(r, min(r1 - i - 2, i + m - l2 - 1));
		if ((i + l) % 2 != mode) {
			++l;
		}
		for (int j = l; j <= r; j += 2) {
			int l0 = i + j + 1;
			int r0 = i - j + m;

			if (s[i][j] == 'L') {
				calc(l1, l0, l2, r2, mode);
				calc(l0, r1, l2, r2, mode);
			}
			if (s[i][j] == 'R') {
				calc(l1, r1, l2, r0, mode);
				calc(l1, r1, r0, r2, mode);
			}
			if (s[i][j] == 'X') {
				calc(l1, l0, l2, r0, mode);
				calc(l1, l0, r0, r2, mode);
				calc(l0, r1, l2, r0, mode);
				calc(l0, r1, r0, r2, mode);
			}
		}
	}

	++cnt;
	for (int i = 0; i < n; ++i) {
		int l = 0;
		int r = m - 1;
		l = max(l, max(l1 - i, i + m - r2 + 1));
		r = min(r, min(r1 - i - 2, i + m - l2 - 1));
		if ((i + l) % 2 != mode) {
			++l;
		}
		for (int j = l; j <= r; j += 2) {
			int l0 = i + j + 1;
			int r0 = i - j + m;

			if (s[i][j] == 'L') {
				used[calc(l1, l0, l2, r2, mode) ^ calc(l0, r1, l2, r2, mode)] = cnt;
			}
			if (s[i][j] == 'R') {
				used[calc(l1, r1, l2, r0, mode) ^ calc(l1, r1, r0, r2, mode)] = cnt;
			}
			if (s[i][j] == 'X') {
				used[calc(l1, l0, l2, r0, mode) ^ calc(l1, l0, r0, r2, mode) ^ calc(l0, r1, l2, r0, mode) ^ calc(l0, r1, r0, r2, mode)] = cnt;
			}
		}
	}
	for (int i = 0; ; ++i) {
		if (used[i] != cnt) {
			return d[l1][r1][l2][r2][mode] = i;
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%s", &s[i]);
	}
	memset(d, -1, sizeof(d));
	int res = (calc(0, n + m, 0, n + m, 0) ^ calc(0, n + m, 0, n + m, 1));
	if (res == 0) {
		cout << "LOSE" << endl;
	} else {
		cout << "WIN" << endl;
	}

	return 0;
}