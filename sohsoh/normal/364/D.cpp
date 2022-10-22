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

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, A[MAXN], cnt[MAXN], dp[MAXN], P_MASK[MAXN];
unordered_map<ll, ll> mp;

inline bool is_prime(ll x) {
	if (x == 1) return false;
	for (ll i = 2; i * i <= x; i++) if (x % i == 0) return false;
	return true;
}

inline ll solve(ll x) {
	memset(cnt, 0, sizeof cnt);
	memset(dp, 0, sizeof dp);
	memset(P_MASK, 0, sizeof P_MASK);
	mp.clear();
	vector<ll> D, P;
	
	for (ll i = 1; i * i <= x; i++) {
		if (x % i) continue;
		D.push_back(i);
		if (is_prime(i)) P.push_back(i);
		
		if (i * i != x) {
			D.push_back(x / i);
			if (is_prime(x / i)) P.push_back(x / i);
		}
	}

	sort(all(D));
	sort(all(P));
	for (int i = 0; i < D.size(); i++) mp[D[i]] = i;

	for (int i = 1; i <= n; i++) {
		ll t = __gcd(A[i], x);
		int ind = mp[t];
		cnt[ind]++;
	}

	int MSK = (1 << P.size());
	P_MASK[0] = 1;
	for (int i = 1; i < MSK; i++) {
		int x = __builtin_ctz(i);
		P_MASK[i] = P_MASK[i ^ (1 << x)] * P[x]; 
	}

	dp[0] = 0;
	for (int i = D.size() - 1; i >= 0; i--) {
		dp[i] = cnt[i];	
		for (int msk = 1; msk < MSK; msk++) {
			ll x = P_MASK[msk] * D[i];
			int ind = mp[x];
			if (__builtin_popcount(msk) & 1) dp[i] += dp[ind];
			else dp[i] -= dp[ind];
		}

		if (dp[i] >= (n + 1) / 2) return D[i];
	}

	return 1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];

	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	int q = 7;
	ll ans = 1;
	while (q--) {
		int ind = rng() % n + 1;
		ans = max(ans, solve(A[ind]));
	}
	
	cout << ans << endl;
	return 0;
}