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

int naive(int n, int m) {
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			if (i + j == m) {
				++res;
			}
		}
	}
	return res;
}

long long correct(long long n, long long m) {
	if (m >= 2 * n) {
		return 0;
	}

	long long x = 1, y = m - 1;
	if (y > n) {
		x += y - n;
		y = n;
	}

	if (x > n || y < 1) {
		return 0;
	}

	long long res = min(n - x + 1, y);
	if (m % 2 == 0 && m / 2 <= n) {
		--res;
	}
	res /= 2;
	return res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	/*for (int n = 1; n <= 1000; ++n) {
		cerr << n << endl;
		for (int m = 1; m <= 10000; ++m) {
			if (naive(n, m) != correct(n, m)) {
				cerr << n << " " << m << endl;
				cerr << naive(n, m) << " " << correct(n, m) << endl;
				exit(0);
			}
		}
	}*/

	long long n, m;
	cin >> n >> m;

	cout << correct(n, m) << endl;



	return 0;
}