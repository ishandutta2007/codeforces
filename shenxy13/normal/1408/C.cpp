#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	for (int h = 0; h < t; ++h) {
		int n, l;
		scanf("%d %d", &n, &l);
		int a[n], x1 = 0, x2 = n - 1;
		for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
		double p1 = 0, p2 = l, t = 0;
		while (x2 - x1 >= 0) {
			if ((p2 - a[x2]) / (n - x2) < (a[x1] - p1) / (x1 + 1)) t += (p2 - a[x2]) / (n - x2), p1 += (p2 - a[x2]) / (n - x2) * (x1 + 1), p2 = a[x2], --x2;
			else t += (a[x1] - p1) / (x1 + 1), p2 -= (a[x1] - p1) / (x1 + 1) * (n - x2), p1 = a[x1], ++x1;
		}
		t += (p2 - p1) / (n - x2 + x1 + 1);
		printf("%.9lf\n", t);
		/*int n, k;
		scanf("%d %d", &n, &k);
		int a[n], diff = 0;
		for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
		for (int i = 1; i < n; ++i) {
			if (a[i] != a[i - 1]) ++diff;
		}
		if (k == 1 && diff != 0) printf("-1\n");
		else if (k == 1) printf("1\n");
		else printf("%d\n", (diff + k - 2) / (k - 1));*/
	}
	return 0;
}