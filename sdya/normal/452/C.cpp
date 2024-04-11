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
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 1100;
long double f[maxN * maxN];

double calc(int n, int k) {
	return f[n] - f[k] - f[n - k];
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	for (int i = 1; i < maxN * maxN; ++i) {
		f[i] = f[i - 1] + log((long double)(i));
	}

	int n, m;
	cin >> n >> m;

	long double res = 0.0;
	for (int k = 1; k <= n && k <= m; ++k) {
		long double a = calc(m, k) + calc(m * (n - 1), n - k) - calc(m * n, n);
		long double w = exp(a);
		long double p = (long double)(k) / (long double)(n);
		res += w * p * p;
	}
	res *= (long double)(n);
	printf("%.10lf\n", (double)(res));

	return 0;
}