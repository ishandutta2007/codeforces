#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <bitset>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

long long best = 1, rx = 0, ry = 0, rz = 0;
long long x, y, z, k;

void check(long long a, long long b, long long c) {
	if ((a + 1) * (b + 1) * (c + 1) > best) {
		best = (a + 1) * (b + 1) * (c + 1);
		rx = a;
		ry = b;
		rz = c;
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	long long x, y, z, k;
	cin >> x >> y >> z >> k;

	
	for (long long a = 0; a < x && a <= k; ++a) {
		long long rest = k - a;
		long long b = rest / 2;
		long long c = rest - b;

		b = min(b, y - 1);
		c = min(c, z - 1);
		check(a, b, c);

		for (long long b = min(y - 1, rest); b >= 0 && b >= min(y - 1, rest) - 20; --b) {
			long long c = rest - b;
			c = min(c, z - 1);
			if (c >= 0) {
				check(a, b, c);
			}
		}
		for (long long c = min(z - 1, rest); c >= 0 && c >= min(z - 1, rest) - 20; --c) {
			long long b = rest - c;
			b = min(b, y - 1);
			if (b >= 0) {
				check(a, b, c);
			}
		}
	}
	cout << best << endl;
	
	return 0;
}