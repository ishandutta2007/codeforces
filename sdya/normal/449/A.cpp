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

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	long long n, m, k;
	cin >> n >> m >> k;
	if (k > (n - 1) + (m - 1)) {
		cout << -1 << endl;
		return 0;
	}

	long long res = -1;
	if (k <= 5000000) {
		for (long long a = 0; a <= k; ++a) {
			long long b = k - a;
			if (a > n - 1 || b > m - 1) {
				continue;
			}

			res = max(res, (n / (a + 1)) * (m / (b + 1)));
		}
	} else {
		for (int i = 0; i < 2; ++i) {
			for (long long x = 1; x <= 1000; ++x) {
				long long a = min(min(k, n - 1), n / x - 1);
				if (a < 0 || a > n - 1) {
					continue;
				}
				long long b = k - a;
				if (b < 0 || b > m - 1) {
					continue;
				}
				res = max(res, (n / (a + 1)) * (m / (b + 1)));
			}
			swap(n, m);
		}
	}

	cout << res << endl;

	return 0;
}