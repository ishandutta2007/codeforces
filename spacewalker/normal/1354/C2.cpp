#include <bits/stdc++.h>

using namespace std;

int main() {
	double PI = 2 * acos(0);
	int t; scanf("%d", &t);
	while (t--) {
		int n;	scanf("%d", &n);
		vector<pair<double, double>> arcPoints(n + 1);
		for (int shift = n / 2, i = 1; shift >= -n/2; --shift, ++i) {
			arcPoints[i].first = arcPoints[i-1].first + cos(PI / n * shift);
			arcPoints[i].second = arcPoints[i-1].second + sin(PI / n * shift);
//			printf("PT %d %.6lf %.6lf\n", i, arcPoints[i].first, arcPoints[i].second);
		}
		double pBase = 0;
		for (int i = 0; i < n; ++i) pBase = min(pBase, arcPoints[i].first - arcPoints[i].second);
//		printf("%.8lf\n", pBase);
		printf("%.8lf\n", ((-pBase * 2) + arcPoints[n].first) * sin(PI/4));
	}
	return 0;
}