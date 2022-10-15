#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>

#define SQR(x) ((x) * (x))
#define ABS(x) ((x) < 0 ? -(x) : (x))
#define LOWBIT(x) ((x) & -(x))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define SWAP(x, y) ((x) ^= (y), (y) ^= (x), (x) ^= (y))
#define MAXINT 2147483647
#define MAXLOL 9223372036854775807LL
#define INF MAXINT
#define lol long long
#define lod long double

lol gcd(lol a, lol b) {
	return b == 0 ? a : gcd(b, a % b);
}

int n;
lol a, b, c;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%I64d%I64d%I64d", &a, &b, &c);
		b /= gcd(a, b);
		while (true) {
			c = gcd(b, c);
			if (c == 1) {
				printf("%s\n", b == 1 ? "Finite" : "Infinite");
				break;
			} else {
				while (b % c == 0) {
					b /= c;
				}
			}
		}
	}
	return 0;
}

// By Sooke.
// CF983A Finite or not?