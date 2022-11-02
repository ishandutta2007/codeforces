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
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 210000;
const int maxD = 10;
int n, k;
int a[maxN];
long long p[maxD];

long long p2[maxD][maxN];
long long x[maxD][maxN], y[maxD][maxN];
long long v[maxD][maxN];

long long w[maxD];

bool isPrime(long long n) {
	for (long long i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

long long inv(long long a, long long p) {
	long long x1 = 1, b1 = a;
	long long x2 = 0, b2 = p;
	while (b2) {
		long long q = b1 / b2;
		b1 -= q * b2;
		x1 -= q * x2;
		swap(b1, b2);
		swap(x1, x2);
	}
	x1 %= p;
	if (x1 < 0) {
		x1 += p;
	}
	return x1;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &k);
	++n;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}

	int m = 0;
	for (long long i = 2000248198 + (rand() % 1000); m < maxD; ++i) {
		if (isPrime(i)) {
			p[m++] = i;
		}
	}

	for (int i = 0; i < maxD; ++i) {
		p2[i][0] = 1LL % p[i];
		for (int j = 1; j < maxN; ++j) {
			p2[i][j] = (2LL * p2[i][j - 1]) % p[i];
		}
	}

	for (int i = 0; i < maxD; ++i) {
		for (int j = 0; j < n; ++j) {
			v[i][j] = ((long long)(a[j]) * p2[i][j]) % p[i];
		}

		for (int j = 0; j < n; ++j) {
			x[i][j] = v[i][j];
			if (j > 0) {
				x[i][j] += x[i][j - 1];
				x[i][j] %= p[i];
			}
		}
		for (int j = n - 1; j >= 0; --j) {
			y[i][j] = v[i][j];
			if (j + 1 < n) {
				y[i][j] += y[i][j + 1];
				y[i][j] %= p[i];
			}
		}
	}

	long long ways = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < maxD; ++j) {
			w[j] = (i > 0 ? x[j][i - 1] : 0) + (i + 1 < n ? y[j][i + 1] : 0);
			w[j] %= p[j];
		}

		long long value = (- w[0] * inv(p2[0][i], p[0])) % p[0];
		value = ((value % p[0]) + p[0]) % p[0];

		if (value > (long long)(k)) {
			value -= p[0];
		}

		if (i + 1 == n && value == 0) {
			continue;
		}

		if (value >= (long long)(-k) && value <= (long long)(k)) {
			bool isOk = true;
			for (int j = 0; j < maxD; ++j) {
				long long r = (w[j] + (p2[j][i] * value)) % p[j];
				if (r != 0) {
					isOk = false;
					break;
				}
			}
			if (isOk) {
				++ways;
			}
		}
	}
	cout << ways << endl;

	return 0;
}