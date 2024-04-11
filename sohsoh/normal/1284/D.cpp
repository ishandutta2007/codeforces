#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<pll, pll> plll;
 
#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;
 
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}
 
const ll MAXN = 4e5 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll Lazy[4 * MAXN], Max[4 * MAXN] = {0};

void lazy_update(int u, int l, int rr) {
	if (Lazy[u] == -1) return; 
	if (l != rr) Lazy[u * 2] = Lazy[u * 2 + 1] = Lazy[u];
	Max[u] = min(Max[u], Lazy[u]); 
	Lazy[u] = -1;
}

void assign_range(int u, int l, int rr, int L, int R, int X) {
	lazy_update(u, l, rr);
	if (l > R || L > rr) return;
	if (L <= l && rr <= R) { 
		Lazy[u] = X; 
		lazy_update(u, l, rr); 
		return; 
	}

	assign_range(2 * u, l, (l + rr) / 2, L, R, X);
	assign_range(2 * u + 1, (l+rr) / 2 + 1, rr, L, R, X);
	Max[u] = min(Max[2 * u], Max[2 * u + 1]);
}

int max_range(int u, int l, int rr, int L, int R) {
	lazy_update(u, l, rr);
	if (l > R || L > rr) return 1e9;
	if (L <= l && rr <= R) return Max[u];
	
	int Max1 = max_range(2 * u, l, (l + rr) / 2, L, R);
	int Max2 = max_range(2 * u + 1, (l + rr) / 2 + 1, rr, L, R);
	return min(Max1, Max2);
}


vector<plll> v;
ll n;

bool cmp(plll x, plll y) {
	return x.X.Y < y.X.Y;
}



void solve() {
	fill(Lazy, Lazy + 4 * MAXN, -1);
	fill(Max, Max + 4 * MAXN, INF);
	sort(all(v), cmp);
	for (int i = 0; i < n; i++) {		
		ll L = -1, R = i - 1;
		while (L < R) {
			ll mid = (L + R + 1) / 2;
			if (v[mid].X.Y < v[i].X.X) L = mid;
			else R = mid - 1;
		}

		if (i > 0 && max_range(1, 1, MAXN, v[i].Y.X, v[i].Y.Y) <= L + 1) {
			cout << "NO" << endl;
			exit(0);
		}

		assign_range(1, 1, MAXN, v[i].Y.X, v[i].Y.Y, i + 1);
	}
}

vector<ll> points;
map<ll, ll> mp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++) cin >> v[i].X.X >> v[i].X.Y >> v[i].Y.X >> v[i].Y.Y, points.push_back(v[i].X.X), points.push_back(v[i].X.Y), points.push_back(v[i].Y.X), points.push_back(v[i].Y.Y);
	sort(all(points));
	ll ind = 1;
	for (ll e : points) if (mp.find(e) == mp.end()) mp.insert({e, ind++});
	for (int i = 0; i < n; i++) {
		v[i].X.X = mp[v[i].X.X];
		v[i].X.Y = mp[v[i].X.Y];
		v[i].Y.X = mp[v[i].Y.X];
		v[i].Y.Y = mp[v[i].Y.Y];
	}
	
	solve();
	for (int i = 0; i < n; i++) swap(v[i].X, v[i].Y);
	solve();
	cout << "YES" << endl;	
	return 0;
}