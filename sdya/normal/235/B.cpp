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
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110000;
double p[maxN];
int n;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%lf", &p[i]);
	}

	double res = 0.0;
	double x = p[1], y = p[1];
	res += x;

	for (int i = 2; i <= n; ++i) {
		x = (x + y) * p[i] + (1.0 - p[i - 1]) * p[i];
		y = y * p[i] + (1.0 - p[i - 1]) * p[i];
		res += x;
	}

	res *= 2.0;
	for (int i = 1; i <= n; ++i) {
		res -= p[i];
	}
	printf("%.10lf\n", res);


	return 0;
}