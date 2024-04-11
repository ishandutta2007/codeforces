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

int n, k, A[MAXN];

int solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> A[i];

	int ans = n;
	for (int c = 1; c <= 100; c++) {
		int tans = 0, lst = 0;
		for (int i = 1; i <= n; i++) { //
			if (A[i] == c || i <= lst) continue;
			tans++;
			lst = i + k - 1;
		}
			
		ans = min(ans, tans);
	}

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