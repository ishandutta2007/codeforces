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

pll A[MAXN];
ll suff[MAXN] = {0};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	vector<pll> u;
	ll n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> A[i].X >> A[i].Y;
	for (int i = 0; i < m; i++) {
		ll x, y;
		cin >> x >> y;
		for (int j = 0; j < n; j++) u.push_back({x - A[j].X, y - A[j].Y});
	}

	for (pll v : u) if (v.X >= 0) suff[v.X] = max(suff[v.X], v.Y + 1);
	for (int i = MAXN - 2; i >= 0; i--) suff[i] = max(suff[i], suff[i + 1]);
	ll ans = INF;
	for (int i = 0; i < MAXN; i++) ans = min(ans, i + suff[i]);
	cout << ans << endl;
	return 0;
}