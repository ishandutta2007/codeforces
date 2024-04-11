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

bool isParent(long long a, long long b) {
	if (a > b) {
		return false;
	}
	while (b > a) {
		b /= 2;
	}
	return a == b;
}

long long lca(long long a, long long b) {
	long long v = a;
	while (!isParent(v, b)) {
		v = v / 2;
	}
	return v;
}

map < pair < long long, long long >, long long > M;

void addPath(long long u, long long v, long long C) {
	long long w = lca(u, v);
	while (v != w) {
		M[make_pair(v / 2, v)] += C;
		v /= 2;
	}
	while (u != w) {
		M[make_pair(u / 2, u)] += C;
		u /= 2;
	}
}

long long getCost(long long u, long long v) {
	long long w = lca(u, v);
	long long res = 0;
	while (v != w) {
		res += M[make_pair(v / 2, v)];
		v /= 2;
	}
	while (u != w) {
		res += M[make_pair(u / 2, u)];
		u /= 2;
	}
	return res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; ++i) {
		int mode;
		scanf("%d", &mode);
		if (mode == 1) {
			long long u, v, C;
			scanf("%I64d%I64d%I64d", &u, &v, &C);
			addPath(u, v, C);
		} else {
			long long u, v;
			scanf("%I64d%I64d", &u, &v);
			printf("%I64d\n", getCost(u, v));
		}
	}

	return 0;
}