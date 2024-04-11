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

int n, rad[N], best[N << 2];
long long res[N];

void build(int v = 1, int b = 0, int e = n - 1) {
	if (b + 1 == e) {
		best[v] = b;
		return;
	}
	int m = b + e >> 1, l = v << 1, r = l | 1;
	build(l, b, m);
	build(r, m, e);
	best[v] = (rad[best[l]] < rad[best[r]]? best[r]: best[l]);
}

int query(int i, int j, int v = 1, int b = 0, int e = n - 1) {
	if (i >= e || b >= j)
		return n - 1;
	if (i <= b && e <= j) {
		return best[v];		
	}
	int m = b + e >> 1, l = v << 1, r = l | 1;
	int ansl = query(i, j, l, b, m);
	int ansr = query(i, j, r, m, e);
	if (rad[ansl] < rad[ansr])
		return ansr;
	return ansl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	rep(i, n - 1)
		cin >> rad[i];
	build();
	long long sum = 0;
	for (int i = n - 2; i >= 0; --i) {
		int r = query(i + 1, rad[i]);
		res[i] = res[r] + n - rad[i] + r - i;
		sum += res[i];
	}
	cout << sum << endl;
}