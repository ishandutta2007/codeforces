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
#pragma comment (linker, "/STACK:256000000")

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	vector < double > p(n), q(n);
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
		if (fabs(p[i] - 1.0) < 1e-9) {
			printf("%.10lf\n", 1.0);
			return 0;
		}
	}

	sort(p.begin(), p.end());
	for (int i = 0; i < n; ++i) {
		q[i] = p[i] / (1.0 - p[i]);
	}
	double res = 0.0;
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			double u = 1.0, v = 0.0;
			for (int k = i; k <= j; ++k) {
				u *= (1.0 - p[k]);
				v += q[k];
			}
			res = max(res, u * v);
		}
	}

	printf("%.10lf\n", res);


	return 0;
}