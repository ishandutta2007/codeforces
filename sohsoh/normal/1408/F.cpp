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

vector<pll> ans;
void mmerge(ll l, ll r) {
	if (l == r) return;
	ll mid = (l + r) / 2;
	mmerge(l, mid);
	mmerge(mid + 1, r);
	for (int i = 0; i <= mid - l; i++) ans.push_back({l + i, mid + 1 + i});
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	ll x = 1;
	while (x * 2 <= n) x *= 2;
	mmerge(1, x);
	mmerge(n - x + 1, n);
	cout << ans.size() << endl;
	for (pll e : ans) cout << e.X << sep << e.Y << endl;
	return 0;
}