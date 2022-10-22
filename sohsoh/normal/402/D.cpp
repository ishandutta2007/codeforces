/*
    Soheil Mohammadkhani
    OK, im back :)
*/
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
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}
 
const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll f[MAXN] = {0}, A[MAXN], g[MAXN], gf[MAXN] = {0}, dp[MAXN] = {0};

bool is_prime_opt[MAXN];

bool is_prime(ll n, bool test = false) {
	 if (n == 1 || n == 1000000000ll) return false;
	 if (!test && n < 100000) return is_prime_opt[n];
	 ll sq = sqrt(n);
	 for (int i = 2; i <= sq; i++) if (n % i == 0) return false;
	 return true; 
}


int main() {
	fast_io;
	ll n, m;
	cin >> n >> m;
	map<ll, ll> mp;
	for (int i = 2; i < 100000; i++) is_prime_opt[i] = is_prime(i, true);
	//alog(is_prime_opt, 10)
	for (int i = 0; i < n; i++) cin >> A[i];
	g[0] = A[0];
	for (int i = 1; i < n; i++) g[i] = __gcd(A[i], g[i - 1]);
	set<ll> bad;
	for (int i = 0; i < m; i++) {
		ll x;
		cin >> x;
		bad.insert(x);
	}

	fill(dp, dp + MAXN, -1 * INF);

	for (int i = 0; i < n; i++) {
		if (mp.find(A[i]) != mp.end()) {
			f[i] = mp[A[i]];
			continue;
		}

		ll sq = sqrt(A[i]);
		for (ll j = 1; j <= sq; j++) {
			if (A[i] % j == 0) {
				if (is_prime(j)) {
					ll ad = 1;
					if (bad.find(j) != bad.end()) ad = -1;
					ll x = A[i];
					while (x % j == 0) {
						x /= j;
						f[i] += ad;
					}
				}

				if (A[i] / j != j && is_prime(A[i] / j)) {
					ll ad = 1;
					if (bad.find(A[i] / j) != bad.end()) ad = -1;
					ll x = A[i];
					//if (i == 1) debug(A[i])
					while (x % (A[i] / j) == 0) {
						x /= (A[i] / j);
						f[i] += ad;
					}	
				}
			}			
		}

		mp.insert({A[i], f[i]});	
	}

	for (int i = 0; i < n; i++) {
		if (mp.find(g[i]) != mp.end()) {
			gf[i] = mp[g[i]];
			continue;
		}

		ll sq = sqrt(g[i]);
		for (ll j = 1; j <= sq; j++) {
			if (g[i] % j == 0) {
				if (is_prime(j)) {
					ll ad = 1;
					if (bad.find(j) != bad.end()) ad = -1;
					ll x = g[i];
					while (x % j == 0) {
						x /= j;
						gf[i] += ad;
					}
				}

				if (g[i] / j != j && is_prime(g[i] / j)) {
					ll ad = 1;
					if (bad.find(g[i] / j) != bad.end()) ad = -1;
					ll x = g[i];
					//if (i == 1) debug(g[i])
					while (x % (g[i] / j) == 0) {
						x /= (g[i] / j);
						gf[i] += ad;
					}	
				}
			}			
		}

		mp.insert({g[i], gf[i]});	
	}
	
	for (int i = 0; i < n; i++) gf[i] *= -1;
	for (int i = n - 1; i >= 0; i--) {
		dp[i] = (i + 1) * gf[i]; 
		for (int j = i + 1; j < n; j++) {
			dp[i] = max(dp[i], dp[j] + (i + 1) * (gf[i] - gf[j]));		
			//if (i == 1 && dp[i] == 10) debug(j);
		}
	}
	
	//alog(dp, n);
	ll sum = 0, ans = max(0ll, *max_element(dp, dp + MAXN));
	for (int i = 0; i < n; i++) sum += f[i];
	cout << sum + ans << endl;
}