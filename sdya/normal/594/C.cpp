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

const int maxN = 110000;
int n, k;
int x[maxN], y[maxN];
pair < int, int > p[maxN];

bool check(int lx, int rx) {
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (x[i] < lx || x[i] > rx) {
			++cnt;
		}
		if (cnt > k) {
			return false;
		}
	}
	return true;
}

int z[maxN];

long long solve(int lx, int rx) {
	int m = 0;
	int rem = k;
	for (int i = 0; i < n; ++i) {
		if (p[i].second >= lx && p[i].second <= rx) {
			z[m++] = p[i].first;
		} else {
			--rem;
		}
	}

	long long x = rx - lx;
	if (x % 2 == 1) {
		++x;
	}
	if (x == 0) {
		x += 2;
	}

	long long y = 2000000000LL;
	for (int i = 0; i < m && i <= rem; ++i) {
		int ly = z[i];
		int ry = z[m - 1 - (rem - i)];
		long long s = ry - ly;
		if (s % 2 == 1) {
			s += 1;
		}
		y = min(y, s);
	}
	if (y == 0) {
		y += 2;
	}
	return x * y;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &k);

	vector < int > xs, ys;
	for (int i = 0; i < n; ++i) {
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		x[i] = x1 + x2;
		y[i] = y1 + y2;

		xs.push_back(x[i]);
		ys.push_back(y[i]);

		p[i] = make_pair(y[i], x[i]);
	}

	sort(p, p + n);

	sort(xs.begin(), xs.end());
	sort(ys.begin(), ys.end());

	xs.resize(unique(xs.begin(), xs.end()) - xs.begin());
	ys.resize(unique(ys.begin(), ys.end()) - ys.begin());

	int m = xs.size();

	long long res = 8000000000000000000LL;
	for (int i = 0; i < 12 && i < xs.size(); ++i) {
		for (int j = 0; j < 12 && j < xs.size(); ++j) {
			if (!check(xs[i], xs[m - 1 - j])) {
				continue;
			}

			res = min(res, solve(xs[i], xs[m - 1 - j]));
		}
	}

	cout << res / 4LL << endl;

	return 0;
}