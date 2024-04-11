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
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const long long P = 1000000007LL;

long long inv(long long a) {
	long long x1 = 1, b1 = a;
	long long x2 = 0, b2 = P;
	while (b2) {
		long long q = b1 / b2;
		b1 -= q * b2;
		x1 -= q * x2;
		swap(x1, x2);
		swap(b1, b2);
	}
	return ((x1 % P) + P) % P;
}

long long cnk(long long n, long long k) {
	long long res = 1;
	for (int i = 1; i <= k; ++i) {
		res *= (n + 1 - i);
		res %= P;
		res *= inv(i);
		res %= P;
	}
	return res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	long long n;
	cin >> n;
	long long res = 2LL * cnk(n + n - 1, n);
	res += (P - n);
	res %= P;
	cout << res << endl;

	return 0;
}