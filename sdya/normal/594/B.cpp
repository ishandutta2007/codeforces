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

int n, r, v;

bool solve(double t, double R, double V, double L) {
	double a = (t * V) / (2.0 * R);

	double A = 2.0 * sin(-a);
	double B = (L - t * V) / R;

	if (fabs(a) < 1e-16) {
		return L <= t * V;
	}

	if (A >= 0) {
		return (L - t * V) / R / A <= 1.0;
	}
	return (L - t * V) / R / A >= -1.0;
}

void solve() {
	int f, s;
	scanf("%d%d", &s, &f);

	double l = 0.0, r = 1e12;
	for (int i = 0; i < 60; ++i) {
		double m = (l + r) / 2.0;
		if (solve(m, ::r, ::v, f - s)) {
			r = m;
		} else {
			l = m;
		}
	}
	printf("%.10lf\n", (l + r) / 2.0);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &r, &v);
	//n = 10000;
	//r = 2;
	//v = 3;
	for (int i = 0; i < n; ++i) {
		solve();
	}

	cerr << clock() << endl;


	return 0;
}