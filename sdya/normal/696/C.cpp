#define _CRT_SECURE_NO_WARNINGS
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
#include <unordered_map>
#include <unordered_set>
#include <list>
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
		swap(b1, b2);
		swap(x1, x2);
	}
	return ((x1 % P) + P) % P;
}

long long powmod(long long a, long long n) {
	if (n == 0) {
		return 1;
	}
	long long b = powmod(a, n / 2);
	b = (b * b) % P;
	if (n % 2 == 0) {
		return b;
	}
	return (a * b) % P;
}

const int maxN = 110000;
long long d[maxN][3];

int n;
long long a[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	bool even = false;
	for (int i = 0; i < n; ++i) {
		scanf("%I64d", &a[i]);
		if (a[i] % 2 == 0) {
			even = true;
		}
		a[i] %= (P - 1);
	}

	long long p = 1;
	for (int i = 0; i < n; ++i) {
		p = (p * a[i]) % (P - 1);
	}

	long long u = powmod(2LL, p);
	if (even) {
		u -= 1;
	} else {
		u -= 2;
	}

	u = (u * inv(3)) % P;
	if (even) {
		++u;
	}

	u = (u * inv(2)) % P;
	u = ((u % P) + P) % P;

	long long v = powmod(2LL, p);
	v = (v * inv(2)) % P;

	printf("%d/%d\n", (int)(u), (int)(v));

	/*d[0][1] = 1;
	for (int i = 0; i < 100; ++i) {
		d[i + 1][0] = d[i][0] + d[i][1];
		d[i + 1][1] = d[i][0] + d[i][2];
		d[i + 1][2] = d[i][1] + d[i][2];

		//printf("%d: %I64d %I64d %I64d\n", i + 1, d[i + 1][0], d[i + 1][1], d[i + 1][2]);
	}*/


	return 0;
}