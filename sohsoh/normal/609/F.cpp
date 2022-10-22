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
const ll INF = 1e18;

int n, m;
vector<pair<pll, ll>> vec;
pll sg[MAXN], ans[MAXN];
multiset<pll> st;

inline pll operator+ (const pll& a, const pll& b) {
	return {a.X + b.X, a.Y + b.Y};
}

pll update(int ind, int x, pll val, int l = 1, int r = n, int v = 1) {
	if (l > ind || sg[v].X < x) return {INF, INF};
	if (l == r) {
		sg[v] = sg[v] + val;
		return {vec[l].X.X, sg[v].X};
	} else {
		int mid = (l + r) >> 1;
		pll ans = {INF, INF};
		if (sg[v << 1].X >= x) ans = update(ind, x, val, l, mid, v << 1);
		else ans = update(ind, x, val, mid + 1, r, v << 1 | 1);
		
		sg[v] = max(sg[v << 1], sg[v << 1 | 1]);
		return ans;
	}
}

void build(int l = 1, int r = n, int v = 1) {
	if (l == r) sg[v] = {vec[l].X.X + vec[l].X.Y, 0};
	else {
		int mid = (l + r) >> 1;
		build(l, mid, v << 1);
		build(mid + 1, r, v << 1 | 1);
		sg[v] = max(sg[v << 1], sg[v << 1 | 1]);
	}
}

void solve(int l = 1, int r = n, int v = 1) {
	if (l == r) ans[vec[l].Y] = sg[v] + make_pair(-vec[l].X.X, 0);
	else {
		int mid = (l + r) >> 1;
		solve(l, mid, v << 1);
		solve(mid + 1, r, v << 1 | 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		ll x, t;
		cin >> x >> t;
		vec.push_back({{x, t}, i});
	}

	vec.push_back({{-1, -1}, 1});
	sort(all(vec));

	build();
	while (m--) {
		ll x, val;
		cin >> x >> val;
	//	cerr << "! " << x << sep << val << endl;

		int ind = upper_bound(all(vec), make_pair(make_pair(x, INF), INF)) - vec.begin() - 1;	
		if (ind < 1) continue;

		pll e = update(ind, x, {val, 1});
		
		if (e.X < INF) {
			while (true) {
				//cerr << "wtf: " <<  e.X << sep << e.Y << endl;
				auto it = st.lower_bound(make_pair(e.X, -1));
				if (it == st.end() || it -> X > e.Y) break;
				x = it -> X, val = it -> Y;
		
				ind = upper_bound(all(vec), make_pair(make_pair(x, INF), INF)) - vec.begin() - 1;	
				e = update(ind, x, {val, 1});	
				st.erase(it);
			}
		} else st.insert({x, val});
	}

	solve();
	for (int i = 1; i <= n; i++)
		cout << ans[i].Y << sep << ans[i].X << endl;
	return 0;
}