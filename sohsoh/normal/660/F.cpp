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

namespace CHT {
	const ll INF = 8e18;
	vector<pair<ll, pll>> vec;
	inline ll isect(pll a, pll b) {
		if (a.X == b.X)
			return a.Y < b.Y ? -INF : INF;
		if (a.X > b.X) swap(a, b);
		return (a.Y - b.Y + (a.Y <= b.Y ? 0 : 1) * (b.X - a.X - 1)) / (b.X - a.X);
	}
 
	inline void add(ll m, ll a) {
		pll line = {m, a};
		while (!vec.empty()) {
			ll x = isect(vec.back().Y, line);
			if (x <= vec.back().X) vec.pop_back();
			else {
				vec.push_back({x, line});
				return;	
			}
		}
 
		vec.push_back({-INF, line});
	}
 
	inline ll query(ll x) {
		pll line = prev(upper_bound(all(vec), make_pair(x, make_pair(INF, INF)))) -> Y;
		return line.X * x + line.Y;
	}
}

int n;
ll ps[MAXN], f[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	CHT::add(0, 0);
	
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		ll x;
		cin >> x;
		ps[i] = ps[i - 1] + x;
		f[i] = f[i - 1] + i * x;

		ans = max(ans, f[i] + CHT::query(-ps[i]));
		CHT::add(i, i * ps[i] - f[i]);
	}

	cout << ans << endl;
	return 0;
}