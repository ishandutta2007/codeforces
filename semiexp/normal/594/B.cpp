#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define MOD
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

int N, R, V;

double yosupot(double a, double b)
{
	return sqrt(a * a + b * b);
}

double maxdist(double cdist, double rad)
{
	double theta = cdist / rad;
	return cdist + rad * yosupot(cos(theta) - 1, sin(theta));
}

double solve(double dist, double rad, double v)
{
	double left = 0, right = dist;
	for (int i = 0; i < 60; ++i) {
		double mid = (left + right) / 2;
		if (maxdist(mid, rad) >= dist) {
			right = mid;
		} else {
			left = mid;
		}
	}

	return left / V;
}

int main()
{
	scanf("%d%d%d", &N, &R, &V);
	for (int i = 0; i < N; ++i) {
		int l, r;
		scanf("%d%d", &l, &r);

		printf("%.10f\n", solve(r - l, R, V));
	}

	return 0;
}