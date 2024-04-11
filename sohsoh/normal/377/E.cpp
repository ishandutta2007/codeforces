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
const ll INF = 8e18;

ll n, s, ans[MAXN];
vector<pll> tvec, vec;

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
		if (x > 0 && INF / x < line.X) return INF;
		return line.X * x + line.Y; // overflow
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> s;
	while (n--) {
		ll v, c;
		cin >> v >> c;
		if (c >= s) continue;
		tvec.push_back({c, v});
	}

	tvec.push_back({s, int(1e8) + 1});
	sort(all(tvec), [] (pll a, pll b) {
		if (a.X == b.X) return a.Y > b.Y;
		return a < b;
	});

	ll mx_v = 0;
	for (pll e : tvec) {
		if (e.Y > mx_v) {
			mx_v = e.Y;
			vec.push_back(e);
		}
	}
	
	CHT::add(vec.front().Y, 0);
	ans[0] = 0;
	for (int i = 1; i < int(vec.size()); i++) {
		ll c = vec[i].X, v = vec[i].Y;
		ll l = 0, r = c;
		
		while (l < r) {
			ll mid = (l + r) >> 1;
			if (CHT::query(mid) >= c) r = mid;
			else l = mid + 1;
		}

		ans[i] = l;
		ll rem = CHT::query(l) - c;
		CHT::add(v, rem - l * v);
	}

	cout << ans[int(vec.size()) - 1] << endl;
	return 0;
}