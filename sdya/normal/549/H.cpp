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

pair < double, double > get(double la, double ra, double lb, double rb) {
	double mn = 1e20;
	double mx = -1e20;

	vector < double > a;
	a.push_back(la);
	a.push_back(ra);
	if (la <= 0.0 && ra >= 0.0) {
		a.push_back(0.0);
	}

	vector < double > b;
	b.push_back(lb);
	b.push_back(rb);
	if (lb <= 0.0 && rb >= 0.0) {
		b.push_back(0.0);
	}

	for (int i = 0; i < a.size(); ++i) {
		for (int j = 0; j < b.size(); ++j) {
			mn = min(mn, a[i] * b[j]);
			mx = max(mx, a[i] * b[j]);
		}
	}
	return make_pair(mn, mx);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	double a, b, c, d;
	cin >> a >> b >> c >> d;

	double left_bound = 0.0, right_bound = 1e20;
	for (int i = 0; i < 100; ++i) {
		double middle = (left_bound + right_bound) / 2.0;
		double la = a - middle, ra = a + middle;
		double lb = b - middle, rb = b + middle;
		double lc = c - middle, rc = c + middle;
		double ld = d - middle, rd = d + middle;


		pair < double, double > A = get(la, ra, ld, rd);
		pair < double, double > B = get(lb, rb, lc, rc);

		double L = max(A.first, B.first);
		double R = min(A.second, B.second);
		if (L <= R) {
			right_bound = middle;
		} else {
			left_bound = middle;
		}
	}
	printf("%.10lf\n", (left_bound + right_bound) / 2.0);

	return 0;
}