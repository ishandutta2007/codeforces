#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		ll s = 0, mx = 0, p = 0;
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			ll x;
			cin >> x;
			while (x % 2 == 0) {
				x = x / 2;
				p++;
			}

			s += x;
			mx = max(mx, x);
		}

		s -= mx;
		while (p--) mx = mx * 2;
		s += mx;
		cout << s << endl;
	}
	return 0;
}