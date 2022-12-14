
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

const int N = (int) 5005, mod = (int) 1e9 + 7;
int s[N], f[N], h[N], lft[N], rgt[N], dp[2], odp[2], lf[N], rg[N], bt[N];
int main() {
	int n, m;
	cin >> n >> m;
	for (int j = 1; j <= n; ++j) cin >> s[j], --s[j];
	++n;
	s[0] = n;
	for (int j = 0; j <= m; ++j) {
		if (j != m) {
			cin >> f[j] >> h[j];
			--f[j];
		} else {
			f[j] = n;
			h[j] = 1;
		}
		int cnt = 0;
		lft[j] = -1;
		rgt[j] = -1;
		for (int i = 0; i < n; ++i) {
			if (f[j] == s[i]) {
				++cnt;
			}
			if (cnt == h[j]) {
				lft[j] = i;
				break;
			}
		}
		cnt = 0;
		for (int i = n - 1; i >= 0; --i) {
			if (f[j] == s[i]) {
				++cnt;
			}
			if (cnt == h[j]) {
				rgt[j] = i;
				break;
			}
		}
	}
	++m;
	int mx = 0, res = 1;
	for (int leftmost = 0; leftmost < n; ++leftmost) {
		memset(rg, 0, sizeof rg);
		memset(lf, 0, sizeof lf);
		memset(bt, 0, sizeof bt);
		int cur_res = 1, cnt = 1, flag = 0, g = -1;
		for (int j = 0; j < m; ++j)
			if (leftmost == lft[j]) {
				flag = 1;
				g = f[j];
			}
		if (!flag) continue;
		for (int j = 0; j < m; ++j) {
			if (lft[j] == -1) continue;
			if (leftmost == lft[j]) continue;
			if (lft[j] < leftmost && rgt[j] > leftmost) {
				if (g == f[j]) {
					rg[f[j]]++;	
				} else {
					bt[f[j]]++;
				}
			} else if (lft[j] < leftmost) {
				if (g == f[j]) continue;
				lf[f[j]]++;
			} else if (rgt[j] > leftmost) {
				rg[f[j]]++;
			}
		}
		
		for (int c = 0; c < n; ++c) {
			if (!!lf[c] + !!rg[c] + bt[c] > 1) {
				cnt += 2;
				int ways = 0;
				if (bt[c] > 1) {
					ways = (ways + (LL) bt[c] * (bt[c] - 1)) % mod;
				}
				ways = (ways + (LL) lf[c] * rg[c]) % mod;
				ways = (ways + (LL) lf[c] * bt[c]) % mod;
				ways = (ways + (LL) bt[c] * rg[c]) % mod;
				cur_res = (LL) cur_res * ways % mod;
			} else if (!!lf[c] + !!rg[c] + bt[c] == 1) {
				cnt++;
				if (bt[c]) cur_res = (LL) cur_res * 2 % mod;
				else {
					if (lf[c]) cur_res = (LL) cur_res * lf[c] % mod;
					else cur_res = (LL) cur_res * rg[c] % mod;
				}
			}
		}
		cnt += (leftmost != 0);
		if (cnt > mx) {
			mx = cnt;
			res = 0;
		}
		if (cnt == mx) res = (res + cur_res) % mod;
	}
	cout << mx-1 << ' ' << res << endl;
}