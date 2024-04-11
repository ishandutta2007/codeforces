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
		ll n, k, b, s;
		cin >> n >> k >> b >> s;
		if (s < k * b || s > k * b + n * (k - 1)) cout << -1 << endl;
		else {
			s -= k * b;
			for (int i = 1; i < n; i++) {
				int x = min(k - 1, s);
				cout << x << sep;
				s -= x;
			}

			cout << b * k + s << endl;
		}
	}
	return 0;
}