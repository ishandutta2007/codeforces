/*
    Soheil Mohammadkhani
    Sos Goge Tabarok :)
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
 
const ll MAXN = 3e3 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll A[MAXN] = {0}, cnt[MAXN] = {0};
ll op[MAXN] = {0}, P[MAXN] = {0}, B[MAXN];

ll solve() {
	for (int i = 0; i < MAXN; i++) A[i] = cnt[i] = op[i] = P[i] = B[i] = 0;
	ll n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> A[i], cnt[A[i]]++;
	ll tot_op = 0;
	for (int i = 0; i < n; i++) {
		ll x = A[i];
		B[i] = tot_op - op[x];

		ll t = -1 * P[x] + cnt[x] - P[x] - 1;
		op[x] += t;
		tot_op += t;
		P[x]++;
	}

	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ll x = 0;
		for (int j = i + 1; j < n; j++) if (A[i] == A[j]) ans += B[j], x++;
		for (int j = i + 1; j < n; j++) {
			if (A[i] != A[j]) B[j] -= x;
			else x--;
		}
	}
	
	for (int i = 0; i < MAXN; i++) ans += cnt[i] * (cnt[i] - 1) * (cnt[i] - 2) * (cnt[i] - 3) / 24;

	cout << ans << endl;
	return 0;
}

int main() {
	fast_io;
	ll t;
	cin >> t;
	while (t--) solve();
	
	return 0;
}