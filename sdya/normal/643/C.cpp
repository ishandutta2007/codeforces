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

const int maxN = 210000;
const int maxK = 60;
const double inf = 1e50;
int t[maxN], n, k;
double s[maxN], sr[maxN];

double d[maxK][maxN];

double cost[maxN];

inline double getS(int l, int r) {
	return s[r] - s[l - 1];
}

inline double getSR(int l, int r) {
	return sr[r] - sr[l - 1];
}

inline double getCost(int l, int r) {
	return cost[r] - cost[l - 1] - getSR(l, r) * getS(1, l - 1);
}

void calc(int index, int l, int r, int optL, int optR) {
	if (l > r) {
		return;
	}
	if (l == r) {
		d[index][l] = inf;
		for (int i = optL; i <= optR; ++i) {
			d[index][l] = min(d[index][l], d[index - 1][i - 1] + getCost(i, l));
		}
		return ;
	}

	int m = (l + r) / 2;
	d[index][m] = inf;

	int optM = optL;

	for (int i = optL; i <= optR; ++i) {
		double value = d[index - 1][i - 1] + getCost(i, m);
		if (value < d[index][m]) {
			d[index][m] = value;
			optM = i;
		}
	}
	calc(index, l, m - 1, optL, optM);
	calc(index, m + 1, r, optM, optR);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &t[i]);
		s[i] = (double)(t[i]);
		sr[i] = 1.0 / (double)(t[i]);
		s[i] += s[i - 1];
		sr[i] += sr[i - 1];
	}

	for (int i = 1; i <= n; ++i) {
		cost[i] = s[i] / (double)(t[i]);
		if (i > 0) {
			cost[i] += cost[i - 1];
		}
	}

	d[0][0] = 0.0;
	for (int i = 1; i <= n; ++i) {
		d[0][i] = inf;
	}

	for (int i = 1; i <= k; ++i) {
		calc(i, 1, n, 1, n);
	}

	printf("%.10lf\n", d[k][n]);

	return 0;
}