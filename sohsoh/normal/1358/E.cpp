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

ll A[MAXN], n, x, s, pref[MAXN] = {0}, pmin[MAXN] = {0};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < (n + 1) / 2; i++) cin >> A[i], s += A[i], pref[i + 1] = pref[i] + A[i];
	cin >> x;
	for (int i = (n + 1) / 2; i < n; i++) A[i] = x, pref[i + 1] = pref[i] + A[i];
	s += x * (n / 2);
	if (s > 0) return cout << n << endl, 0;
      	if (x >= 0) return cout << -1 << endl, 0;

	ll k = n / 2 + 1;
	pmin[0] = INF;
	for (int i = k; i <= n; i++) pmin[i - k + 1] = min(pmin[i - k], pref[i] - pref[i - k]);
	ll ind = n - k + 1, neg = 0;
	while (k < n) {
		if (pmin[ind] + neg > 0) return cout << k << endl, 0;
		k++;
		ind--;
		neg += x;
	}

	cout << -1 << endl;
	return 0;
}