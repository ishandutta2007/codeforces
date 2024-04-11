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

map<int, int> mp[2]; // L, U

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, q;
	cin >> n >> q;
	mp[0][n + 1] = mp[1][0] = 0;

	while (q--) {
		int x, y;
		char c;
		cin >> x >> y >> c;
		swap(x, y);
		
		if (c == 'L') {
			auto it = mp[0].lower_bound(x);
			if (it -> X == x) {
				cout << 0 << endl;
				continue;
			}

			int ans = it -> X - x + it -> Y;
			auto it2 = mp[1].lower_bound(x);

			if (it2 != mp[1].end() && it2 -> X == x) {
				cout << 0 << endl;
				continue;
			}

			if (it2 != mp[1].end() && it2 -> X < it -> X) ans = min(ans, it2 -> X - x);
			
			mp[0][x] = ans;
			cout << ans << endl;
		} else {
			auto it = prev(mp[1].upper_bound(x));
			if (it -> X == x) {
				cout << 0 << endl;
				continue;
			}

			int ans = x - it -> X + it -> Y;
			auto it2 = mp[0].upper_bound(x);

			if (it2 != mp[0].begin() && prev(it2) -> X == x) {
				cout << 0 << endl;
				continue;
			}

			if (it2 != mp[0].begin() && prev(it2) -> X > it -> X) ans = min(ans, x - prev(it2) -> X);

			mp[1][x] = ans;
			cout << ans << endl;
		}
	}
	return 0;
}