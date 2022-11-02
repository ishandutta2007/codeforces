#include <cassert>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <bitset>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <stack>
#include <cmath>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 1100;
const double inf = 1e6;
const double eps = 1e-16;
int n;
double p[maxN][maxN];
double e[maxN];

int order[maxN];
int s[maxN];

bool used[maxN];

bool comp(int x, int y) {
	return e[x] < e[y];
}

void gen(int n) {
	printf("%d\n", n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == j) {
				printf("100 ");
			} else {
				printf("%d ", (i + 1 == j ? 1 : 0));
			}
		}
		printf("\n");
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	//gen(1000);

	//return 0;

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int v;
			scanf("%d", &v);
			p[i][j] = (double)(v) / 100.0;
		}
		e[i] = inf;
	}
	e[n - 1] = 0.0;
	used[n - 1] = true;

	for (int t = 0; ; ++t) {
		if ((double)(clock()) / (double)(CLOCKS_PER_SEC) > 1.9) {
			cerr << t << endl;
			break;
		}
		int m = 0;
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			s[m++] = i;
			if (!used[i]) {
				++cnt;
			}
		}
		sort(s, s + m, comp);
		if (used[0]) {
			//break;
		}
		for (int i = 0; i < m; ++i) {
			int v = s[i];
			if (used[v]) {
				//continue;
			}
			int k = 0;
			bool needed = false;
			for (int j = 0; j <= i; ++j) {
				if (e[s[j]] < e[v] || s[j] == v) {
					order[k++] = s[j];
					if (k >= 2 && e[order[k - 1]] < e[order[k - 2]]) {
						needed = true;
					}
				}
			}
			if (needed) {
				sort(order, order + k, comp);
			}

			double q = 1.0;
			double A = 1.0, B = 0.0;
			for (int j = 0; j < k; ++j) {
				if (order[j] == v) {
					B += q;
					A -= q;
					break;
				}
				B += q * p[v][order[j]] * (1.0 + e[order[j]]);
				q *= (1.0 - p[v][order[j]]);
			}
			if (A < eps) {
				continue;
			}
			if (fabs(e[v] - B / A) < eps) {
				used[v] = true;
			}
			e[v] = B / A;
		}
	}

	/*for (int i = 0; i < n; ++i) {
		printf("%.10lf\n", e[i]);
	}*/

	cerr << clock() << endl;

	printf("%.10lf\n", (double)e[0]);

	return 0;
}