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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll n, m, k;
	cin >> n >> m >> k;
	set<pll> st;
	for (int i = 0; i < m; i++) {
		ll x;
		cin >> x;
		x--;
		st.insert({x, i});
	}

	ll op = 0;
	while (!st.empty()) {
		pll e = *st.begin();
		ll x = e.X - e.Y;
		ll g = e.X + k - x % k;
		while (!st.empty() && st.begin() -> X < g)
			st.erase(st.begin());
		
		op++;
	}

	cout << op << endl;
	return 0;
}