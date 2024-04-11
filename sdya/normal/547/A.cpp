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
#include <complex>
#include <ctime>
#include <unordered_map>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

long long m;

long long getNext(long long h, long long x, long long y) {
	return (h * x + y) % m;
}

long long gcd(long long a, long long b) {
	if (a == 0 || b == 0) {
		return a + b;
	}
	if (a > b) {
		return gcd(a % b, b);
	}
	return gcd(b % a, a);
}

long long gcd(long long a, long long b, long long &x, long long &y) {
	long long x1 = 1, y1 = 0, b1 = a;
	long long x2 = 0, y2 = 1, b2 = b;
	while (b2) {
		long long q = b1 / b2;
		b1 -= q * b2;
		x1 -= q * x2;
		y1 -= q * y2;
		swap(b1, b2);
		swap(x1, x2);
		swap(y1, y2);
	}

	x = x1;
	y = y1;
	return b1;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> m;
	long long h1, a1;
	cin >> h1 >> a1;
	long long x1, y1;
	cin >> x1 >> y1;

	long long h2, a2;
	cin >> h2 >> a2;
	long long x2, y2;
	cin >> x2 >> y2;

	vector < int > u;
	vector < int > v;

	long long h = h1;
	for (int i = 1; i <= 2500000; ++i) {
		h = getNext(h, x1, y1);
		if (h == a1) {
			u.push_back(i);
		}
	}

	h = h2;
	for (int i = 1; i <= 2500000; ++i) {
		h = getNext(h, x2, y2);
		if (h == a2) {
			v.push_back(i);
		}
	}

	if (u.size() == 0 || v.size() == 0) {
		printf("-1\n");
		return 0;
	}

	if (u.size() == 1) {
		if (binary_search(v.begin(), v.end(), u[0])) {
			printf("%d\n", u[0]);
			return 0;
		}
		printf("-1\n");
		return 0;
	}
	if (v.size() == 1) {
		if (binary_search(u.begin(), u.end(), v[0])) {
			printf("%d\n", v[0]);
			return 0;
		}
		printf("-1\n");
		return 0;
	}

	long long s1 = u[0];
	long long p1 = u[1] - u[0];

	long long s2 = v[0];
	long long p2 = v[1] - v[0];

	for (long long i = 0; i <= 2500000; ++i) {
		if ((s1 + i * p1 - s2) % p2 == 0) {
			long long j = (s1 + i * p1 - s2) / p2;
			if (j >= 0) {
				printf("%I64d\n", s1 + i * p1);
				return 0;
			}
		}
	}
	printf("-1\n");

	return 0;
}