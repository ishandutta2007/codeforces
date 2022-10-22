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

const ll MAXN = 20 + 10;

ll dp[MAXN][MAXN];

inline int solve() {
	ll s, a;
	string ans;

	cin >> a >> s;
	while (s || a) {
		int c = a % 10, b = s % 10;
		s /= 10;
		a /= 10;

		if (c <= b) ans.push_back(char(b - c + '0'));
		else {
			if (s % 10 != 1) return cout << -1 << endl, 0;
			s /= 10;
			b += 10;
			ans.push_back(char(b - c + '0'));
		}
	}

	while (ans.back() == '0') ans.pop_back();
	reverse(all(ans));
	cout << ans << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll t;
	cin >> t;
	while (t--) solve();
	return 0;
}