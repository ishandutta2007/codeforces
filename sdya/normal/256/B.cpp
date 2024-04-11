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
#pragma comment (linker, "/STACK:256000000")

using namespace std;

long long n, x, y, c;

long long calc(long long x, long long t) {
	long long res = 0;
	if (x - t > 1) {
		res += n * (x - t - 1);
	}

	{
		long long left_bound = max(0LL, y + t - n + 1LL);
		long long right_bound = min(min(t, x - 1), 1LL + t - y);
		if (left_bound <= right_bound) {
			long long len = right_bound - left_bound + 1;
			res += n * len - (y + t) * len + (left_bound + right_bound) * len / 2LL;
		}
	}
	{
		long long left_bound = max(0LL, 2LL - y + t);
		long long right_bound = min(min(t, x - 1), y + t - n);
		if (left_bound <= right_bound) {
			long long len = right_bound - left_bound + 1;
			res += (y - t - 1LL) * len + (left_bound + right_bound) * len / 2LL;
		}
	}
	{
		long long left_bound = max(0LL, max(2LL + t - y, y + t - n + 1LL));
		long long right_bound = min(t, x - 1);

		if (left_bound <= right_bound) {
			long long len = right_bound - left_bound + 1;
			res += (n - 2LL * t - 1LL) * len + (left_bound + right_bound) * len;
		}
	}
	return res;
}

bool check(long long t) {
	long long a = y - t, b = y + t;
	long long left_bound = max(1LL, a);
	long long right_bound = min(n, b);

	long long added = (left_bound - 1) + (n - right_bound);
	long long score = calc(x, t) + calc(n + 1 - x, t) - added;
	return n * n - score >= c;
}

long long trivial() {
	for (int i = 0; i <= n + n; ++i) {
		long long value = 0;
		for (int j = 1; j <= n; ++j) {
			for (int k = 1; k <= n; ++k) {
				if (abs(j - x) + abs(k - y) <= i) {
					++value;
				}
			}
		}
		if (value >= c) {
			return i;
		}
	}
	return -1;
}

long long solve() {
	long long left_bound = 0, right_bound = 2 * n;
	while (right_bound - left_bound > 1) {
		long long middle = (left_bound + right_bound) / 2;
		if (check(middle)) {
			right_bound = middle;
		} else {
			left_bound = middle;
		}
	}

	if (check(left_bound)) {
		return left_bound;
	} else {
		return right_bound;
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n >> x >> y >> c;
	cout << solve() << endl;

	/*for (n = 1; n <= 10; ++n) {
		for (x = 1; x <= n; ++x) {
			for (y = 1; y <= n; ++y) {
				for (c = 1; c <= n * n; ++c) {
					if (trivial() != solve()) {
						cerr << n << " " << x << " " << y << " " << c << endl;
						return 0;
					}
				}
			}
		}
	}*/

	

	return 0;
}