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
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110000;
const int maxK = 610;
int n, k;

double d[2][maxK];
double t[maxK], s[maxK];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	for (int i = 1; i < maxK; ++i) {
		t[i] = 1.0 / (double)(i + 1);
		s[i] = (double)(i) * (double)(i + 1) * t[i] / 2.0;
	}

	cin >> n >> k;
	double p = 1.0 / (double)(k);
	double q = 1.0 - p;
	int u = 0, v = 1;
	memset(d[u], 0, sizeof(d[u]));

	double res = 0.0;
	d[u][1] = 1.0;
	for (int steps = 0; steps < n; ++steps, swap(u, v)) {
		memset(d[v], 0, sizeof(d[v]));

		for (int i = 1; i < maxK; ++i) {
if (d[u][i] < 1e-100) d[u][i] = 0.0;
			d[v][i] += d[u][i] * q;
			if (i + 1 < maxK) {
				d[v][i + 1] += d[u][i] * p * t[i];
				res += d[u][i] * p * t[i] * (double)(i);
			}
			d[v][i] += d[u][i] * p * (1.0 - t[i]);
			res += d[u][i] * p * s[i];
		}
	}

	printf("%.10lf\n", res * (double)(k));

	return 0;
}