#define _CRT_SECURE_NO_WARNINGS
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
#include <list>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110000;
int ax, ay, bx, by, tx, ty;
int x[maxN], y[maxN], n;
double d[maxN];
pair < double, int > a[maxN], b[maxN];

double dist(double x1, double y1, double x2, double y2) {
	return hypot(x1 - x2, y1 - y2);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d%d%d%d%d", &ax, &ay, &bx, &by, &tx, &ty);
	scanf("%d", &n);
	double res = 0.0;
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &x[i], &y[i]);
		double D = dist(x[i], y[i], tx, ty);
		d[i] = 2.0 * D;
		a[i] = make_pair(dist(x[i], y[i], ax, ay) - D, i);
		b[i] = make_pair(dist(x[i], y[i], bx, by) - D, i);

		res += d[i];
	}

	sort(a, a + n);
	sort(b, b + n);

	double ans = 1e30;
	ans = min(ans, res + a[0].first);
	ans = min(ans, res + b[0].first);
	for (int i = 0; i < min(n, 5); ++i) {
		for (int j = 0; j < min(n, 5); ++j) {
			if (a[i].second != b[j].second) {
				ans = min(ans, res + a[i].first + b[j].first);
			}
		}
	}

	printf("%.10lf\n", ans);

	return 0;
}