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
#include <list>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

int gcd(int a, int b) {
	if (a == 0 || b == 0) {
		return a + b;
	}
	if (a > b) {
		return gcd(a % b, b);
	}
	return gcd(b % a, a);
}

const int maxN = 210000;
const int maxD = 200;
int a[2 * maxN];
int n;
int d[maxN], m;

int gc[maxN];

void getDivisors(int n) {
	m = 0;
	for (int i = 1; i < n; ++i) {
		if (n % i == 0) {
			d[m++] = i;
		}
	}
}

bool g[maxD][maxN];
int p[2 * maxN];
int cnt[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		a[i + n] = a[i];
	}

	getDivisors(n);

	for (int i = 1; i <= n; ++i) {
		gc[i] = gcd(i, n);
	}

	for (int i = 0; i < m; ++i) {
		int step = n / d[i];

		for (int s = 0; s < d[i]; ++s) {
			int value = 0;
			for (int j = 0, k = s; j < step; ++j) {
				value = max(value, a[k]);
				k += d[i];
				if (k >= n) {
					k -= n;
				}
			}

			for (int j = 0, k = s; j < step; ++j) {
				if (a[k] == value) {
					g[i][k] = true;
				}
				k += d[i];
				if (k >= n) {
					k -= n;
				}
			}
		}
	}

	long long res = 0;
	for (int index = 0; index < m; ++index) {
		int G = d[index];
		for (int i = 0; i <= 2 * n; ++i) {
			p[i] = 0;
		}
		for (int i = n + n - 1; i >= 0; --i) {
			int j = i;
			if (j >= n) {
				j -= n;
			}

			if (g[index][j]) {
				p[i] = 1 + p[i + 1];
			}
		}

		for (int i = 0; i <= n; ++i) {
			cnt[i] = 0;
		}

		for (int i = G; i < n; i += G) {
			if (gc[i] == G) {
				cnt[i] += 1;
			}
		}

		for (int i = 1; i <= n; ++i) {
			cnt[i] += cnt[i - 1];
		}

		for (int l = 0; l < n; ++l) {
			res += cnt[min(p[l], n)];
		}
	}

	cout << res << endl;

	return 0;
}