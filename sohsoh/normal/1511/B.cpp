#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int d(ll n) {
	int ans = 0;
	while (n) {
		ans++;
		n /= 10;
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int a, b, c;
		cin >> a >> b >> c;
		ll x = 1, y = 1;
		while (d(x) < c)
			x = x * 2;

		y = x;
		while (d(x) < a) x = x * 3;
		while (d(y) < b) y = y * 5;
		cout << x << sep << y << endl;
	}
	return 0;
}