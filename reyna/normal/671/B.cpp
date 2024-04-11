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
#define int long long
const int N = (int) 5e5 + 5, mod = 0;

int n, k, a[N];

bool check1(int lim) {
	int cost = 0;
	rep(i, n)
		if (a[i] >= lim)
			cost += a[i] - lim;
	return cost <= k;
}

bool check2(int lim) {
	int cost = 0;
	rep(i, n)
		if (a[i] <= lim)
			cost += lim - a[i];
	return cost <= k;
}

int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	int sum = 0;
	rep(i, n)
		cin >> a[i], sum += a[i];
	sort(a, a + n);
	int bl = (sum - 1) / n, br = 1e9 + 1;
	int res = !!(sum % n);
	while (bl < br - 1) {
		int bm = bl + br >> 1;
		if (check1(bm))
			br = bm;
		else
			bl = bm;
	}
	int r = br;
	bl = 0, br = (sum - 1) / n + 1;
	while (bl < br - 1) {
		int bm = bl + br >> 1;
		if (check2(bm))
			bl = bm;
		else
			br = bm;
	}
	if (sum % n == 0) {
		int cost = 0;
		rep(i, n)
			cost += abs(a[i] - sum / n);
		cost /= 2;
		if (cost <= k) {
			cout << 0 << endl;
			return 0;
		}
	}
	int l = bl;
	cout << max(res, r - l) << endl;
	return 0;
}