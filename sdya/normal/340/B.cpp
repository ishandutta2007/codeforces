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

long long area(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3) {
	long long res = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
	return res > 0 ? res : -res;
}

const int maxN = 500;
long long x[maxN], y[maxN];
int n;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
	}

	long long res = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			long long A = y[i] - y[j];
			long long B = x[j] - x[i];
			long long C = x[i] * y[j] - x[j] * y[i];

			long long u = -1e18, v = -1e18;
			for (int k = 0; k < n; ++k) {
				long long D = A * x[k] + B * y[k] + C;
				long long a = area(x[i], y[i], x[j], y[j], x[k], y[k]);
				if (D > 0) {
					u = max(u, a);
				}
				if (D < 0) {
					v = max(v, a);
				}
			}
			res = max(res, u + v);
		}
	}
	printf("%.10lf\n", (double)(res) / 2.0);

	return 0;
}