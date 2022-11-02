#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <cmath>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 1100000;
long long a[maxN], s[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	long long k, b, n, t;
	cin >> k >> b >> n >> t;
	long long res = n;
	a[0] = 1LL;
	for (int i = 1; i < maxN; ++i) {
		a[i] = a[i - 1] * k;
	}
	for (int i = 0; i < maxN; ++i) {
		s[i] = a[i];
		if (i > 0) {
			s[i] += s[i - 1];
		}
	}
	for (long long m = n - 1; m >= 0; --m) {
		long long sum = s[n - m - 1], p = a[n - m];
		if (t >= sum * b + p) {
			res = m;
		} else {
			break;
		}
	}

	cout << res << endl;

	return 0;
}