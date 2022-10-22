#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
 
#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;
 
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}
 
const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

vector<pll> v;
ll n;

void dojob() {
	vector<pll> ans;
	ans.push_back(v[0]);
	for (int i = 1; i < v.size(); i++) {
		if (ans.back().Y == v[i].X - 1) {
			pll p = {ans.back().X, v[i].Y};
			ans.pop_back();
			ans.push_back(p);
		} else {
			ans.push_back(v[i]);
		}
	}

	v = ans;
}

void dojob2(ll a, ll b, ll c, ll d) {
	vector<vector<pll>> tv;
	tv.resize(4);
	for (int i = 0; i < a; i++) tv[0].push_back(v[i]);
	for (int i = 0; i < b; i++) tv[1].push_back(v[a + i]);
	for (int i = 0; i < c; i++) tv[2].push_back(v[a + b + i]);
	for (int i = 0; i < d; i++) tv[3].push_back(v[a + b + c + i]);
	reverse(all(tv));
	v.clear();
	for (vector<pll> vv : tv) {
		for (pll u : vv) v.push_back(u);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		v.push_back({x, x});
	}

	dojob();
	vector<vector<ll>> ans;
	while (v.size() > 1) {
		pll s_req;
		for (int i = 0; i < v.size(); i++) {
			for (int j = i + 1; j < v.size(); j++) {
				if (v[i].X == v[j].Y + 1) s_req = {i, j};
			}
		}

		ans.push_back({});
		ll p0 = 0, p1 = v[s_req.X].Y - v[s_req.X].X + 1, p2 = 0, p3 = 0, x1 = 0, x2 = 1, x3 = 0, x4 = 0;
		bool b1 = true, b2 = true;
		for (int i = 0; i < v.size(); i++) {
			if (i == s_req.X) {
				b1 = false;
				b2 = true;
				continue;
			}

			if (b1) {
				p0 += v[i].Y - v[i].X + 1;
				x1++;
			} else if (b2) {
				p2 += v[i].Y - v[i].X + 1;
				x3++;
			} else {
				p3 += v[i].Y - v[i].X + 1;
				x4++;
			}

			if (i == s_req.Y) {
				b1 = false;
				b2 = false;				
			}
		}

		if (p0) ans[ans.size() - 1].push_back(p0);
		if (p1) ans[ans.size() - 1].push_back(p1);
		if (p2) ans[ans.size() - 1].push_back(p2);
		if (p3) ans[ans.size() - 1].push_back(p3);
		dojob2(x1, x2, x3, x4);
		dojob();	

	}

	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i].size() << sep;
		for (ll u : ans[i]) cout << u << sep;
		cout << endl;
	}
	return 0;
}