#pragma comment(linker, "/STACK:256000000")
#pragma GCC optimize("O3")

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <assert.h>
#include <set>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <random>
#include <map>
#include <bitset>
#include <deque>
#include <chrono>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define endl '\n'

#define X first
#define Y second

using namespace std;

mt19937 rng(time(NULL));

using ll = long long;
using vi = vector<int>;
using graph = vector<vi>;
using vl = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using ld = long double;
using vb = vector<bool>;

const ll MOD = 998244353;
const int INF = 1000000007;
const ll LINF = 4e18;

struct dsu {
	vector<int> lnk;
	vector<int> rnk;

	dsu(int n) {
		lnk.resize(n);
		rnk.resize(n);
		for (int i = 0; i < n; i++) lnk[i] = i, rnk[i] = 1;
	}

	int get_parent(int v) {
		if (v == lnk[v]) return v;
		else return lnk[v] = get_parent(lnk[v]);
	}

	bool same(int u, int v) {
		return get_parent(u) == get_parent(v);
	}

	void merge(int u, int v) {
		u = get_parent(u);
		v = get_parent(v);
		if (u == v) return;
		if (rnk[u] < rnk[v]) {
			lnk[u] = v;
			rnk[v] += rnk[u];
		}
		else {
			lnk[v] = u;
			rnk[u] += rnk[v];
		}
	}
};

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	if (a < b) return gcd(b, a);
	return gcd(b, a % b);
}


int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> aggr(n);
	for (int i = 0; i < n; i++) {
		cin >> aggr[i];
		aggr[i]--;
	}

	vector<int> cost(n);
	for (int i = 0; i < n; i++) cin >> cost[i];

	vector<int> revenue(n + m);
	for (int i = 0; i < n + m; i++) cin >> revenue[i];

	vector<vector<ll>> dp(m, vector<ll>(1, 0));

	for (int i = n - 1; i >= 0; i--) {
		vector<ll> new_dp = dp[aggr[i]];
		new_dp.pb(new_dp.back() + revenue[aggr[i]] - cost[i]);
		for (int j = sz(new_dp) - 2; j > 0; j--) {
			new_dp[j] = max(new_dp[j], new_dp[j - 1] + revenue[aggr[i]] - cost[i]);
		}

		for (int j = 0; j < aggr[i]; j++) {
			for (int k = 0; k < sz(dp[j]); k++) {
				ll assaults = 0;
				int alive = k;
				int cur_aggr = j;

				while (alive > 1 && cur_aggr < aggr[i]) {
					assaults += (alive / 2) * revenue[cur_aggr + 1];
					alive /= 2;
					cur_aggr++;
				}

				if (cur_aggr < aggr[i]) alive = 0;

				while (alive + 1 >= sz(new_dp)) new_dp.pb(-LINF);

				new_dp[alive] = max(new_dp[alive], dp[j][k] + assaults);
				new_dp[alive + 1] = max(new_dp[alive + 1], dp[j][k] + assaults + revenue[aggr[i]] - cost[i]);
			}
		}

		dp[aggr[i]] = new_dp;
	}

	ll ans = -LINF;

	for (int j = 0; j < m; j++) {
		for (int k = 0; k < sz(dp[j]); k++) {
			ll assaults = 0;
			int alive = k;
			int cur_aggr = j;

			while (alive > 1) {
				assaults += (alive / 2) * revenue[cur_aggr + 1];
				alive /= 2;
				cur_aggr++;
			}

			ans = max(ans, dp[j][k] + assaults);
		}
	}

	cout << ans << endl;

	return 0;
}