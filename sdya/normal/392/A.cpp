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

long long getRoot(long long d) {
	long long n = sqrt((double)(d));
	for (long long i = n + 2; i >= n - 2 && i >= 0; --i) {
		if (i * i <= d) {
			return i;
		}
	}
	return 0;
}

long long dx[] = {-1, 0, 0, 1};
long long dy[] = { 0,-1, 1, 0};

bool isGood(long long x, long long y, long long d) {
	if (x * x + y * y > d) {
		return false;
	}
	for (int i = 0; i < 4; ++i) {
		long long nx = x + dx[i];
		long long ny = y + dy[i];
		if (nx * nx + ny * ny > d) {
			return true;
		}
	}
	return false;
}

long long a[4];

long long solve2(int n) {
	long long res = 0;
	long long d = n * n;

	for (long long x = -n; x <= n; ++x) {
		long long y = getRoot(d - x * x);
		a[0] = -y;
		a[1] = -y + 1;
		a[2] = y - 1;
		a[3] = y;
		sort(a, a + 4);
		int m = unique(a, a + 4) - a;
		for (int i = 0; i < m; ++i) {
			if (isGood(x, a[i], d)) {
				++res;
			}
		}
	}
	return res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	long long n;
	cin >> n;

	long long res = 0;
	long long d = n * n;

	long long y = n;

	//int start = clock();
	for (long long x = 0; x <= n; ++x) {
		long long py = y;
		while (x * x + y * y > d) {
			--y;
		}

		++res;
		if (py > y) {
			res += py - y - 1;
		}
	}

	if (n == 0) {
		cout << 1 << endl;
	} else {
		cout << (res - 1) * 4LL << endl;
	}
	//cout << solve2(n) << endl;
	//cerr << clock() - start << endl;

	return 0;
}