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

const int maxN = 210000;
int n, a[maxN];
long long s[maxN];

bool isGreater(long long x1, long long y1, long long x2, long long y2) {
	if (x1 >= 0 && x2 >= 0) {
		return x1 * y2 >= x2 * y1;
	}
	if (x1 >= 0 && x2 < 0) {
		return true;
	}
	if (x1 < 0 && x2 >= 0) {
		return false;
	}
	return -x1 * y2 <= -x2 * y1;
}

pair < long long, long long > calculateA(int i, int m) {
	return make_pair(s[i] - (i - m == 0 ? 0 : s[i - m - 1]) + s[n - 1] - s[n - m - 1], 2LL * m + 1);
}

pair < long long, long long > calculateB(int i, int m) {
	return make_pair(s[i + 1] - (i - m == 0 ? 0 : s[i - m - 1]) + s[n - 1] - s[n - m - 1], 2LL * m + 2);
}


int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	for (int i = 0; i < n; ++i) {
		s[i] = a[i];
		if (i > 0) {
			s[i] += s[i - 1];
		}
	}

	long long p = 0, q = 1;
	vector < pair < int, int > > res(1, make_pair(0, 0));
	for (int i = 0; i < n; ++i) {
		int left_bound = 0, right_bound = min(i, n - 1 - i);
		while (right_bound - left_bound > 20) {
			int u = (2 * left_bound + right_bound) / 3;
			int v = (left_bound + 2 * right_bound) / 3;
			pair < long long, long long > U = calculateA(i, u);
			pair < long long, long long > V = calculateA(i, v);
			if (isGreater(U.first, U.second, V.first, V.second)) {
				right_bound = v;
			} else {
				left_bound = u;
			}
		}
		long long x = 0, y = 1;
		int m = 0;
		for (int j = left_bound; j <= right_bound; ++j) {
			pair < long long, long long > current = calculateA(i, j);
			if (isGreater(current.first, current.second, x, y)) {
				x = current.first;
				y = current.second;
				m = j;
			}
		}

		x -= (long long)(a[i]) * y;
		if (isGreater(x, y, p, q)) {
			p = x;
			q = y;
			res.clear();
			res.push_back(make_pair(i - m, i));
			res.push_back(make_pair(n - m, n - 1));
		}
	}

	for (int i = 0; i + 1 < n; ++i) {
		int left_bound = 0, right_bound = min(i, n - 2 - i);
		while (right_bound - left_bound > 20) {
			int u = (2 * left_bound + right_bound) / 3;
			int v = (left_bound + 2 * right_bound) / 3;
			pair < long long, long long > U = calculateB(i, u);
			pair < long long, long long > V = calculateB(i, v);
			if (isGreater(U.first, U.second, V.first, V.second)) {
				right_bound = v;
			} else {
				left_bound = u;
			}
		}
		long long x = 0, y = 1;
		int m = 0;
		for (int j = left_bound; j <= right_bound; ++j) {
			pair < long long, long long > current = calculateB(i, j);
			if (isGreater(current.first, current.second, x, y)) {
				x = current.first;
				y = current.second;
				m = j;
			}
		}

		x *= 2;
		x -= (long long)(a[i]) * y;
		x -= (long long)(a[i + 1]) * y;
		y *= 2;
		if (isGreater(x, y, p, q)) {
			p = x;
			q = y;
			res.clear();
			res.push_back(make_pair(i - m, i + 1));
			res.push_back(make_pair(n - m, n - 1));
		}
	}
	int m = 0;
	for (int i = 0; i < res.size(); ++i) {
		m += res[i].second - res[i].first + 1;
	}
	printf("%d\n", m);
	for (int i = 0; i < res.size(); ++i) {
		for (int j = res[i].first; j <= res[i].second; ++j) {
			printf("%d ", a[j]);
		}
	}
	printf("\n");

	return 0;
}