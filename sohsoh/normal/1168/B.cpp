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

ll R[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string s;
	cin >> s;
	if (s.size() < 3) return cout << 0 << endl, 0; 
	ll n = s.size();
	R[n - 1] = INF;
	R[n - 2] = INF;
	for (int i = n - 3; i >= 0; i--) {
		R[i] = R[i + 1];
		for (int j = 1; i + 2 * j <= min(n - 1, R[i]); j++) {
			if (s[i] == s[i + j] && s[i + j] == s[i + 2 * j]) {
				R[i] = i + 2 * j;
				break;
			}
		}
	}

	ll ans = 0;
	for (int i = 0; i < n; i++) {
		if (R[i] >= n) continue;
		ans += n - R[i];
	}

	cout << ans << endl;
	return 0;
}