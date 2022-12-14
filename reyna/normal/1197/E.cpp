
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

const int N = (int) 1e6 + 6, mod = (int) 1e9 + 7;
multiset<pair<int, int>> lst;
multiset<pair<int, int>, greater<pair<int, int>>> gst;
pair<int, int> sr[N];
int xl[N], xr[N], dp[N], space[N], sum;
int main() {
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	int mx = 0, mn = 2e9;
	for (int j = 0; j < n; ++j) {
		cin >> xr[j] >> xl[j];	
		mx = max(mx, xl[j]);
		sr[j << 1 | 0] = mp(xl[j], j);
		sr[j << 1 | 1] = mp(xr[j], -j);
	}
	sort(sr, sr + 2 * n);
	lst.insert(mp(0, 1));
	gst.insert(mp(0, 1));
	sum = 1;
	for (int s = 0; s < 2 * n; ++s) {
		int pos = sr[s].first;
		int id = abs(sr[s].second);
		if (pos == xl[id]) {
			dp[id] = sum;
			auto x = *(lst.begin());
			space[id] = x.first + xl[id];
			if (mx < xr[id])
			   mn = min(mn, space[id]);
		} else {
			pair<int, int> cur = mp(space[id] - xr[id], dp[id]);
			lst.insert(cur);
			gst.insert(cur);
			sum = (sum + dp[id]) % mod;
			while ((int) gst.size()) {
				auto x = *(gst.begin());
				auto y = *(lst.begin());
				if (x.first != y.first) {
					gst.erase(gst.begin());
					sum = (sum - x.second + mod) % mod;
				} else {
					break;
				}
			}
		}
	}
	int res = 0;
	for (int id = 0; id < n; ++id) {
		if (mx < xr[id] && mn == space[id]) {
			res = (res + dp[id]) % mod;
		}
	}
	cout << res << endl;
}