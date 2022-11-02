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

const int maxN = 110000;
int n, m;
int a[maxN], t[maxN * 4];

int gcd(int a, int b) {
	int b1 = a, b2 = b;
	while (b2) {
		int q = b1 / b2;
		b1 -= q * b2;
		swap(b1, b2);
	}
	return b1 + b2;
}

map < int, long long > M;
int q[4 * maxN], r[4 * maxN];

int pg[17][maxN], nt[17][maxN];
int p2[maxN];

int getGcd(int l, int r) {
	int len = r - l + 1;
	int k = p2[len];
	return gcd(pg[k][l], pg[k][r - (1 << k) + 1]);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; ++i) {
		pg[0][i] = a[i];
		nt[0][i] = i + 1;
	}
	for (int i = 1; i < 17; ++i) {
		for (int j = 0; j < n; ++j) {
			pg[i][j] = gcd(pg[i - 1][j], pg[i - 1][nt[i - 1][j]]);
			nt[i][j] = nt[i - 1][nt[i - 1][j]];
		}
	}

	for (int i = 1; i < maxN; ++i) {
		for (int j = 0; ; ++j) {
			if ((1 << j) <= i) {
				p2[i] = j;
			} else {
				break;
			}
		}
	}

	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d", &q[i]);
		r[i] = q[i];
	}
	sort(r, r + m);

	for (int i = 0; i < n; ++i) {
		int g = a[i];
		int bound = i;
		while (bound < n) {
			int left_bound = bound, right_bound = n - 1;
			while (right_bound - left_bound > 1) {
				int middle = (left_bound + right_bound) / 2;
				if (getGcd(i, middle) == g) {
					left_bound = middle;
				} else {
					right_bound = middle;
				}
			}
			int nbound = left_bound;
			if (getGcd(i, right_bound) == g) {
				nbound = right_bound;
			}

			if (binary_search(r, r + m, g)) {
				M[g] += (long long)(nbound - bound + 1);
			}
			bound = nbound + 1;
			if (bound < n) {
				g = getGcd(i, bound);
			}
		}
	}

	for (int i = 0; i < m; ++i) {
		printf("%I64d\n", M[q[i]]);
	}

	return 0;
}