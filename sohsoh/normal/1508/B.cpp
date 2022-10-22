#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;
const ll INF = 1e18 + 10;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll F(ll n) {
	if (n > 61) return INF;
	if (n == 0) return 1;
	return (1ll << (n - 1));
}

inline int solve() {
	ll n, k;
	cin >> n >> k;
	if (F(n) < k) return cout << -1 << endl, 0;

	ll ind = 0, P = 0;
	vector<ll> ans;
	while (ind < n) {
		ll i = 1;
		while (F(n - ind - i) < k) k -= F(n - ind - i), i++;
		for (int j = i; j > 0; j--) ans.push_back(j + P);
		P += i;
		ind += i;
	}

	for (int e : ans) cout << e << sep;
	cout << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}