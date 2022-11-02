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

const long long P = 1000000009LL;
long long n, m, k;

long long powmod(long long a, long long n) {
	if (n == 0) {
		return 1LL % P;
	}
	long long b = powmod(a, n / 2);
	b = (b * b) % P;
	if (n % 2 == 1) {
		b = (b * a) % P;
	}
	return b;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n >> m >> k;
	long long r = n - m;
	if ((k - 1) * (r + 1) >= m) {
		cout << m << endl;
		return 0;
	}

	long long have = m - r * (k - 1);
	long long total = have / k;
	long long res = (powmod(2LL, total + 1) + P - 2) % P;
	res *= k;
	res %= P;

	res += have % k;
	res += r * (k - 1);
	res %= P;
	cout << res << endl;

	return 0;
}