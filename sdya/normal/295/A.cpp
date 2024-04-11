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

const int maxN = 110000;
long long t[4 * maxN], add[4 * maxN];

void update(int i, int l, int r, int cl, int cr, long long value) {
	if (l == cl && r == cr) {
		t[i] += value;
		add[i] += value;
		return ;
	}
	if (cl > (l + r) / 2) {
		update(2 * i + 1, (l + r) / 2 + 1, r, cl, cr, value);
	} else if (cr <= (l + r) / 2) {
		update(2 * i, l, (l + r) / 2, cl, cr, value);
	} else {
		update(2 * i, l, (l + r) / 2, cl, (l + r) / 2, value);
		update(2 * i + 1, (l + r) / 2 + 1, r, (l + r) / 2 + 1, cr, value);
	}
	t[i] = max(t[2 * i], t[2 * i + 1]);
	t[i] += add[i];
}

long long get(int i, int l, int r, int k) {
	if (l == r) {
		return t[i];
	}
	if (k > (l + r) / 2) {
		return get(2 * i + 1, (l + r) / 2 + 1, r, k) + add[i];
	} else {
		return get(2 * i, l, (l + r) / 2, k) + add[i];
	}
}

int n, m, k;
int a[maxN];

int l[maxN], r[maxN], d[maxN], cnt[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d%d", &l[i], &r[i], &d[i]);
	}

	for (int i = 1; i <= k; ++i) {
		int l, r;
		scanf("%d%d", &l, &r);
		update(1, 1, m, l, r, 1);
	}
	for (int i = 1; i <= m; ++i) {
		cnt[i] = get(1, 1, m, i);
	}
	memset(t, 0, sizeof(t));
	memset(add, 0, sizeof(add));

	for (int i = 1; i <= m; ++i) {
		update(1, 1, n, l[i], r[i], (long long)(d[i]) * (long long)(cnt[i]));
	}
	for (int i = 1; i <= n; ++i) {
		printf("%I64d ", (long long)(a[i]) + get(1, 1, n, i));
	}
	printf("\n");

	return 0;
}