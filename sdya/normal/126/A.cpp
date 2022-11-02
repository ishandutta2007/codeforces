#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <set>
#include <map>
#include <queue>
#include <stack>

using namespace std;

long long t1, t2, x1, x2, t0;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> t1 >> t2 >> x1 >> x2 >> t0;
	if (t1 == t2) {
		cout << x1 << " " << x2 << endl;
		return 0;
	}
	long long A = (t2 - t0);
	long long B = (t2 - t1);
	long long p = 1000000000LL, q = 1LL;
	long long by1, by2;
	for (long long i = 0; i <= x1 + x2; i ++) {
		long long y1 = (A * i) / B;
		if (y1 > x1) y1 = x1;
		long long y2 = i - y1;
		if (y2 > x2) continue;
		long long np = t1 * y1 + t2 * y2;
		long long nq = y1 + y2;
		if (np * q <= p * nq) {
			p = np;
			q = nq;
			by1 = y1;
			by2 = y2;
		}
	}
	cout << by1 << " " << by2 << endl;
	return 0;
}