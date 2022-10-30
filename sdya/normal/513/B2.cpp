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

int calc(vector < int > a) {
	int n = a.size();
	int res = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			int x = n;
			for (int k = i; k <= j; ++k) {
				x = min(x, a[k]);
			}
			res += x;
		}
	}
	return res;
}

const int maxN = 60;
long long c[maxN][maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i = 0; i < maxN; ++i) {
		c[i][0] = 1LL;
		for (int j = 1; j <= i; ++j) {
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
		}
	}
	int n;
	long long m;
	cin >> n >> m;
	/*{
		vector < int > a(n);
		for (int i = 0; i < n; ++i) {
			a[i] = i + 1;
		}
		int ans = 0;
		do {
			ans = max(ans, calc(a));
		} while (next_permutation(a.begin(), a.end()));

		sort(a.begin(), a.end());
		long long f = m;
		do {
			if (calc(a) == ans) {
				--f;
			}
			if (f == 0) {
				for (int i = 0; i < a.size(); ++i) {
					printf("%d ", a[i]);
				}
				printf("\n");
				break;
			}
		} while (next_permutation(a.begin(), a.end()));
	}*/
	vector < long long > res;
	vector < bool > used(n + 1, false);
	for (int i = 0; i < n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (used[j]) {
				continue;
			}
			if (i > 0 && j < res[i - 1]) {
				continue;
			}
			if (j == n) {
				res.push_back(n);
				for (int k = n - 1; k >= 1; --k) {
					if (!used[k]) {
						res.push_back(k);
					}
				}
				for (int k = 0; k < n; ++k) {
					printf("%d ", res[k]);
				}
				printf("\n");
				return 0;
			}
			int have = 0;
			for (int k = j + 1; k < n; ++k) {
				if (!used[k]) {
					++have;
				}
			}
			long long ways = (1LL << (long long)(have));
			if (ways < m) {
				m -= ways;
				continue;
			} else {
				res.push_back(j);
				used[j] = true;
				break;
			}
		}
	}
	

	return 0;
}