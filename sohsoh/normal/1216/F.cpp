#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
 
#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
 
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}
 
const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

void upd(ll& a, ll b) {
	a = min(a, b);
}

ll dp[MAXN][2];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll n, k;
	string s;
	cin >> n >> k >> s;
	for (int i = 0; i < MAXN; i++) dp[i][0] = dp[i][1] = INF;
	dp[0][0] = 0;
	multiset<ll> mn_st, mn_st2;
	set<pll> ind_st, ind_st2;
	ind_st2.insert({0, 0});
	mn_st2.insert(0);
	for (int i = 1; i <= n; i++) {
		while (!ind_st.empty() && i - (ind_st.begin() -> X) > k) {
			mn_st.erase(mn_st.find(ind_st.begin() -> Y));
			ind_st.erase(ind_st.begin());
		}
		
		while (!ind_st2.empty() && i - (ind_st2.begin() -> X) > k + 1) {
			mn_st2.erase(mn_st2.find(ind_st2.begin() -> Y));
			ind_st2.erase(ind_st2.begin());
		}
		
		upd(dp[i][0], dp[i - 1][1]);
		upd(dp[i][0], dp[i - 1][0] + i);
		if (!mn_st.empty()) upd(dp[i][0], *mn_st.begin());
		if (s[i - 1] == '1') {
			upd(dp[i][1], (*mn_st2.begin()) + i);
			ind_st.insert({i, dp[i][1]});
			mn_st.insert(dp[i][1]);
		}

		ll x = min(dp[i][0], dp[i][1]);
		ind_st2.insert({i, x});
		mn_st2.insert(x);
	}
	
	cout << min(dp[n][0], dp[n][1]) << endl;
	return 0;
}