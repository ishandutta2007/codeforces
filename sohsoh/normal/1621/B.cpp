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

template<typename T>
inline void F(map<T, ll>& a, T b, ll c) {
	if (a.find(b) != a.end()) a[b] = min(a[b], c);
	else a[b] = c;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		map<pll, ll> mp;
		map<ll, ll> mp_l, mp_r;
		
		ll r = -1, l = ll(1e9 + 10);
		while (n--) {
			ll tl, tr, c;
			cin >> tl >> tr >> c;
			r = max(r, tr);
			l = min(l, tl);
			
			F(mp, make_pair(tl, tr), c);
			F(mp_l, tl, c);
			F(mp_r, tr, c);

			ll ans = ll(2e9 + 10);
			if (mp.find(make_pair(l, r)) != mp.end()) ans = mp[make_pair(l, r)];
			ans = min(ans, mp_l[l] + mp_r[r]);
			cout << ans << endl;
		}
	}
	return 0;
}