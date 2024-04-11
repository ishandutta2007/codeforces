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

const int maxN = 3100;
int n, x[maxN], y[maxN];
int d[maxN][maxN], b[maxN * maxN / 2], k;
unsigned long long f[maxN][maxN / 64];

bool check(int value) {
	int len = (n + 63) / 64;
	for (int i = 0; i < n; ++i) {
		for (int j = 0, index = 0; j < n; j += 64, ++index) {
			int r = min(n, j + 64);
			f[i][index] = 0;
			for (int k = j; k < r; ++k) {
				if (d[i][k] >= value) {
					f[i][index] += (1ULL << (unsigned long long)(k - j));
				}
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (d[i][j] < value) {
				continue;
			}
			bool total = false;
			for (int k = j / 64; k < len && !total; ++k) {
				if ((f[i][k] & f[j][k])) {
					total = true;
				}
			}
			if (total) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &x[i], &y[i]);
	}
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			int dx = x[i] - x[j];
			int dy = y[i] - y[j];
			d[i][j] = d[j][i] = (dx * dx + dy * dy);
			b[k ++] = d[i][j];
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

	double ans = sqrt((double)(res)) / 2.0;
	printf("%.10lf\n", ans);

	return 0;
}