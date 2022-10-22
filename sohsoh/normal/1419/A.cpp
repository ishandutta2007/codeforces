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

void solve() {
	ll n;
	string s;
	cin >> n >> s;
	ll o_e = 0, e_o = 0, o_o = 0, e_e = 0;
	for (int i = 0; i < n; i++) {
		ll ind = i + 1;
		int x = s[i] - '0';
		if (x % 2) {
			if (ind % 2) o_o++;
			else e_o++;
		} else {
			if (ind % 2) o_e++;
			else e_e++;
		}
	}

	bool turn = false;
	while (o_e + e_o + o_o + e_e > 1) {
		if (turn) {
			if (e_o) e_o--;
			else e_e--;
		} else {
			if (o_e) o_e--;
			else o_o--;
		}

		turn = !turn;
	}

	if (o_o > 0 || e_o > 0) cout << 1 << endl;
	else cout << 2 << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll t;
	cin >> t;
	while (t--) solve();
	return 0;
}