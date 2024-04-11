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

string s, t;
ll n;
vector<ll> ans;

void shift(ll x) {
	string B;
	for (int i = 0; i < x; i++) {
		B.push_back(s.back());
		s.pop_back();
	}

	s = B + s;
	ans.push_back(x);
}

void move_forward(ll ind) {
	shift(n);
	shift(ind);
	shift(1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> s >> t;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (s[j] == t[n - i - 1]) {
				move_forward(j);
				break;
			}
		}
	}

	if (s != t) return cout << -1 << endl, 0;
	cout << ans.size() << endl;
	for (ll e : ans) cout << e << sep;
	cout << endl;
	return 0;
}