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

const int maxN = 1100;
int a[maxN][maxN], b[maxN * maxN], k;
int n, m;
unsigned long long f[maxN][maxN / 64];

inline short bitCount(unsigned long long x) {
	if (x == 0) {
		return 0;
	}
	if (!(x & (x - 1))) {
		return 1;
	}
	return 2;
}

bool check(int value) {
	int len = (m + 63) / 64;
	for (int i = 0; i < n; ++i) {
		for (int j = 0, index = 0; j < m; j += 64, ++index) {
			int r = min(m, j + 64);
			f[i][index] = 0;
			for (int k = j; k < r; ++k) {
				if (a[i][k] >= value) {
					f[i][index] += (1ULL << (unsigned long long)(k - j));
				}
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			short total = 0;
			for (int k = 0; k < len && total < 2; ++k) {
				total += bitCount(f[i][k] & f[j][k]);
			}
			if (total >= 2) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", &a[i][j]);
			b[k++] = a[i][j];
		}
	}
	sort(b, b + k);
	k = unique(b, b + k) - b;

	int left_bound = 0, right_bound = k - 1;
	while (right_bound - left_bound > 1) {
		int middle = (left_bound + right_bound) / 2;
		if (check(b[middle])) {
			left_bound = middle;
		} else {
			right_bound = middle;
		}
	}
	int res = b[left_bound];
	if (check(b[right_bound])) {
		res = b[right_bound];
	}
	printf("%d\n", res);

	return 0;
}