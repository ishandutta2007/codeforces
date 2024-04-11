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

int sg[MAXN], A[MAXN], O[MAXN];

int solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
		O[A[i]] = true;
		if (i > 0 && A[i] != A[i - 1]) sg[A[i - 1]]++;
	}

	sg[A[0]]--;
	
	ll ans = INF;
	for (int i = 0; i < n + 10; i++)
		if (O[i]) ans = min(ans, 1ll * sg[i] + 1);
	
	if (ans == INF) ans = 0;
	cout << ans << endl;

	for (int i = 0; i < n + 10; i++) sg[i] = 0, O[i] = false;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}