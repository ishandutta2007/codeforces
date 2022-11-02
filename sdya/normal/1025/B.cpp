#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

long long gcd(long long a, long long b) {
	if (a == 0 || b == 0) return a + b;
	return a > b ? gcd(a % b, b) : gcd(b % a, a);
}

long long lcm(long long a, long long b) {
	return a / gcd(a, b) * b;
}

const int maxN = 160000;
int n;
int a[maxN], b[maxN];

int main() {
	scanf("%d", &n);
	long long g = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &a[i], &b[i]);
		g = gcd(g, lcm(a[i], b[i]));
	}

	for (long long i = 2; i <= 1000000; ++i) {
		if (g % i == 0) {
			printf("%d\n", (int)(i));
			return 0;
		}
	}
	for (int i = 0; i < n; ++i) {
		if (g % a[i] == 0) {
			printf("%d\n", a[i]);
			return 0;
		}
		if (g % b[i] == 0) {
			printf("%d\n", b[i]);
			return 0;
		}
	}
	if (g > 1) {
		printf("%d\n", (int)(g));
	} else {
		printf("-1\n");
	}

	return 0;
}