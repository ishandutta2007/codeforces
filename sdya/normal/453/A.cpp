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

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int m, n;
	cin >> m >> n;

	vector < double > r(m + 1, 0.0);
	for (int i = m; i >= 1; --i) {
		double p = (double)(i) / (double)(m);
		r[i] = pow(p, n);
	}

	double res = 0.0;
	for (int i = m; i >= 1; --i) {
		r[i] -= r[i - 1];
		res += r[i] * (double)(i);
	}

	printf("%.10lf\n", res);

	return 0;
}