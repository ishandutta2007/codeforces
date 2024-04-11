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

inline int solve() {
	string s;
	cin >> s;

	int c0 = 0, c1 = count(all(s), '1'), ans = c1, p = int(s.size()) - 1;
	for (int i = int(s.size()) - 1; i >= 0; i--) {
		c1 -= (s[i] == '1');
		c0 += (s[i] == '0');

		while (p > i && c1 + (s[p] == '1') <= c0 - (s[p] == '0')) {
			c1 += (s[p] == '1');
			c0 -= (s[p] == '0');
			p--;
		}

		ans = min(ans, max(c0, c1));
	}

	cout << ans << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}