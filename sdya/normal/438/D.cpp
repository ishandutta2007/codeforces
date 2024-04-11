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

const int maxN = 110000;
long long t[maxN];

void update(int k, int value) {
	for (int i = k; i < maxN; i |= (i + 1)) {
		t[i] += value;
	}
}

long long get(int r) {
	long long res = 0;
	for (int i = r; i >= 0; i = (i & (i + 1)) - 1) {
		res += t[i];
	}
	return res;
}

long long get(int l, int r) {
	return get(r) - get(l - 1);
}

pair < int, int > T[4 * maxN];
int a[maxN], n, m;

pair < int, int > build(int i, int l, int r) {
	if (l == r) {
		T[i] = make_pair(a[l], l);
	} else {
		T[i] = max(
			build(2 * i, l, (l + r) / 2),
			build(2 * i + 1, (l + r) / 2 + 1, r));
	}
	return T[i];
}

pair < int, int > get(int i, int l, int r, int cl, int cr) {
	if (l == cl && r == cr) {
		return T[i];
	}
	if (cl > (l + r) / 2) {
		return get(2 * i + 1, (l + r) / 2 + 1, r, cl, cr);
	}
	if (cr <= (l + r) / 2) {
		return get(2 * i, l, (l + r) / 2, cl, cr);
	}
	return max(
		get(2 * i, l, (l + r) / 2, cl, (l + r) / 2),
		get(2 * i + 1, (l + r) / 2 + 1, r, (l + r) / 2 + 1, cr));
}

void update(int i, int l, int r, int k, int value) {
	if (l == r) {
		T[i].first = value;
		return ;
	}
	if (k > (l + r) / 2) {
		update(2 * i + 1, (l + r) / 2 + 1, r, k, value);
	} else {
		update(2 * i, l, (l + r) / 2, k, value);
	}
	T[i] = max(T[2 * i], T[2 * i + 1]);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		update(i, a[i]);
	}

	build(1, 0, n - 1);

	for (int i = 0; i < m; ++i) {
		int mode;
		scanf("%d", &mode);
		if (mode == 1) {
			int l, r;
			scanf("%d%d", &l, &r);
			printf("%I64d\n", get(l - 1, r - 1));
		} else if (mode == 2) {
			int l, r, x;
			scanf("%d%d%d", &l, &r, &x);
			--l;
			--r;
			while (true) {
				pair < int, int > u = get(1, 0, n - 1, l, r);
				if (u.first < x) {
					break;
				}
				update(1, 0, n - 1, u.second, u.first % x);
				update(u.second, - u.first + (u.first % x));
			}
		} else {
			int k, x;
			scanf("%d%d", &k, &x);
			--k;
			pair < int, int > u = get(1, 0, n - 1, k, k);
			update(1, 0, n - 1, u.second, x);
			update(u.second, - u.first + x);
		}
	}


	return 0;
}