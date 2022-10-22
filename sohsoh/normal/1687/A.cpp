#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;

ll ps[MAXN], A[MAXN];

inline int solve() {
	ll ans = 0, n, k;
	cin >> n >> k;
	ans = k * (k - 1) / 2;
	if (k > n) {
		ans = (k - (n - 1));
		ans += n * (n - 1) / 2;
		ans += (k - (n - 1)) * (n - 1) - n; 
	}

	ll tans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		ps[i] = ps[i - 1] + A[i];
		tans = max(tans, ps[i] - ps[max(0ll, i - k)]);
	}

	cout << ans + tans << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}