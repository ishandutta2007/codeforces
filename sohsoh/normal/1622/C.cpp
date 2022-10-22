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
const ll INF = 8e18;

ll ps[MAXN], n, A[MAXN], k;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 1; i <= n; i++) cin >> A[i];
		sort(A + 1, A + n + 1);
		for (int i = 1; i <= n; i++) ps[i] = ps[i - 1] + A[i];

		ll ans = INF;
		for (int i = n + 1; i > 1; i--) {
			ll x = n + 2 - i, s = A[1] * x + ps[i - 1] - A[1];
			ans = min(ans, max(0ll, s - k + x - 1) / x + x - 1);
		}

		cout << ans << endl;
	}
	return 0;
}