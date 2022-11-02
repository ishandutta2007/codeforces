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
#include <unordered_map>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const long long inf = 1000000000000000000LL;

long long getB(long long x, long long y, long long b) {
	long long c = x - y;
	long long d = c / b;

	long long mn = -inf;
	long long mx = inf;

	for (long long i = d - 2; i <= d + 2; ++i) {
		if (i * b >= c) {
			mx = min(i, mx);
		}
		if (i * b <= c) {
			mn = max(mn, i);
		}
	}
	return mn;
}

long long getA(long long x, long long y, long long a) {
	long long c = x + y;
	long long d = c / a;

	long long mn = -inf;
	long long mx = inf;

	for (long long i = d - 2; i <= d + 2; ++i) {
		if (i * a >= c) {
			mx = min(i, mx);
		}
		if (i * a <= c) {
			mn = max(mn, i);
		}
	}
	return mn;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	long long a, b, x1, y1, x2, y2;
	cin >> a >> b >> x1 >> y1 >> x2 >> y2;

	long long res = 0;
	long long u1 = getA(x1, y1, 2LL * a);
	long long v1 = getB(x1, y1, 2LL * b);

	long long u2 = getA(x2, y2, 2LL * a);
	long long v2 = getB(x2, y2, 2LL * b);

	long long dx = u1 - u2;
	long long dy = v1 - v2;
	if (dx < 0) {
		dx = -dx;
	}
	if (dy < 0) {
		dy = -dy;
	}

	cout << (dx > dy ? dx : dy) << endl;


	return 0;
}