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

ll A[6], n, B[MAXN];
vector<ll> S[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	for (int i = 0; i < 6; i++) cin >> A[i];
	cin >> n;
	vector<pll> v;
	
	ll ans = INF, mx = 0;
	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		for (int j = 0; j < 6; j++) S[i].push_back(x - A[j]), v.push_back({x - A[j], i});
		sort(all(S[i]));
		mx = max(mx, S[i].front());
	}
	
	sort(all(v));
	reverse(all(v));
	while (!v.empty()) {
		pll e = v.back();
		v.pop_back();
		ans = min(ans, mx - e.X);
		S[e.Y].erase(S[e.Y].begin());
		if (S[e.Y].empty()) break;
		mx = max(mx, S[e.Y].front());
	}

	cout << ans << endl;

	return 0;
}