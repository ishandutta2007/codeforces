#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cstring>
#include <climits>
#include <cmath>
#include <map>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
struct edge { int u, v; ll w; };

int main() {
	int n, m, w; cin >> n >> m >> w;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	ll lb = 0, ub = INT_MAX; // [lb,ub)
	while (ub - lb > 1) {
		ll mid = (lb + ub) / 2;
		vector<ll> b = a, c(n);
		ll csum = 0, cnt = 0;
		for (int i = 0; i < n; i++) {
			if (i - w >= 0) csum -= c[i - w];
			if (b[i] + csum < mid) {
				c[i] = mid - (b[i] + csum);
				cnt += c[i];
			}
			csum += c[i];
		}
		if (cnt <= m) lb = mid;
		else ub = mid;
	}
	cout << lb << endl;
}