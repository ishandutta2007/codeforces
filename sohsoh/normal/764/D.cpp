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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	cout << "YES" << endl;
	for (int i = 0; i < n; i++) {
		ll x, y, x0, y0;
		cin >> x >> y >> x0 >> y0;

		x += int(1e9);
		y += int(1e9);
		if (x % 2 == 0 && y % 2 == 0) cout << 1 << endl;
		else if (x % 2 == 0 && y % 2 == 1) cout << 2 << endl;
		else if (x % 2 == 1 && y % 2 == 0) cout << 3 << endl;
		else if (x % 2 == 1 && y % 2 == 1) cout << 4 << endl;
	}
	return 0;
}