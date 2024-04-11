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
		int n;
		cin >> n;
		ll ans = 0;
		bool flag1 = false, flag2 = false;
		for (int i = 1; i <= n; i++) {
			ll x;
			cin >> x;
			if (i == 1 || i == n) continue;

			ans += x / 2;
			if (x & 1) ans++;
			if (x % 2 == 0) flag1 = true;
			if (x > 1) flag2 = true;
		}

		if (flag1 || (n != 3 && flag2)) cout << ans << endl;
		else cout << -1 << endl;
	}
	return 0;
}