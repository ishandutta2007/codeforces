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

const double eps = 1e-12;

double solve(double A, double B, double C, double S, double sp, double sq) {
	double D = B * B - 4.0 * A * C;
	if (D < 0) {
		D = 0.0;
	}


	double x1 = (-B + sqrt(D)) / (2.0 * A);
	double x2 = (-B - sqrt(D)) / (2.0 * A);

	if (x1 >= -eps && x1 <= 1.0 + eps && (S - x1) >= -eps && (S - x1) <= 1.0 + eps && sp + x1 <= 1.0 + eps && sq + (S - x1) <= 1.0 + eps) {
		return x1;
	}
	return x2;
}

const int maxN = 110000;

double S[maxN], T[maxN];
int n;

double p[maxN], q[maxN];
double sp[maxN], sq[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%lf", &S[i]);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%lf", &T[i]);
	}

	p[0] = solve(1.0, -(S[0] + T[0]), S[0], S[0] + T[0], 0.0, 0.0);
	q[0] = S[0] + T[0] - p[0];

	sp[0] = p[0];
	sq[0] = q[0];
	for (int i = 1; i < n; ++i) {
		p[i] = solve(-1.0, sq[i - 1] - sp[i - 1] + S[i] + T[i], (S[i] + T[i]) * sp[i - 1] - S[i], S[i] + T[i], sp[i - 1], sq[i - 1]);
		q[i] = S[i] + T[i] - p[i];

		sp[i] = sp[i - 1] + p[i];
		sq[i] = sq[i - 1] + q[i];
	}

	for (int i = 0; i < n; ++i) {
		printf("%.10lf ", p[i]);
	}
	printf("\n");

	for (int i = 0; i < n; ++i) {
		printf("%.10lf ", q[i]);
	}
	printf("\n");

	/*for (int i = 0; i < n; ++i) {
		printf("%.4lf ", p[i] * sq[i] + q[i] * sp[i] - p[i] * q[i]);
	}
	printf("\n");

	for (int i = 0; i < n; ++i) {
		printf("%.4lf ", p[i] * (1.0 - (i == 0 ? 0.0 : sq[i - 1])) + q[i] * (1.0 - (i == 0 ? 0.0 : sp[i - 1])) - p[i] * q[i]);
	}
	printf("\n");*/


	return 0;
}