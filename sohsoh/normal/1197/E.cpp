#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
 
#define int			    long long
#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;
 
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}
 
const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

map<int, vector<pll>> mp;
int n, dp[MAXN], pref_mn[MAXN], cnt[MAXN];
vector<pll> v;

// make it ll :/

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	v.resize(n);
	v.push_back({0, -INF});
	for (int i = 0; i < n; i++) cin >> v[i].X >> v[i].Y;
	sort(all(v));	
	mp[0].push_back({0, 1});
	for (int i = 1; i <= n; i++) {
		int score = v[i].Y - v[i].X;
		int L = 0, R = i - 1;
		while (L < R) {
			int mid = (L + R + 1) / 2;
			if (v[mid].X <= v[i].Y) L = mid;
			else R = mid - 1;
		}

		int score_p = pref_mn[L];
		dp[i] = score + score_p;
		
		if (!mp[score_p].empty()) {
			auto it = upper_bound(all(mp[score_p]), make_pair(L, INF));
			if (it != mp[score_p].begin()) {	
				it--;			
				cnt[i] = it -> Y;
			}
		}

		ll pb_val = cnt[i];
		if (!mp[dp[i]].empty())	pb_val += mp[dp[i]].back().Y;
		mp[dp[i]].push_back({i, pb_val % MOD});

		pref_mn[i] = min(pref_mn[i - 1], dp[i]);
	}
/*
	cerr << "WOW :/" << endl;
	for (pll e : v) cerr << e.X << sep << e.Y << endl;
	cerr << "_____" << endl;
	for (int i = 1; i <= n; i++) {
		debug(dp[i]);
		debug(cnt[i]);
		debug(dp[i] + v[i].X);
		debug("________")
	}
*/
	ll ans = 0, mn_found = INF, mx_in = 0;
	for (int i = 1; i <= n; i++) dp[i] += v[i].X;
	// check for maximality from right :/
	for (int i = n; i > 0; i--) {
		if (v[i].X <= mx_in) break;
		if (dp[i] > mn_found) {
			mx_in = max(v[i].Y, mx_in);
			continue;
		}

		if (dp[i] < mn_found) {
			mn_found = dp[i];
			ans = 0;
		}

		ans += cnt[i];
		ans %= MOD;
		mx_in = max(mx_in, v[i].Y);
	}

	cout << ans % MOD << endl;
	return 0;
}