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

const int maxN = 510000;
const long long inf = 1000000000000000000LL;
long long t[4 * maxN], add[4 * maxN];
int n, m;
int a[maxN], l[maxN], r[maxN], p[maxN];
int order[maxN];

bool comp(int x, int y) {
	return r[x] < r[y];
}

long long get(int i, int l, int r, int cl, int cr) {
	if (l == cl && r == cr) {
		return t[i];
	}
	if (cl > (l + r) / 2) {
		return get(2 * i + 1, (l + r) / 2 + 1, r, cl, cr) + add[i];
	}
	if (cr <= (l + r) / 2) {
		return get(2 * i, l, (l + r) / 2, cl, cr) + add[i];
	}
	
	long long A = get(2 * i, l, (l + r) / 2, cl, (l + r) / 2);
	long long B = get(2 * i + 1, (l + r) / 2 + 1, r, (l + r) / 2 + 1, cr);
	return max(A, B) + add[i];
}

long long getMax(int l, int r) {
	return get(1, 0, maxN - 1, l, r);
}

void update(int i, int l, int r, int cl, int cr, long long delta) {
	if (l == cl && r == cr) {
		t[i] += delta;
		add[i] += delta;
		return ;
	}

	if (cl > (l + r) / 2) {
		update(2 * i + 1, (l + r) / 2 + 1, r, cl, cr, delta); 
	} else if (cr <= (l + r) / 2) {
		update(2 * i, l, (l + r) / 2, cl, cr, delta);
	} else {
		update(2 * i, l, (l + r) / 2, cl, (l + r) / 2, delta);
		update(2 * i + 1, (l + r) / 2 + 1, r, (l + r) / 2 + 1, cr, delta);
	}
	t[i] = max(t[2 * i], t[2 * i + 1]) + add[i];
}

void update(int l, int r, long long delta) {
	if (l > r) {
		return;
	}
	update(1, 0, maxN - 1, l, r, delta);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}

	for (int i = 1; i <= m; ++i) {
		scanf("%d%d%d", &l[i], &r[i], &p[i]);
		order[i] = i;
	}

	sort(order + 1, order + m + 1, comp);

	int start = 1;
	int zero = maxN / 2;
	update(0, maxN - 1, -inf);
	update(zero, zero, inf);

	for (int i = 1; i <= n; ++i) {
		long long value = getMax(zero, maxN - 1);
		long long oldValue = getMax(zero - 1, zero - 1);
		update(zero - 1, zero - 1, - oldValue + value);
		update(zero, maxN - 1, -a[i]);
		--zero;

		while (start <= m && r[order[start]] == i) {
			int v = order[start];
			int length = r[v] - l[v] + 1;
			update(zero + length, maxN - 1, p[v]);
			++start;
		}
	}

	cout << getMax(zero, maxN - 1) << endl;

	return 0;
}