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

ll A[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	vector<ll> v;
	for (int i = 0; i < 2 * n; i++) {
		ll x;
		cin >> x;
		v.push_back(x);
	}

	ll ans = 0;

	for (int i = 0; i < v.size(); i += 2) {
		for (int j = i + 1; j < v.size(); j++) {
			if (v[j] == v[i]) {
				v.erase(v.begin() + j);
				v.insert(v.begin() + i, v[i]);
				ans += j - i - 1;
			}
		}
	}
	
	cout << ans << endl;
	return 0;
}