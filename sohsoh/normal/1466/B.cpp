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

int cnt[MAXN], n;

inline int solve() {
	for (int i = 0; i < 2 * n + 10; i++) cnt[i] = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		cnt[x]++;
	}

	for (int i = 2 * n + 5; i >= 0; i--) {
		if (cnt[i] > 1) cnt[i]--, cnt[i + 1]++;
		if (cnt[i] == 1 && cnt[i + 1] == 0) cnt[i]--, cnt[i + 1]++;
	}

	int ans = 0;
	for (int i = 2 * n + 6; i >= 0; i--) if (cnt[i]) ans++;
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