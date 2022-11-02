#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const int maxN = 110000;
const int maxS = 110;
int a[maxN], n;
double d[maxN][maxS];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		d[i][a[i]] = 1.0;
	}

	double res = 0.0;
	for (int i = 1; i <= n; ++i) {
		res += d[i][0];
	}

	int m;
	scanf("%d", &m);
	for (int i = 1; i <= m; ++i) {
		int u, v, k;
		scanf("%d%d%d", &u, &v, &k);

		res -= d[u][0];
		for (int j = 0; j <= 100 && j <= a[u]; ++j) {
			double total = 1.0, old = d[u][j];
			d[u][j] = 0.0;

			for (int c = 1; c <= k; ++c) {
				total *= (double)(a[u] + 1 - c);
				total /= (double)(c);
			}

			for (int unused = 0; unused <= k && unused <= j; ++unused) {
				if (k - unused > a[u] - j) {
					continue;
				}
				double ways = 1.0;
				for (int c = 1; c <= unused; ++c) {
					ways *= (double)(j + 1 - c);
					ways /= (double)(c);
				}

				for (int c = 1; c <= k - unused; ++c) {
					ways *= (double)(a[u] - j + 1 - c);
					ways /= (double)(c);
				}

				d[u][j - unused] += old * (ways / total);
			}
		}

		a[u] -= k;
		a[v] += k;

		res += d[u][0];
		printf("%.10lf\n", res);
	}

	return 0;
}