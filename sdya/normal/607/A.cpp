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

const int maxN = 110000;
int n, a[maxN], b[maxN];
int c[maxN], t[maxN];

int order[maxN];

bool comp(int x, int y) {
	return a[x] < a[y];
}

int d[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &a[i], &b[i]);
		order[i] = i;
	}
	sort(order, order + n, comp);
	for (int i = 0; i < n; ++i) {
		c[i] = a[order[i]];
		t[i] = b[order[i]];
	}

	int res = 0;
	for (int i = 0; i < n; ++i) {
		int index = lower_bound(c, c + n, c[i] - t[i]) - c;
		--index;
		if (index >= 0) {
			d[i] = d[index] + 1;
		} else {
			d[i] = 1;
		}
		res = max(res, d[i]);
	}

	printf("%d\n", n - res);



	return 0;
}