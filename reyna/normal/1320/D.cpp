
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
const int N = (int) 1e6 + 6, base0 = 727, base1 = 97, mod1 = (int) 1e9 + 9, mod0 = 1e9 + 7, L = 5;
int go_r[N], sum[N], go_l[N], h0[N], pw0[N], h1[N], pw1[N];
string s;
vector<int> all;
int get_hash(int xl, int xr, int h[N], int pw[N], int mod) {
	if (xl >= xr) return 0;
	return (h[xr] - h[xl] * (LL) pw[xr-xl] % mod + mod) % mod;
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	cin >> s;
	go_l[0] = -1;
	go_r[n-1] = n;
	for (int j = 0; j < n; ++j) sum[j + 1] = (sum[j] + (s[j] == '0'));
	for (int j = 1; j < n; ++j) {
		if (s[j] == '0') go_l[j] = j-1;
		if (s[j] == '1' && s[j - 1] == '0') go_l[j] = j - 1;
		if (s[j] == '1' && s[j - 1] == '1') go_l[j] = go_l[j-1];
	}
	for (int j = n - 2; j >= 0; --j) {
		if (s[j] == '0') go_r[j] = j+1;
		if (s[j] == '1' && s[j + 1] == '0') go_r[j] = j+1;
		if (s[j] == '1' && s[j + 1] == '1') go_r[j] = go_r[j+1];
	}
	{
		int cur = 0;
		while (cur < n) {
			int cnt = (go_r[cur] - cur) & 1;
			if (cnt) all.pb(cur);
			cur = go_r[cur];
		}
	}
	pw1[0] = pw0[0] = 1;
	for (int j = 1; j < N; ++j) pw0[j] = (LL) pw0[j - 1] * base0 % mod0, pw1[j] = (LL) pw1[j - 1] * base1 % mod1;
	for (int j = 0; j < (int) all.size(); ++j) {
		h0[j+1] = (h0[j] * (LL) base0 + s[all[j]]) % mod0;
		h1[j+1] = (h1[j] * (LL) base1 + s[all[j]]) % mod1;
	}
	int q;
	cin >> q;
	while (q--) {
		int xl, yl, len;
		cin >> xl >> yl >> len;
		--xl, --yl;
		int xr = xl + len, yr = yl + len;
		{
			vector<int> sx, sy;
			while (xl < xr) {
				int s = (min(go_r[xl], xr) - xl) & 1;
				if (s) {
					if (sx.size() == L) break;
					sx.pb(::s[xl]);
				}
				xl = go_r[xl];
			}
			while (yl < yr) {
				int s = (min(go_r[yl], yr) - yl) & 1;
				if (s) {
					if (sy.size() == L) break;
					sy.pb(::s[yl]);
				}
				yl = go_r[yl];
			}
			if (sx != sy) {
				cout << "No\n";
				continue;
			}
		}
		{
			vector<int> sx, sy;
			while (xl < xr) {
				int s = (xr-1 - (max(xl-1, go_l[xr-1]))) & 1;
				if (s) {
					if (sx.size() == L) break;
					sx.pb(::s[xr-1]);
				}
				xr = go_l[xr-1]+1;
			}
			while (yl < yr) {
				int s = (yr-1 - (max(yl-1, go_l[yr-1]))) & 1;
				if (s) {
					if (sy.size() == L) break;
					sy.pb(::s[yr-1]);
				}
				yr = go_l[yr-1]+1;
			}
			if (sx != sy) {
				cout << "No\n";
				continue;
			}
		}
		if (xl >= xr && yl >= yr) {
			cout << "Yes\n";
			continue;
		}
		if (xl >= xr || yl >= yr) {
			cout << "No\n";
			continue;
		}
		xl = lower_bound(ALL(all), xl) - all.begin();
		yl = lower_bound(ALL(all), yl) - all.begin();
		xr = lower_bound(ALL(all), xr) - all.begin();
		yr = lower_bound(ALL(all), yr) - all.begin();
		if (get_hash(xl, xr, h0, pw0, mod0) == get_hash(yl, yr, h0, pw0, mod0) &&
			get_hash(xl, xr, h1, pw1, mod1) == get_hash(yl, yr, h1, pw1, mod1)) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
		
	}
}