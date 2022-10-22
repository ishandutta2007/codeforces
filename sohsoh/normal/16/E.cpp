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
 
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}
 
const ll MAXN = 18;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ld dp[262144 + 10] = {0}, P[MAXN][MAXN];


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cin >> P[i][j];
	}

	ll p = (1 << n);
	dp[p - 1] = 1;
	for (int msk = p - 1; msk > 0; msk--) {
		vector<ll> v;
		ll k = msk, j = 0;
		while (k > 0) {
			if (k & 1) v.push_back(j);
			k /= 2;
			j++;
		}

		for (int i = 0; i < v.size(); i++) {
			for (j = i + 1; j < v.size(); j++) {
				dp[msk - (1 << v[i])] += dp[msk] * P[v[j]][v[i]] / ld(ll(v.size()) * ll(v.size() - 1) / 2);
				dp[msk - (1 << v[j])] += dp[msk] * P[v[i]][v[j]] / ld(ll(v.size()) * ll(v.size() - 1) / 2);
			}
		}
	}
	
	cout << setprecision(15) << fixed << endl;
	for (int i = 0; i < n; i++) cout << dp[(1 << i)] << sep;
	cout << endl;

	return 0;
}