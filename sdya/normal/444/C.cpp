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
#include <list>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110000;
const int maxD = 300;
int n, m;
int color[maxN];
long long t[maxN];

int cnt;
int L[maxN], R[maxN], c[maxN];
long long s[maxN], added[maxN];

void precalc() {
	int i = 1;
	while (i <= n) {
		L[cnt] = i;
		R[cnt] = min(n, i + maxD - 1);
		c[cnt] = -1;
		i = R[cnt] + 1;
		++cnt;
	}
}

void transformBucket(int i) {
	if (c[i] == -1) {
		return;
	}
	for (int j = L[i]; j <= R[i]; ++j) {
		t[j] += added[i];
		color[j] = c[i];
	}
	added[i] = 0;
	c[i] = -1;
}

void updateBucket(int i, int l, int r, int x) {
	int cl = max(l, L[i]);
	int cr = min(r, R[i]);
	if (cl > cr) {
		return;
	}

	if (cl == L[i] && cr == R[i]) {
		if (c[i] == -1) {
			for (int j = L[i]; j <= R[i]; ++j) {
				s[i] += abs(x - color[j]);
				t[j] += abs(x - color[j]);
				color[j] = x;
			}
			c[i] = x;
			added[i] = 0;
		} else {
			added[i] += abs(x - c[i]);
			s[i] += (long long)(R[i] - L[i] + 1) * (long long)(abs(x - c[i]));
			c[i] = x;
		}
	} else {
		transformBucket(i);
		for (int j = cl; j <= cr; ++j) {
			s[i] += abs(x - color[j]);
			t[j] += abs(x - color[j]);
			color[j] = x;
		}
	}
}

long long getBucket(int i, int l, int r) {
	int cl = max(l, L[i]);
	int cr = min(r, R[i]);
	if (cl > cr) {
		return 0;
	}

	long long res = 0;
	if (cl == L[i] && cr == R[i]) {
		res += s[i];
	} else {
		transformBucket(i);
		for (int j = cl; j <= cr; ++j) {
			res += t[j];
		}
	}
	return res;
}

void update(int l, int r, int x) {
	for (int i = 0; i < cnt; ++i) {
		updateBucket(i, l, r, x);
	}
}

long long get(int l, int r) {
	long long res = 0;
	for (int i = 0; i < cnt; ++i) {
		res += getBucket(i, l, r);
	}
	return res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		color[i] = i;
		t[i] = 0;
	}

	precalc();

	for (int i = 0; i < m; ++i) {
		int mode;
		scanf("%d", &mode);
		if (mode == 1) {
			int l, r, x;
			scanf("%d%d%d", &l, &r, &x);
			update(l, r, x);
		} else {
			int l, r;
			scanf("%d%d", &l, &r);
			printf("%I64d\n", get(l, r));
		}
	}


	return 0;
}