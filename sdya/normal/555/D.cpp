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
#include <complex>
#include <ctime>
#include <unordered_map>
#include <unordered_set>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 210000;

int n, m;
int x[maxN], y[maxN];
unordered_map < int, int > M;

int solve(int index, int L, int isright = true) {
	if (isright) {
		int p = upper_bound(x, x + n, x[index] + L) - x - 1;

		L -= x[p] - x[index];

		int q = lower_bound(x, x + n, x[p] - L) - x;

		L -= x[p] - x[q];

		if (p == q) {
			return M[x[p]] + 1;
		}

		int d = x[p] - x[q];

		int parts = L / d;
		if (parts == 0) {
			return solve(q, L, true);
		}

		if (parts % 2 == 0) {
			return solve(q, L % d, true);
		}
		return solve(p, L % d, false);
	}
	int p = lower_bound(x, x + n, x[index] - L) - x;
	return solve(p, L - (x[p] - x[index]), true);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &x[i]);
		y[i] = x[i];
		M[x[i]] = i;
	}
	sort(x, x + n);

	for (int i = 0; i < m; ++i) {
		int v, l;
		scanf("%d%d", &v, &l);
		int index = lower_bound(x, x + n, y[v - 1]) - x;
		printf("%d\n", solve(index, l));
	}



	return 0;
}