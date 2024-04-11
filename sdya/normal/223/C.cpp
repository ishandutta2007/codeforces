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

const int maxN = 2100;
long long r[maxN], w[maxN];
long long c[maxN];

long long cnk(int n, int k) {
	if (n < k) {
		return 0;
	}
	long long res = 1;
	for (int i = 1; i <= k; ++i) {
		res *= (long long)(n + 1 - i);
		res %= P;
		res *= r[i];
		res %= P;
	}
	return res;
}

int n, k, a[maxN];
long long s[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	r[0] = 1;
	for (int i = 1; i < maxN; ++i) {
		r[i] = inv(i);
		r[i] = (r[i] * r[i - 1]) % P;
	}

	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}

	if (k == 0) {
		for (int i = 0; i < n; ++i) {
			printf("%d ", (int)(a[i] % P));
		}
		printf("\n");
		return 0;
	} else if (k == 1) {
		for (int i = 0; i < n; ++i) {
			if (i > 0) {
				a[i] += a[i - 1];
				a[i] %= P;
			}
			printf("%d ", a[i]);
		}
		printf("\n");
		return 0;
	}

	w[0] = k;
	for (int i = 1; i < maxN; ++i) {
		w[i] = (w[i - 1] * (long long)(k + i));
		w[i] %= P;
	}

	c[0] = 1;
	for (int i = 0; i < n; ++i) {
		c[i + 1] = (w[i] * r[i + 1]) % P;
	}

	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			s[j] += c[j - i] * a[i];
			s[j] %= P;
		}
	}

	for (int i = 0; i < n; ++i) {
		printf("%d ", (int)(s[i]));
	}
	printf("\n");

	return 0;
}