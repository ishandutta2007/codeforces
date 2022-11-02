#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

const int maxN = 60000;
int a[maxN], p[maxN], s[maxN], n;
int order[maxN];

bool compare(int x, int y) {
	return p[x] * a[x] * (100 - p[y]) > p[y] * a[y] * (100 - p[x]);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", &a[i], &p[i]);
		order[i] = i;
	}
	sort(order + 1, order + n + 1, compare);
	for (int i = 1; i <= n; ++i) {
		s[i] = s[i - 1] + (100 - p[order[i]]);
	}

	double res = 0.0;
	for (int i = 1; i <= n; ++i) {
		res += (double)(a[order[i]]);
		double value = (double)(p[order[i]]) / 100.0 * (double)(s[n] - s[i]) / 100.0; 
		res += (double)(a[order[i]]) * value;
	}

	printf("%.10lf\n", res);

	return 0;
}