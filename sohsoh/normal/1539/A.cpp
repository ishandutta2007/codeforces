// \_()_/
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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		ll n, x, t;
		cin >> n >> x >> t;
		ll L = 0, R = n;
		while (L < R) {
			ll mid = (L + R + 1) >> 1;
			if (mid * x <= t) L = mid;
			else R = mid - 1;
		}
		
		if (L > n - 1) L = n - 1;
		cout << L * (L + 1) / 2 + (n - L - 1) * L << endl;
	}
	return 0;
}