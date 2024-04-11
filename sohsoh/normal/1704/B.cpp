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
const ll INF = 1e18;

inline pll unite(pll a, pll b) {
	return {max(a.X, b.X), min(a.Y, b.Y)};
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		pll f = {-INF, INF};
		ll n, x;
		cin >> n >> x;

		int ans = 0;
		for (int i = 1; i <= n; i++) {
			int a;
			cin >> a;
			f = unite(f, {a - x, a + x});

			if (f.X > f.Y) {
				f = {a - x, a + x};
				ans++;
			}
		}

		cout << ans << endl;
	}
	return 0;
}