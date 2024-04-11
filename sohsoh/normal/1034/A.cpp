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
 
const ll MAXN = 15 * 1e6 + 1000;
const ll MAXN2 = 1e6;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int A[MAXN] = {0}, spf[MAXN] = {0}, n;
int cnt[MAXN] = {0};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);	
	ll n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> A[i];
	int g = A[0];
	for (int i = 0; i < n; i++) g = __gcd(A[i], g);
	for (int i = 0; i < n; i++) A[i] /= g;
	spf[1] = 1;
	for (int i = 2; i < MAXN; i++) spf[i] = i;
	for (int i = 4; i < MAXN; i += 2) spf[i] = 2;
	for (ll i = 3; i * i < MAXN; i++) {
		if (spf[i] == i) {
			for (ll j = i * i; j < MAXN; j += i) {
				if (spf[j] == j) spf[j] = i;
			}
		}
	}

	set<ll> pf;
	for (int i = 0; i < n; i++) {
		ll pp = -1;
		while (A[i] > 1) {
			ll p = spf[A[i]];
			A[i] /= p;
			pf.insert(p);
			if (p != pp) cnt[p]++;
			pp = p;
		} 
	}

	ll ans = INF;
	for (ll e : pf) {
		if (cnt[e] < n) ans = min(ans, n - cnt[e]);
	}

	if (ans > n) ans = -1;
       	cout << ans << endl;	
	
	
	return 0;
}