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

long long powmod(long long a, long long n, long long p) {
	a %= p;
	if (n == 0) {
		return 1LL % p;
	}

	long long b = powmod(a, n / 2, p);
	b = (b * b) % p;
	if (n % 2 == 1) {
		b = (b * a) % p;
	}
	return b;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	long long res = powmod(3LL, n, m);
	res += (m - 1);
	res %= m;
	cout << res << endl;

	return 0;
}