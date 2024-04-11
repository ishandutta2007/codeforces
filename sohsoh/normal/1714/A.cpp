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
		int n, h, m;
		cin >> n >> h >> m;
		int f = h * 60 + m;

		int ans = MAXN;
		for (int i = 1; i <= n; i++) {
			int a, b;
			cin >> a >> b;

			int x = a * 60 + b;
			if (x >= f) ans = min(ans, x - f);
			else ans = min(ans, x + 60 * 24 - f);
		}

		cout << ans / 60 << sep << ans % 60 << endl;
	}
	return 0;
}