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

const int maxN = 110;
const int maxM = 25;
const int inf = 1000000000;
int a[maxN];
int n, m;
int dp[maxM][1 << 20];
pair < int, int > r[maxN];

int calc(int moves, int mask) {
	if (dp[moves][mask] != inf) {
		return dp[moves][mask];
	}
	if (moves == m) {
		return dp[moves][mask] = 0;
	}

	int res = (r[moves].second == 1 ? -inf : inf);
	if (r[moves].first == 1) {
		for (int i = 0; i < n; ++i) {
			if ((mask & (1 << i)) == 0) {
				if (r[moves].second == 1) {
					res = max(res, calc(moves + 1, mask | (1 << i)) + a[i]);
				} else {
					res = min(res, calc(moves + 1, mask | (1 << i)) - a[i]);
				}
			}
		}
	} else {
		for (int i = 0; i < n; ++i) {
			if ((mask & (1 << i)) == 0) {
				if (r[moves].second == 1) {
					res = max(res, calc(moves + 1, mask | (1 << i)));
				} else {
					res = min(res, calc(moves + 1, mask | (1 << i)));
				}
			}
		}
		if (r[moves].second == 1) {
			res = max(res, calc(moves + 1, mask));
		} else {
			res = min(res, calc(moves + 1, mask));
		}
	}
	return dp[moves][mask] = res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	reverse(a, a + n);
	scanf("%d", &m);
	n = min(n, m);

	for (int i = 0; i < m; ++i) {
		string s;
		cin >> s;
		int p;
		cin >> p;
		int q = (s == "p" ? 1 : 2);
		r[i] = make_pair(q, p);
	}

	for (int i = 0; i <= m; ++i) {
		for (int j = 0; j < (1 << n); ++j) {
			dp[i][j] = inf;
		}
	}
	printf("%d\n", calc(0, 0));

	return 0;
}