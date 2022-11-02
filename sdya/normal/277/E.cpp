#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#include <stack>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 900;
int n;
int x[maxN], y[maxN];

double getD(double x1, double y1, double x2, double y2) {
	double dx = x1 - x2;
	double dy = y1 - y2;
	return sqrt(dx * dx + dy * dy);
}

double a[maxN][maxN], dist[maxN];
int c[maxN][maxN], prv[maxN];

void getFlow() {
	int T = n + n, S = T + 1;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (y[i] > y[j]) {
				c[i][j + n] = 1;
				a[i][j + n] = getD(x[i], y[i], x[j], y[j]);
				a[j + n][i] = -a[i][j + n];
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		c[S][i] = 2;
		c[i + n][T] = 1;
	}

    double score = 0;
    for (int kk = 1; kk < n; ++kk) {
		fill(dist, dist + S, 1e111);
		dist[S] = 0;
		memset(prv, -1, sizeof(prv));
		for (; ; ) {
			bool ok = true;
			for (int i = 0; i <= S; ++i) {
				if (dist[i] > -1e110) {
					for (int j = 0; j < S; ++j) { 
						if (c[i][j] > 0 && dist[i] + a[i][j] < dist[j] - 1e-10) {
							ok = false;
							dist[j] = dist[i] + a[i][j];
							prv[j] = i;
						}
					}
				}
			}
			if (ok) break;
		}
		if (dist[T] > 1e60) {
			printf("-1\n");
			exit(0);
		}
		score += dist[T];
		if (score < 0) break;
		for (int x, y = T; ~(x = prv[y]); y = x) {
			--c[x][y];
			++c[y][x];
		}
	}
	printf("%.10lf\n", score);
}


int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &x[i], &y[i]);
	}

	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (make_pair(y[j], x[j]) > make_pair(y[i], x[i])) {
				swap(x[i], x[j]);
				swap(y[i], y[j]);
			}
		}
	}

	if (y[1] == y[0]) {
		printf("-1\n");
		return 0;
	}

	getFlow();

	return 0;
}