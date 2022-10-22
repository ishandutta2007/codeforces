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

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

inline int solve() {
	int a1, a2, a3, a4, a5, c1, c2, c3;
	cin >> c1 >> c2 >> c3;
	cin >> a1 >> a2 >> a3 >> a4 >> a5;
       	c1 -= a1;	
       	c2 -= a2;
	c3 -= a3;
	if (c1 < 0 || c2 < 0 || c3 < 0) return cout << "NO" << endl, 0;
	c3 -= a4 - min(a4, c1);
	c3 -= a5 - min(a5, c2);
	if (c3 < 0) return cout << "NO" << endl, 0;
	cout << "YES" << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}