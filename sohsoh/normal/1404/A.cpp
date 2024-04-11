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

ll solve() {
	ll n, k;
	cin >> n >> k;
	ll o = 0, z = 0;
	string s;
	cin >> s;
	for (int i = 0; i < k; i++) {
		char c = 'N';
		for (int j = i; j < n; j += k) {
			if (c != 'N' && s[j] != '?' && s[j] != c) return cout << "NO" << endl, 0;
		       	if (c == 'N') {
				if (s[j] == '1') c = '1', o++;	
				if (s[j] == '0') c = '0', z++;
			}
		}
	}
	
	if (o <= k / 2 && k - z >= k / 2) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll t;
	cin >> t;
	while (t--) solve();
	return 0;
}