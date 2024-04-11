// In the name of God

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

using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; ++i)

const int N = (int) 1e5 + 5, mod = 0;

int mn[N << 2], par[N], n;
map<int, int> pl;
pair<int, int> a[N];

void build(int v = 1, int b = 0, int e = n) {
	if (b + 1 == e) {
		mn[v] = a[b].second;
		return;
	}
	int m = b + e >> 1, l = v << 1, r = l | 1;
	build(l, b, m);
	build(r, m, e);
	mn[v] = min(mn[l], mn[r]);
}

int query(int i, int j, int v = 1, int b = 0, int e = n) {
	if (i >= e || b >= j)
		return (int) 1e9;
	if (i <= b && e <= j)
		return mn[v];
	int m = b + e >> 1, l = v << 1, r = l | 1;
	return min(query(i, j, l, b, m), query(i, j, r, m, e));
}

int solve(int s = 0, int e = n) {
	if (e - s <= 0)
		return N - 1;
	if (e - s == 1)
		return a[s].second;
	int m = pl[query(s, e)];
	par[solve(s, m)] = a[m].second;
	par[solve(m + 1, e)] = a[m].second;
	return a[m].second;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	rep(i, n)
		cin >> a[i].first, a[i].second = i;
	sort(a, a + n);
	rep(i, n)
		pl[a[i].second] = i;
	build();
	solve();
	rep(i, n - 1)
		cout << a[pl[par[i + 1]]].first << ' ';
}