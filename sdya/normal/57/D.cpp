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
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 1100;
char s[maxN][maxN], t[maxN][maxN];
int n, m;

long long da[maxN][maxN], db[maxN][maxN];
int pos[maxN];

long long cnt[maxN];

long long calc(char s[maxN][maxN], int n, int m) {
	memset(da, 0, sizeof(da));
	memset(db, 0, sizeof(db));
	memset(pos, -1, sizeof(pos));
	memset(cnt, 0, sizeof(cnt));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (s[i][j] == 'X') {
				pos[i] = j;
			} else {
				++cnt[i];
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = m - 1; j >= 0; --j) {
			if (s[i][j] == 'X') {
				da[i][j] = m - 1 - j;
				if (i > 0 && pos[i - 1] > j) {
					da[i][j] += da[i - 1][j];
				}
			} else {
				da[i][j] = da[i][j + 1];
			}
		}
	}

	for (int i = n - 1; i >= 0; --i) {
		for (int j = m - 1; j >= 0; --j) {
			if (s[i][j] == 'X') {
				db[i][j] = m - 1 - j;
				if (i + 1 < n && pos[i + 1] > j) {
					db[i][j] += db[i + 1][j];
				}
			} else {
				db[i][j] = db[i][j + 1];
			}
		}
	}

	long long res = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (s[i][j] == '.') {
				res += da[i][j] + db[i][j];
				if (j < pos[i]) {
					res -= m - 1 - pos[i];
				}
			}
		}
	}
	res *= 2LL;

	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			res += (long long)(j - i) * (long long)(cnt[i]) * (long long)(cnt[j]);
		}
	}
	return res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%s", &s[i]);
	}

	long long sumA = calc(s, n, m);
	for (int i = 0; i < n; ++i) {
		reverse(s[i], s[i] + m);
	}
	long long sumB = calc(s, n, m);

	for (int i = 0; i < n; ++i) {
		reverse(s[i], s[i] + m);
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			t[j][i] = s[i][j];
		}
	}
	long long sumC = calc(t, m, n);
	for (int i = 0; i < m; ++i) {
		reverse(t[i], t[i] + n);
	}
	long long sumD = calc(t, m, n);

	long long k = 0;
	for (int i = 0; i < n; ++i) {
		k += count(s[i], s[i] + m, '.');
	}

	long long A = sumA + sumB + sumC + sumD;
	long long B = k * k;
	printf("%.10lf\n", (double)(A) / (double)(B));

	return 0;
}