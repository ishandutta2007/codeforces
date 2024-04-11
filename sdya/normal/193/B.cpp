#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <cmath>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 32;
int n, u, r;
int a[maxN], b[maxN], k[maxN], p[maxN];
long long res = - 1000000000000000000LL;

void rec(int have, int last = -1) {
	if ((have + u) % 2 == 0) {
		long long cur = 0;
		for (int i = 1; i <= n; ++i) {
			cur += (long long)(a[i]) * (long long)(k[i]);
		}
		res = max(res, cur);
	}
	if (have == u) {
		return ;
	}

	if (last != 1) {
		for (int i = 1; i <= n; ++i) {
			a[i] ^= b[i];
		}
		rec(have + 1, 1);
		for (int i = 1; i <= n; ++i) {
			a[i] ^= b[i];
		}
	}

	int c[maxN];
	for (int i = 1; i <= n; ++i) {
		c[i] = a[i];
	}
	for (int i = 1; i <= n; ++i) {
		a[i] = c[p[i]] + r;
	}
	rec(have + 1, 2);
	for (int i = 1; i <= n; ++i) {
		a[i] = c[i];
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &u, &r);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &b[i]);
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &k[i]);
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &p[i]);
	}

	rec(0);

	cout << res << endl;


	return 0;
}