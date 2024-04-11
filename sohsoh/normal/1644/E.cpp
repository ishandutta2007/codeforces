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

ll suff[MAXN], n, m;
string s;

inline int solve() {
	for (int i = 0; i < m + 10; i++)
		suff[i] = 0;

	cin >> n >> s;
	m = s.size();

	ll r = count(all(s), 'R'), d = count(all(s), 'D');
	r = n - 1 - r;
	d = n - 1 - d;
	if (r == n - 1 || d == n - 1) return cout << n << endl, 0;

	suff[m - 1] = 1;
	for (int i = m - 2; i >= 0; i--) {
		if (s[i] == s[i + 1]) suff[i] = suff[i + 1] + 1;
		else suff[i] = 1;
	}


	ll ans = 1 + suff[0] + (s[0] == 'R' ? r : d);

	ll x = 0, y = 0;
	bool vis_d = false, vis_r = false;
	for (int i = 0; i < m; i++) {
		char c = s[i];
		if (c == 'D') {
			x++;
			ll tmp = 0;
			if (i < m - 1 && s[i] != s[i + 1]) tmp = suff[i + 1];
			if (vis_r || tmp) ans += tmp + r;

			vis_d = true;
		} else {	
			y++;
			ll tmp = 0;
			if (i < m - 1 && s[i] != s[i + 1]) tmp = suff[i + 1];
			if (vis_d || tmp) ans += tmp + d;	
			
			vis_r = true;
		}
	}

	ans += (n - 1 - x) * (n - 1 - y);
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