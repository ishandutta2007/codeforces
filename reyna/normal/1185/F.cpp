
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
const int N = (int) 512, mod = (int) 0;
int fr[N], fr_sum[N], best[N][3];
pair<int, int> par[N][3];
int32_t main() {
	ios_base::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	while (n--) {
		int k;
		cin >> k;
		int mask = 0;
		while (k--) {
			int x;
			cin >> x;
			--x;
			mask |= 1 << x;
		}
		fr[mask]++;
	}
	for (int mask = 0; mask < N; ++mask)
		for (int submask = 0; submask <= mask; ++submask)
			if ((mask & submask) == submask)
				fr_sum[mask] += fr[submask];
	memset(best, 63, sizeof best);
	memset(par, -1, sizeof par);
	best[0][0] = 0;
	for (int j = 0; j < m; ++j) {
		int cost, k;
		cin >> cost >> k;
		int cur_mask = 0;
		while (k--) {
			int x;
			cin >> x;
			--x;
			cur_mask |= 1 << x;
		}
		for (int pizza = 1; pizza >= 0; --pizza) {
			for (int mask = 0; mask < N; ++mask) {
				best[mask | cur_mask][pizza + 1] = min(best[mask | cur_mask][pizza + 1], best[mask][pizza] + cost);
				if (best[mask | cur_mask][pizza + 1] == best[mask][pizza] + cost) {
					par[mask | cur_mask][pizza + 1] = mp(j, par[mask][pizza].first);
				}
			}
		}
	}
	int mx = 0, mn = 2e9 + 1;
	for (int mask = 0; mask < N; ++mask) 
		if (best[mask][2] < 2e9 + 1) {
			mx = max(mx, fr_sum[mask]);
		}
	for (int mask = 0; mask < N; ++mask) 
		if (best[mask][2] < 2e9 + 1) {
			if (mx == fr_sum[mask])
				mn = min(mn, best[mask][2]);
		}
	for (int mask = 0; mask < N; ++mask) {
		if (best[mask][2] < 2e9 + 1) {
			if (mx == fr_sum[mask] && mn == best[mask][2]) {
				cout << par[mask][2].first + 1 << ' ' << par[mask][2].second + 1 << endl;
				return 0;
			}
		}
	}
}