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
const ll OVF = 2e18;

string s;
vector<pair<ll, pll>> vec;
ll sz, c, q;

inline void solve() {
	vec.clear();
	cin >> sz >> c >> q >> s;
	s = "#" + s;
	vec.push_back({sz, {1, sz}});

	for (int i = 1; i <= c; i++) {
		ll l, r;
		cin >> l >> r;
		sz += (r - l + 1);

		if (sz >= OVF) {
			sz = OVF;
			continue;
		}

		vec.push_back({sz, {l, r}});
	}
	
	while (q--) {
		ll ind;
		cin >> ind;

		for (int i = int(vec.size()) - 1; i > 0; i--) {
			if (ind <= vec[i - 1].X) continue;
			ind -= vec[i - 1].X + 1;
			ind += vec[i].Y.X;
		}

		cout << s[ind] << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}