/*
    Soheil Mohammadkhani
    final test contest on vim
*/
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<pll, ll> plll;
 
#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}
 
const ll MAXN = 75 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll dp[MAXN][MAXN];
plll rec[MAXN][MAXN];

bool cmp(plll x, plll y) {
	if (x.Y == y.Y) return x.X > y.X;
	return x.Y < y.Y; 
}

void upd(ll& a, plll& r, ll x, plll tr) {
	if (x > a) a = x, r = tr;
}

ll solve() {
	for (int i = 0; i < MAXN; i++) for (int j = 0; j < MAXN; j++) dp[i][j] = -1 * INF;
	dp[0][0] = 0;
	rec[0][0] = {{-1, -1}, 0};
	ll n, k;
	cin >> n >> k;
	vector<plll> v;
	v.push_back({{-1, -1}, -1});
	for (int i = 0; i < n; i++) {
		plll p;
		p.X.Y = i + 1;
		cin >> p.X.X >> p.Y;
		v.push_back(p);
	}

	sort(all(v), cmp);
	
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			upd(dp[i][j], rec[i][j], dp[i - 1][j] + v[i].Y * (k - 1), {{i - 1, j}, 0});
			if (j > 0) upd(dp[i][j], rec[i][j], dp[i - 1][j - 1] + v[i].X.X + (j - 1) * v[i].Y, {{i - 1, j - 1}, 1});
		}	
	}

	vector<ll> chs, nchs;
	ll x = n, y = k;
	while (x > 0) {
		if (rec[x][y].Y == 1) y--, chs.push_back(v[x].X.Y);
		else nchs.push_back(v[x].X.Y);
		x--;
	}
	
	cout << chs.size() + 2 * nchs.size() << endl;
	reverse(all(chs));
	for (int i = 0; i < chs.size() - 1; i++) cout << chs[i] << sep;
	for (ll e : nchs) cout << e << sep << -1 * e << sep;
	cout << chs.back() << endl;	
	return 0;
}

int main() {
	fast_io;
	ll t;
	cin >> t;
	while (t--) solve();
}