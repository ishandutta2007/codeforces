#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <algorithm>
#include <functional>
#include <utility>

#define maxn 100500
#define maxk 131072

using namespace std;

int n, q, maxid, curk;
int v[maxn], c[maxn];
long long res[2 * maxk];

int main () {
	scanf ("%d%d", &n, &q);
	for (int i = 0; i < n; ++i)
		scanf ("%d", v + i);
	maxid = 0;
	for (int i = 0; i < n; ++i) {
		scanf ("%d", c + i);
		maxid = max (maxid, c[i]);
	}
	curk = 2;
	while (curk < maxid) curk *= 2;
	for (int it = 0; it < q; ++it) {
		int a, b;
		scanf ("%d%d", &a, &b);
		long long aa (a), bb (b), ca, cb;
		if (maxid == 1) {
			res[1] = -1000000000000LL;
			for (int i = 0; i < n; ++i)
				res[1] = max (res[1], max(res[1] + (long long) v[i] * aa, (long long) v[i] * bb));
			cout << max (res[1], 0LL) << '\n';
			continue;
		}
		int id1 = 1, id2 = maxid;
		for (int itit = 1; itit <= maxid; ++itit)
			res[itit] = -1000000000000LL;
		for (int i = 0; i < n; ++i) {
			ca = res[c[i]];
			assert (id1 != id2);
			if (id1 == c[i])
				cb = res[id2];
			else
				cb = res[id1];
			res[c[i]] = max (res[c[i]], max (ca + (long long) v[i] * aa, max (cb, 0LL)  + (long long) v[i] * bb));
			if (res[c[i]] > res[id2] && c[i] != id1)
				id2 = c[i];
			if (res[id2] > res[id1])
				swap (id2, id1);
		}
		cout << max (max (res[id1], res[id2]), 0LL) << '\n';
	}
	return 0;
}