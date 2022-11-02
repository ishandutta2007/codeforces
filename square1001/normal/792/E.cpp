#include <cmath>
#include <cstdio>
#include <algorithm>
#pragma warning(disable : 4996)
using namespace std;
int n, a[509], r[100009];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	int t = sqrt(a[0]), c = 0;
	for (int i = 1; i <= t; i++) {
		r[c++] = a[0] / i;
		if (a[0] % i == 0) r[c++] = a[0] / i - 1;
	}
	int z = r[c - 1] - 1;
	for (int i = 1; i <= z; i++) {
		if (a[0] <= a[0] / i * (i + 1)) r[c++] = i;
	}
	sort(r, r + c);
	for (int i = c - 1; i >= 0; i--) {
		bool f = true;
		for (int j = 0; j < n; j++) {
			if (a[j] > a[j] / r[i] * (r[i] + 1)) f = false;
		}
		if (f) {
			long long ret = 0;
			for (int j = 0; j < n; j++) ret += (a[j] + r[i]) / (r[i] + 1);
			printf("%lld\n", ret);
			break;
		}
	}
	return 0;
}