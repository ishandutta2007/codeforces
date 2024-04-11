#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <bitset>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

int h, q;
char s[10];

map < int, int > M;

int get(int v) {
	if (M.count(v) > 0) {
		return M[v];
	}
	return 0;
}

double calc(int level, int v, int mx) {
	if (level == h) {
		return max(get(v), mx);
	}

	int x = get(v);
	if (x == 0) {
		return mx;
	}
	int y = get(2 * v);
	int z = get(2 * v + 1);

	if (y == 0 && z == 0) {
		return max(x, mx);
	}

	if (y < z) {
		return 0.5 * max((double)(mx), (double)(x - y)) + 0.5 * max((double)(mx), max((double)(x - z), calc(level + 1, 2 * v + 1, max(mx, x - z))));
	} else {
		return 0.5 * max((double)(mx), (double)(x - z)) + 0.5 * max((double)(mx), max((double)(x - y), calc(level + 1, 2 * v, max(mx, x - y))));
	}
}

double calc() {
	return calc(0, 1, 0);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &h, &q);
	for (int i = 1; i <= q; ++i) {
		scanf("%s", &s);
		if (s[0] == 'a') {
			int v, e;
			scanf("%d%d", &v, &e);
			while (v) {
				M[v] += e;
				v /= 2;
			}
		} else {
			printf("%.10lf\n", calc());
		}
	}

	return 0;
}