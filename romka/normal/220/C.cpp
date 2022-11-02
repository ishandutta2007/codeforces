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

int n, a[300010], b[300010], ans[300010], q[300010], qb, qf, where[300010];
multiset<int> ss;
vector<int> zl_in[300010], zl_out[300010], zr_in[300010], zr_out[300010];

int aa(int x) {
	return x < 0 ? -x : x;
}

int main() {
	scanf("%d", &n);
	forn(i, n) scanf("%d", &a[i]), a[i]--;
	forn(i, n) scanf("%d", &b[i]), b[i]--;

	forn(i, n) where[ a[i] ] = i;

	forn(i, n) {
		int t = 0;
		if (where[ b[i] ] <= i) t = i - where[ b[i] ];
		else t = n - (where[ b[i] ] - i);

		// printf("%d - in %d\n", i, t);

		int wi = where[ b[i] ];
		zr_in[t].pb(t);
		zr_out[t+wi+1].pb(t);
		zr_in[t+n].pb(t+n);
		zr_out[t+n+wi+1].pb(t+n);

		zl_in[t+n+n].pb(t+n+n);
		zl_out[t+n+n-(n-wi)].pb(t+n+n);
		zl_in[t+n].pb(t+n);
		zl_out[t+n-(n-wi)].pb(t+n);
	}

	forn(i, n+n) ans[i] = n + 2;
	
	forn(i, n+n) {
		forn(j, zr_in[i].size()) {
			ss.insert(zr_in[i][j]);
			// printf("ir at %d val %d\n", i, zr_in[i][j]);
		}
		forn(j, zr_out[i].size())
			ss.erase(ss.find(zr_out[i][j]));
		if (!ss.empty())
			ans[i] = min(ans[i], i - (*ss.rbegin()));
	}

	ss.clear();

	for (int i = n+n+n-1; i >= 0; i--) {
		forn(j, zl_in[i].size()) {
			ss.insert(zl_in[i][j]);
			// printf("il at %d val %d\n", i, zl_in[i][j]);
		}
		forn(j, zl_out[i].size())
			ss.erase(ss.find(zl_out[i][j]));
		if (!ss.empty())
			ans[i] = min(ans[i], (*ss.begin()) - i);
	}

	for (int i = n; i < n+n; i++)
		printf("%d\n", ans[i]);

    return 0;
}