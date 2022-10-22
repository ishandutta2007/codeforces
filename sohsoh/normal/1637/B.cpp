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

int n;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		ll ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			int x;
			cin >> x;
			ans += i * (n - i + 1);
			if (x == 0) ans += i * (n - i + 1);
		}

		cout << ans << endl;
	}
	return 0;
}