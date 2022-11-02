#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <functional>
#pragma warning(disable : 4996)
using namespace std;
int n, p, q, a[100009];
int main() {
	scanf("%d%d%d", &n, &p, &q);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	sort(a, a + n, greater<int>());
	if (p > q) swap(p, q);
	long long s1 = 0, s2 = 0;
	for (int i = 0; i < n; i++) {
		if (i < p) s1 += a[i];
		else if (i < p + q) s2 += a[i];
	}
	printf("%.12lf\n", 1.0 * s1 / p + 1.0 * s2 / q);
	return 0;
}