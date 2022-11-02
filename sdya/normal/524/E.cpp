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
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 210000;

int t[4 * maxN];

void update(int i, int l, int r, int k, int value) {
	if (l == r) {
		t[i] = value;
		return ;
	}
	if (k > (l + r) / 2) {
		update(2 * i + 1, (l + r) / 2 + 1, r, k, value);
	} else {
		update(2 * i, l, (l + r) / 2, k, value);
	}
	t[i] = min(t[2 * i], t[2 * i + 1]);
}

int get(int i, int l, int r, int cl, int cr) {
	if (l == cl && r == cr) {
		return t[i];
	}
	if (cl > (l + r) / 2) {
		return get(2 * i + 1, (l + r) / 2 + 1, r, cl, cr);
	}
	if (cr <= (l + r) / 2) {
		return get(2 * i, l, (l + r) / 2, cl, cr);
	}
	int A = get(2 * i, l, (l + r) / 2, cl, (l + r) / 2);
	int B = get(2 * i + 1, (l + r) / 2 + 1, r, (l + r) / 2 + 1, cr);
	return min(A, B);
}

int n, m, k, q;
int xl[maxN], xr[maxN], yl[maxN], yr[maxN];
int order[maxN];

int x[maxN], y[maxN];
int orderP[maxN];

bool comp1(int i, int j) {
	return yr[i] < yr[j];
}

bool comp2(int i, int j) {
	return y[i] < y[j];
}

bool isGood[maxN];

void check() {
	sort(order, order + q, comp1);
	sort(orderP, orderP + k, comp2);

	memset(t, 0, sizeof(t));
	int index = 0;
	for (int i = 0; i < q; ++i) {
		while (index < k && y[orderP[index]] <= yr[order[i]]) {
			update(1, 1, n, x[orderP[index]], y[orderP[index]]);
			++index;
		}
		int value = get(1, 1, n, xl[order[i]], xr[order[i]]);
		if (value >= yl[order[i]]) {
			isGood[order[i]] = true;
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d%d%d", &n, &m, &k, &q);
	for (int i = 0; i < k; ++i) {
		scanf("%d%d", &x[i], &y[i]);
		orderP[i] = i;
	}

	for (int i = 0; i < q; ++i) {
		scanf("%d%d%d%d", &xl[i], &yl[i], &xr[i], &yr[i]);
		order[i] = i;
		isGood[i] = false;
	}

	check();
	for (int i = 0; i < k; ++i) {
		swap(x[i], y[i]);
	}
	for (int i = 0; i < q; ++i) {
		swap(xl[i], yl[i]);
		swap(xr[i], yr[i]);
	}
	swap(n, m);
	check();

	for (int i = 0; i < q; ++i) {
		if (isGood[i]) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}



	return 0;
}