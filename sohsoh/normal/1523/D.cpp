#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define int 			    ll

const ll MAXN = 2e5 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n, m, p;
ll B[MAXN];
int dp[MAXN];

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll F(int r) {
	memset(dp, 0, sizeof dp);
	vector<int> v;
	for (int j = 0; j < m; j++) {
		if (B[r] & (1ll << j))
			v.push_back(j);
	}

	for (int i = 0; i < n; i++) {
		int tmask = 0;
		for (int j = 0; j < v.size(); j++) {
			if (B[i] & (1ll << v[j]))
				tmask ^= (1ll << j);	
		}
	
		dp[tmask]++;
	}

	for (int i = 0; i < v.size(); i++) 
		for (int mask = (1ll << v.size()); mask >= 0; mask--)
			if ((mask & (1ll << i)) == 0)
				dp[mask] += dp[mask ^ (1ll << i)];
	ll ans = 0;			
	for (int mask = 0; mask < (1 << v.size()); mask++) {
		if (__builtin_popcountll(mask) < __builtin_popcountll(ans) || dp[mask] < (n + 1) / 2) continue;
		ans = 0;
		for (int i = 0; i < v.size(); i++)
			if (mask & (1ll << i))
				ans ^= (1ll << v[i]);
	}

	return ans;

}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m >> p;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;
			if (c == '1') B[i] ^= (1ll << j);
		}
	}

	ll ans = 0;
	int cnt = 20;
	while (cnt--) {
		ll tans = F(rng() % n);
		if (__builtin_popcountll(tans) > __builtin_popcountll(ans)) ans = tans;
	}

	for (int i = 0; i < m; i++) {
		if (ans & (1ll << i)) cout << 1;
		else cout << 0;
	}

	cout << endl;

	return 0;
}