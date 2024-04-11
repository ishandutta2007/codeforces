// \_()_/
#include <bits/stdc++.h>

using namespace std;

#define int 			    ll
typedef long long ll;
typedef pair<ll, int> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;
const ll INF = 1e9;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;
const ll SQ = 720;

int n, q, lz[SQ + 10];
vector<pll> v[SQ + 10];

void Update(int ind, int L, int R, ll x) {
	for (pll& e : v[ind])
		if (e.Y >= L && e.Y <= R) 
			e.X += x;
	sort(all(v[ind]));
}

void Update(int L, int R, ll x) {
	int Li = L / SQ, Ri = R / SQ;
	if (Li == Ri) {
		Update(Li, L, R, x);
		return;
	}

	Update(Li, L, R, x);
	Update(Ri, L, R, x);
	for (int i = Li + 1; i < Ri; i++) lz[i] += x;
}

pll Query(ll x) {
	pll ans = {-1, -2};
	for (int i = 0; i < SQ + 10; i++) {
		if (ans.X == -1) {
			auto it = lower_bound(all(v[i]), make_pair(x - lz[i], -1ll));
			if (it != v[i].end() && it -> X == x - lz[i]) ans.X = it -> Y;
		} 
		
		auto it = lower_bound(all(v[i]), make_pair(x - lz[i] + 1, -1ll));
		if (it != v[i].begin()) {
			it = prev(it);
			if (it -> X == x - lz[i]) ans.Y = it -> Y;
		}	
	}	

	return ans;
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		v[i / SQ].push_back({x, i});
	}

	for (int i = 0; i < SQ; i++) sort(all(v[i]));
	
	while (q--) {
		int c;
		cin >> c;
		if (c == 1) {
			ll l, r, x;
			cin >> l >> r >> x;
			l--, r--;
			Update(l, r, x);
		} else {
			ll x;
			cin >> x;
			pll e = Query(x);
			cout << e.Y - e.X << endl;
		}
	}
	return 0;
}