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
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int inf = 10000;
int a[50], p;

const int maxN = 110000;
const int maxD = 1000;
const int maxV = 10100;
bool isOk[maxV];
int cnt[maxN / maxD][maxV];
int add[maxN / maxD];

int tmp[maxD];

void gen(int current) {
	if (current > inf) {
		return;
	}
	if (current > 0) {
		a[p++] = current;
		isOk[current] = true;
	}
	gen(current * 10 + 4);
	gen(current * 10 + 7);
}

int n, m;
int b[maxN];
char s[10];

int segCnt;
int l[maxN / maxD], r[maxN / maxD];

int get(int index) {
	int res = 0;
	for (int i = 0; i < p; ++i) {
		if (a[i] - add[index] >= 0) {
			res += cnt[index][a[i] - add[index]];
		}
	}
	return res;
}

void precalc() {
	int start = 1;
	while (start <= n) {
		l[segCnt] = start;
		r[segCnt] = min(n, start + maxD - 1);
		for (int i = l[segCnt]; i <= r[segCnt]; ++i) {
			++cnt[segCnt][b[i]];
		}
		start = r[segCnt] + 1;
		++segCnt;
	}
}

void update(int left, int right, int delta) {
	for (int index = 0; index < segCnt; ++index) {
		if (l[index] >= left && r[index] <= right) {
			add[index] += delta;
			continue;
		}
		if (r[index] < left) {
			continue;
		}
		if (l[index] > right) {
			break;
		}

		for (int i = l[index]; i <= r[index]; ++i) {
			--cnt[index][b[i]];
			b[i] += add[index];
			++cnt[index][b[i]];
		}

		add[index] = 0;
		for (int i = max(l[index], left); i <= min(r[index], right); ++i) {
			--cnt[index][b[i]];
			b[i] += delta;
			++cnt[index][b[i]];
		}
	}
}

int get(int left, int right) {
	int res = 0;
	for (int index = 0; index < segCnt; ++index) {
		if (l[index] >= left && r[index] <= right) {
			res += get(index);
			continue;
		}
		if (r[index] < left) {
			continue;
		}
		if (l[index] > right) {
			break;
		}

		for (int i = max(l[index], left); i <= min(r[index], right); ++i) {
			if (isOk[b[i] + add[index]]) {
				++res;
			}
		}
	}
	return res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	gen(0);
	sort(a, a + p);

	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &b[i]);
	}
	precalc();

	for (int i = 1; i <= m; ++i) {
		scanf("%s", &s);
		if (s[0] == 'a') {
			int l, r, delta;
			scanf("%d%d%d", &l, &r, &delta);
			update(l, r, delta);
		} else {
			int l, r;
			scanf("%d%d", &l, &r);
			printf("%d\n", get(l, r));
		}
	}

	return 0;
}