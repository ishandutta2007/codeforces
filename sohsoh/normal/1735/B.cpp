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
		int n, mn;
		cin >> n >> mn;

		ll ans = 0;
		for (int i = 2; i <= n; i++) {
			int x;
			cin >> x;
			ans += (x + 2 * mn - 2) / (2 * mn - 1) - 1;
		}

		cout << ans << endl;
	}
	return 0;
}