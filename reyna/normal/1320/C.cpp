
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <complex>

using namespace std;

#define mp make_pair
#define x first
#define y second
#define pb push_back
#define ALL(x) (x).begin(), (x).end()

typedef long long LL;
#define int long long
const int N = (int) 1e6 + 6, mod = (int) 0;
int ca[N], cb[N], px[N], py[N], pz[N], a[N], b[N], oa[N], ob[N], oc[N], n, vals[N], mx[N << 2], ch[N << 2];
int cmpa(int x, int y) { return a[x] < a[y]; }
int cmpb(int x, int y) { return b[x] < b[y]; }
int cmpc(int x, int y) { return px[x] < px[y]; }
void build(int v = 1, int b = 0, int e = n) {
	if (b + 1 == e) {
		mx[v] = -cb[ob[b]];
		return;
	}
	int m = b + e >> 1, l = v << 1, r = l | 1;
	build(l, b, m);
	build(r, m, e);
	mx[v] = max(mx[l], mx[r]);
}
void update(int i, int j, int x, int v = 1, int b = 0, int e = n) {
	if (i >= e || b >= j) return;
	if (i <= b && e <= j) {
		ch[v] += x;
		mx[v] += x;
		return;
	}
	int m = b + e >> 1, l = v << 1, r = l | 1;
	update(i, j, x, l, b, m);
	update(i, j, x, r, m, e);
	mx[v] = max(mx[l], mx[r]) + ch[v];
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	int nn, m, k;
	cin >> nn >> m >> k;
	for (int j = 0; j < nn; ++j) {
		cin >> a[j] >> ca[j];
		oa[j] = j;
	}
	sort(oa, oa + nn, cmpa);
	for (int j = 0; j < m; ++j) {
		cin >> b[j] >> cb[j];
		ob[j] = j;
	}
	sort(ob, ob + m, cmpb);
	for (int j = 0; j < m; ++j) vals[j] = b[ob[j]];
	for (int j = 0; j < k; ++j) {
		cin >> px[j] >> py[j] >> pz[j];
		oc[j] = j;
	}
	n = m;
	sort(oc, oc + k, cmpc);
	build();
	int pt = 0, res = -1e18;
	for (int i = 0; i < nn; ++i) {
		int cur = oa[i];
		while (pt < k && px[oc[pt]] < a[cur]) {
			int pos = lower_bound(vals, vals + m, py[oc[pt]]+1) - vals;
			update(pos, m, pz[oc[pt]]);
			++pt;
		}
		res = max(res, -ca[cur] + mx[1]);
	}
	cout << res << endl;
}