#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef long double ld;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353;

inline int solve() {
	int n;
	cin >> n;
	vector<ll> M, D;
	for (int i = 1; i <= 2 * n; i++) {
		ll x, y;
		cin >> x >> y;
		if (x == 0) D.push_back(y * y);
		else M.push_back(x * x);
	}

	sort(all(D));
	sort(all(M));
	ld ans = 0;
	for (int i = 0; i < n; i++) {
		ans += sqrt(D[i] + M[i]);
	}
	
	cout << setprecision(10) << fixed;
	cout << ans << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}