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
#pragma comment (linker, "/STACK:256000000")

using namespace std;

long long gcd(long long a, long long b) {
	if (a == 0 || b == 0) {
		return a + b;
	}
	if (a > b) {
		return gcd(a % b, b);
	} else {
		return gcd(b % a, a);
	}
}

long long lcm(long long a, long long b) {
	return (a / gcd(a, b)) * b;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	long long n;
	cin >> n;
	long long res = 0;
	for (long long i = max(1LL, n - 10LL); i <= n; ++i) {
		for (long long j = max(1LL, n - 10LL); j <= n; ++j) {
			for (long long k = max(1LL, n - 10LL); k <= n; ++k) {
				long long L = lcm(i, lcm(j, k));
				res = max(res, L);
			}
		}
	}
	cout << res << endl;


	return 0;
}