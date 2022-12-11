#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define FOR(a, b) for (int a = 0; a < (b); ++a)
#define clr(a) memset(a, 0, sizeof(a))

typedef long long ll;

const int INF = 1e9;
const int MAXN = 100002;
const int MAXR = 400;

int a[MAXN];
int c[MAXN];
int cb = 0;
int b[MAXN];
int cand[2 * MAXR + 1];
int pr[600][MAXN + 1];
int cc = 0;

int main() {
//	freopen("a.in", "r", stdin);
	int n, m;
	cin >> n >> m;
	clr(c);
	FOR(i, n) {
		scanf("%d", &a[i]);
		if (a[i] <= n)
			c[a[i]]++;
	}
	for (int i = 1; i < n + 1; ++i) {
		if (c[i] >= i) {
			cand[cc++] = i;
			if (cc > 500)
				return -1;
		}
	}
	clr(c);
	clr(pr);
	FOR(i, n) {
		FOR(j, cc)
			if (a[i] == cand[j])
				c[j]++;
		FOR(j, cc) {
			pr[j][i + 1] = c[j];
		}
	}
	/*
	FOR(i, 10) {
		FOR(j, n)
			cerr << pr[i][j]
			*/
	FOR(i, m) {
		int l, r;
		scanf("%d%d", &l, &r);
		int ans = 0;
		FOR(j, cc) {
			int w = pr[j][r] - pr[j][l - 1];
			//cerr << j << ' ' << w << '\n';
			if (w == cand[j])
				ans++;
		}
		printf("%d\n", ans);
	}





	return 0;
}