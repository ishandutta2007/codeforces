#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <memory.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

const int maxn = 100010;

int n, a[100010], m, cnt[maxn], it[maxn], ql[maxn], qr[maxn], id[maxn], first[maxn], next[maxn], ans[maxn], s[maxn], prev[maxn], last[maxn];

bool cmp(int i, int j) {
	return qr[i] < qr[j];
}

void modify(int x, int d) {
	for (x++; x <= n; x += -x&x)
		s[x] += d;
}

int get(int x) {
	int res = 0;
	for (x++; x > 0; x &= x-1)
		res += s[x];
	return res;
}

int getsum(int L, int R) {
	return get(R) - (L == 0 ? 0 : get(L-1));
}

int main() {
	scanf("%d %d", &n, &m);
	forn(i, n) scanf("%d", &a[i]);
	forn(i, m) scanf("%d %d", &ql[i], &qr[i]), ql[i]--, qr[i]--;

	forn(i, n) if (a[i] > n) a[i] = n+1;

	memset(last, 0xff, sizeof(last));
	forn(i, n) {
		prev[i] = last[ a[i] ];
		last[ a[i] ] = i;
	}

	memset(first, 0xff, sizeof(first));
	for (int i = n-1; i >= 0; i--) {
		next[i] = first[ a[i] ];
		first[ a[i] ] = i;
	}

	forn(i, m) id[i] = i;
	sort(id, id+m, cmp);

	int j = 0;

	forn(i, n) {
		if (a[i] <= n) {
			cnt[ a[i] ]++;
			if (cnt[ a[i] ] == a[i]) {
				it[ a[i] ] = first[ a[i] ];
				modify(it[ a[i] ], +1);
			}
			if (cnt[ a[i] ] > a[i]) {
				int pr = prev[ it[ a[i] ] ];
				if (pr != -1) modify(pr, +1);
				modify(it[a[i]], -2);
				it[ a[i] ] = next[ it[a[i]] ];
				modify(it[a[i]], +1);
			}
		}

		while (j < m && qr[id[j]] == i) {
			int cq = id[j];
			ans[cq] = getsum(ql[cq], qr[cq]);
			j++;
		}
	}

	forn(i, m) printf("%d\n", ans[i]);

    return 0;
}