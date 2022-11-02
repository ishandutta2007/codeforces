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
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110000;
long long gcd(long long a, long long b) {
	if (a < 0) {
		return gcd(-a, b);
	}
	if (b < 0) {
		return gcd(a, -b);
	}
	if (a == 0 || b == 0) {
		return a + b;
	}
	if (a > b) {
		return gcd(a % b, b);
	} else {
		return gcd(b % a, a);
	}
}

int n, x[maxN], y[maxN];

long long value(long long x1, long long y1, long long x2, long long y2) {
	return x1 * y2 - x2 * y1;
}

long double pw[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &x[i], &y[i]);
	}

	long double area = 0.0;
	for (int i = 0; i < n; ++i) {
		area += value(x[i], y[i], x[(i + 1) % n], y[(i + 1) % n]);
	}
	area = fabs(area);
	area /= 2.0;

	long double res = 1.0 + area;
	pw[0] = 1.0;
	for (int i = 1; i < 300; ++i) {
		pw[i] = pw[i - 1] + pw[i - 1];
	}
	if (n <= 200) {
		long double N = n;
		long double T = 2.0;
		long double total = pw[n] - 1.0 - N - N * (N - 1.0) / 2.0;
		res -= 0.5 * N * (pw[n - 1] - 1.0 - (N - 1)) / total;
		for (int i = 0; i < n; ++i) {
			long double s1 = 0.0, s2 = area;
			for (int j = i + 1; j < n; ++j) {
				long long G = gcd(x[j] - x[i], y[j] - y[i]) - 1;

				long double p1 = pw[n - (j - i + 1)] - 1.0;
				long double p2 = pw[n - (i + n - j + 1)] - 1.0;
				p1 /= total;
				p2 /= total;

				res -= p1 * s1;
				res -= p2 * s2;

				res -= (p1 + p2) * (long double)(G) / 2.0;

				long double v = 0.0;
				if (j + 1 < n) {
					v = value(x[j] - x[i], y[j] - y[i], x[j + 1] - x[i], y[j + 1] - y[i]);
					v = fabs(v) / 2.0;
				}
				s1 += v;
				s2 -= v;
			}
		}
	} else {
		long double T = 2.0;
		const int maxD = 70;
		long double N = n;
		res -= 0.25 * N;
		for (int i = 0; i < n; ++i) {
			long double s1 = 0.0, s2 = area;
			for (int j = i + 1; j < i + maxD; ++j) {
				long long G = gcd(x[j % n] - x[i], y[j % n] - y[i]) - 1;

				long double p1 = (long double)(1.0) / pw[j - i + 1];

				res -= p1 * s1;

				res -= (p1) * (long double)(G) / 2.0;

				long double v = 0.0;
				v = value(x[j % n] - x[i], y[j % n] - y[i], x[(j + 1) % n] - x[i], y[(j + 1) % n] - y[i]);
				v = fabs(v) / 2.0;
				s1 += v;
				s2 -= v;
			}
		}
	}
	printf("%.10lf\n", (double)(res));


	return 0;
}