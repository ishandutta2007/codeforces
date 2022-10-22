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
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
 
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}
 
const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

map<ll, vector<ll>> mp;
map<ll, ll> pnt;
vector<ll> y_ax;
ll ans = 0, n;

ll tree[MAXN] = {0};
void update(ll ind, ll diff) {
	ind++;
	while (ind < MAXN) tree[ind] += diff, ind += ind & (-ind);
}

ll sum(ll ind) {
	ll ans = 0;
	ind++;
	while (ind > 0) {
		ans += tree[ind];
		ind -= ind & (-ind);
	}

	return ans;
}

void add_pnt(ll ind) {
	if (sum(ind) - sum(ind - 1) == 0) update(ind, 1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	vector<pll> compress;
	for (int i = 0; i < n; i++) {
		pll e;
		cin >> e.X >> e.Y;
		compress.push_back({e.X, e.Y});
	}

	sort(all(compress));
	
	ll ind = 1;
	for (int i = 0; i < n; i++) {
		if (pnt.find(compress[i].X) != pnt.end()) compress[i].X = pnt[compress[i].X];
	       	else pnt.insert({compress[i].X, ind}), compress[i].X = ind, ind++;	
	}
		
	for (int i = 0; i < n; i++) {
		pll p = compress[i];
		if (mp.find(p.Y) == mp.end()) mp.insert({p.Y, {}}), y_ax.push_back(p.Y);
		mp[p.Y].push_back(p.X);
	}

	sort(all(y_ax));
	reverse(all(y_ax));
	for (ll y : y_ax) {
		for (ll e : mp[y])
			add_pnt(e);
		mp[y].push_back(0);
		sort(all(mp[y]));
		for (int i = 1; i < mp[y].size(); i++) {
			ll beg = sum(mp[y][i]) - sum(mp[y][i - 1]);
			ll e = sum(MAXN - 10) - sum(mp[y][i]) + 1;
			ans += e * beg;
		}
	}

	cout << ans << endl;
	return 0;
}