#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <stack>
#include <algorithm>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110000;
int n, k, h;
int m[maxN], v[maxN], order[maxN];
int ans[maxN];

bool comp(int x, int y) {
	return make_pair(m[x], v[x]) < make_pair(m[y], v[y]);
}

bool check(double t) {
	int m = k;
	int bans[maxN];
	for (int i = n; i >= 1 && m != 0; --i)
		if ((double)(m * h) <= (double)(v[order[i]]) * t) {
			bans[m] = order[i];
			--m;
		}

	if (m == 0) {
		for (int i = 1; i <= k; ++i)
			ans[i] = bans[i];
	}
	return m == 0;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &k, &h);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &m[i]), order[i] = i;
	for (int i = 1; i <= n; ++i)
		scanf("%d", &v[i]);

	sort(order + 1, order + n + 1, comp);
	double l = 0.0, r = 1e10;
	int iters = 200;
	while (iters) {
		double key = (l + r) / 2.0;
		if (check(key))
			r = key; else l = key;
		--iters;
	}

	for (int i = 1; i <= k; ++i)
		printf("%d ", ans[i]);
	printf("\n");

	return 0;
}