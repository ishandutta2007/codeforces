#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>

using namespace std;

#define forn(i,n) for (int i = 0; i < (int)(n); i++)
#define ford(i,n) for (int i = (int)(n) - 1; i >= 0; i--)

long long di(long long a, long long b) {
	long long c = a % b;
	if (c < 0) {
		c += b;
	}
	return (a - c) / b;
}

long long ab(long long a) {
	return a < 0 ? -a : a;
}

long long ma(long long a, long long b) {
	return a < b ? b : a;
}

int main() {
	long long a, b, x1, y1, x2, y2;
	cin >> a >> b >> x1 >> y1 >> x2 >> y2;
	cout << ma(ab(di(x1 + y1, 2 * a) - di(x2 + y2, 2 * a)), ab(di(x1 - y1, 2 * b) - di(x2 - y2, 2 * b)));
}