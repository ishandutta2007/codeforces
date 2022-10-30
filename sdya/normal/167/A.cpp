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

const int maxN = 110000;
int t[maxN], v[maxN];

double getTime(double d, double v, double a) {
	double left_bound = 0.0, right_bound = 1e9;
	for (int i = 1; i <= 80; ++i) {
		double middle = (left_bound + right_bound) / 2.0;
		double ta = v / a;
		
		double length = 0.0;
		double p = min(ta, middle);
		length += a / 2.0 * p * p;
		length += (middle - p) * v;
		if (length > d) {
			right_bound = middle;
		} else {
			left_bound = middle;
		}
	}
	return (left_bound + right_bound) / 2.0;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, a, d;
	cin >> n >> a >> d;
	double current = 0.0;
	for (int i = 1; i <= n; ++i) {
		cin >> t[i] >> v[i];
		double value = getTime(d, v[i], a);
		if (value + (double)(t[i]) < current) {
			printf("%.10lf\n", current);
		} else {
			printf("%.10lf\n", value + (double)(t[i]));
			current = value + (double)(t[i]);
		}
	}


	return 0;
}