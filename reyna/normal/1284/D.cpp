
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
vector<int> allx, ally;
vector<int> cl[N], op[N];
int tot;
int xl[N], yl[N], xr[N], yr[N], seg[N << 2], ch[N << 2];
void push(int v) {
	ch[v << 1 | 0] += ch[v];
	ch[v << 1 | 1] += ch[v];
	seg[v << 1 | 0] += ch[v];
	seg[v << 1 | 1] += ch[v];
	ch[v] = 0;
}
void update(int i, int j, int x, int v = 1, int b = 0, int e = tot) {
	if (i >= e || b >= j) return;
	if (i <= b && e <= j) {
		seg[v] += x;
		ch[v] += x;
		return;
	}
	int m = b + e >> 1, l = v << 1, r = l | 1;
	push(v);
	update(i, j, x, l, b, m);
	update(i, j, x, r, m, e);
	seg[v] = max(seg[l], seg[r]);
}
int query(int i, int j, int v = 1, int b = 0, int e = tot) {
	if (i >= e || b >= j) return 0;
	if (i <= b && e <= j) return seg[v];
	int m = b + e >> 1, l = v << 1, r = l | 1;
	push(v);
	return max(query(i, j, l, b, m), query(i, j, r, m, e));
}
int32_t main() {
	int n;
	cin >> n;
	for (int j = 0; j < n; ++j) {
		cin >> xl[j] >> xr[j] >> yl[j] >> yr[j];
		--xl[j];
		--yl[j];
		allx.pb(xl[j]);
		allx.pb(xr[j]);
		ally.pb(yl[j]);
		ally.pb(yr[j]);
	}
	sort(ALL(allx));
	sort(ALL(ally));
	allx.resize(unique(ALL(allx)) - allx.begin());
	ally.resize(unique(ALL(ally)) - ally.begin());
	for (int j = 0; j < n; ++j) {
		xl[j] = lower_bound(ALL(allx), xl[j]) - allx.begin();
		xr[j] = lower_bound(ALL(allx), xr[j]) - allx.begin();
		yl[j] = lower_bound(ALL(ally), yl[j]) - ally.begin();
		yr[j] = lower_bound(ALL(ally), yr[j]) - ally.begin();
		op[yl[j]].pb(j);
		cl[yr[j]].pb(j);
	}
	tot = (int) allx.size();
	int flag = 1;
	for (int t = (int) ally.size(); t >= 0; --t) {
		for (int j : op[t]) update(xl[j], xr[j], 1);
		for (int j : cl[t]) {
			if (query(xl[j], xr[j]) > 0) {
				flag = 0;
			}
		}
	}
	memset(ch, 0, sizeof ch);
	memset(seg, 0, sizeof seg);
	for (int j = 0; j < N; ++j) op[j].clear(), cl[j].clear();
	tot = (int) ally.size();
	for (int j = 0; j < n; ++j) {
		op[xl[j]].pb(j);
		cl[xr[j]].pb(j);
	}
	for (int t = (int) allx.size(); t >= 0; --t) {
		for (int j : op[t]) update(yl[j], yr[j], 1);
		for (int j : cl[t]) if (query(yl[j], yr[j]) > 0) flag = 0;
	}
	if (!flag) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
	}
}