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

long long powmod(long long a, long long n, long long p) {
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

long long inv(int a, int p) {
	int x1 = 1, b1 = a;
	int x2 = 0, b2 = p;
	while (b2) {
		int q = b1 / b2;
		b1 -= q * b2;
		x1 -= q * x2;
		swap(x1, x2);
		swap(b1, b2);
	}
	x1 %= p;
	if (x1 < 0) {
		x1 += p;
	}
	return x1;
}

long long calculate(long long x, long long n, long long p) {
	x %= p;
	if (x == 1) {
		return powmod(2LL, n + 1, p);
	}

	long long rem = powmod(2LL, n + 1, p - 1);
	long long A = (powmod(x, rem, p) + p - 1) % p;
	long long B = inv(x - 1, p);
	return (A * B) % p;
}

void solve() {
	long long k;
	long long l, r;
	long long p;
	scanf("%I64d%I64d%I64d%I64d", &k, &l, &r, &p);
	if (p == 2) {
		if (k % 2 == 0) {
			printf("1\n");
		} else {
			printf("0\n");
		}
		return ;
	}
	long long rem = powmod(2LL, l, p - 1);
	long long x = powmod(k, rem, p);

	// trivial
	/*{
		long long score = 1LL;
		for (long long i = l; i <= r; ++i) {
			long long rem = powmod(2, i, p - 1);
			long long value = (powmod(k, rem, p) + 1) % p;
			score *= value;
			score %= p;
		}
		if (k % 2 == 1) {
			score *= inv(powmod(2LL, r - l, p), p);
		}
		score %= p;
		cout << score << endl;
	}*/

	long long score = calculate(x, r - l, p);
	if (k % p == 0) {
		score = 1;
	}
	if (k % 2 == 0) {
		printf("%d\n", (int)(score % p));
	} else {
		if (p == 2LL) {
			printf("0\n");
		} else {
			score *= inv(powmod(2LL, r - l, p), p);
			score %= p;
			printf("%d\n", (int)(score));
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		solve();
	}
	//cerr << clock() << endl;

	return 0;
}