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

const int P = 1000000007;
const int maxN = 21000;
const int shift = 10500;
int d[2][3][maxN];
int n, a[maxN];

void set0(int d[3][maxN]) {
	for (int i = 0; i < 3; ++i) {
		memset(d[i], 0, sizeof(d[i]));
	}
}

void add(int &x, int value) {
	x += value;
	if (x >= P) {
		x -= P;
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}

	int u = 0, v = 1;
	d[u][0][shift] = 1;

	for (int step = 0; step < n; ++step, swap(u, v)) {
		set0(d[v]);
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < maxN; ++j) {
				if (d[u][i][j] == 0) {
					continue;
				}
				if (i == 0) {
					add(d[v][0][j], d[u][i][j]);
					add(d[v][1][j + a[step]], d[u][i][j]);
					add(d[v][1][j - a[step]], d[u][i][j]);
				} else if (i == 1) {
					add(d[v][1][j + a[step]], d[u][i][j]);
					add(d[v][1][j - a[step]], d[u][i][j]);
					add(d[v][2][j], d[u][i][j]);
				} else {
					add(d[v][2][j], d[u][i][j]);
				}
			}
		}
	}
	printf("%d\n", (d[u][2][shift] + d[u][1][shift]) % P);


	return 0;
}