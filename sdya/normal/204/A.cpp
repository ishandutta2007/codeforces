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

long long solve(long long n) {
	if (n == 0) {
		return 0;
	}
	long long res = 0;
	for (long long length = 1; length <= 18; ++length) {
		for (long long a = 1; a <= 9; ++a) {
			long long p = 1LL;
			for (int i = 1; i < length; ++i) {
				p *= 10LL;
			}

			if (length == 1) {
				if (a <= n) {
					++res;
				}
				continue;
			}
			if (length == 2) {
				if (a * 10LL + a <= n) {
					++res;
				}
				continue;
			}

			long long value = a * p + a;
			if (value > n) {
				continue;
			}
			long long bound = p / 10LL - 1LL;
			bound = min(bound, (n - value) / 10LL);
			res += bound + 1;
		}
	}
	return res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	long long l, r;
	cin >> l >> r;
	long long res = solve(r) - solve(l - 1);
	cout << res << endl;


	return 0;
}