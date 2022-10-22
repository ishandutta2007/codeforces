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
 
const ll MAXN = 3e3 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll A[MAXN], n;

void compress_arr() {
	vector<pll> v;
	for (int i = 0; i < n; i++) v.push_back({A[i], i});
	sort(all(v));
	ll ind = 0;
	for (int i = 0; i < n; i++) {
		if (i == 0 || v[i].X > v[i - 1].X) ind++;
		A[v[i].Y] = ind;
	}
}

ll val[MAXN] = {0}, dp[MAXN] = {0};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> A[i];
		compress_arr();
		for (int i = 0; i < n; i++) {
			dp[i] = val[A[i]] + 1;
			val[A[i]] = max(val[A[i]], dp[i]);
			val[A[i] + 1] = max(val[A[i] + 1], dp[i]);
		}
	
		cout << n - *max_element(dp, dp + MAXN) << endl;
		fill(dp, dp + MAXN, 0);
		fill(val, val + MAXN, 0);
	}
	return 0;
}