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

ll A[MAXN], n, x;

inline ll f(ll a, ll b) {
	return max(a, b) - min(a, b);
}

inline int solve() {
	ll ans = 0, delta1 = INF, delta2 = INF, delta3 = INF;
	cin >> n >> x;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		if (i > 1) {
			ans += f(A[i], A[i - 1]);
			delta1 = min(delta1, f(1, A[i]) + f(1, A[i - 1]) - f(A[i], A[i - 1]));
			delta2 = min(delta2, f(x, A[i]) + f(x, A[i - 1]) - f(A[i], A[i - 1]));
			delta3 = min(delta3, f(A[i - 1], 1) + f(1, x) + f(x, A[i]) - f(A[i], A[i - 1]));
			delta3 = min(delta3, f(A[i - 1], x) + f(x, 1) + f(1, A[i]) - f(A[i], A[i - 1]));
		}
	}

	delta1 = min(delta1, f(1, A[1]));
	delta2 = min(delta2, f(x, A[1]));
	delta1 = min(delta1, f(1, A[n]));
	delta2 = min(delta2, f(x, A[n]));
	delta3 = min(delta3, f(1, x) + f(x, A[1]));
	delta3 = min(delta3, f(x, 1) + f(1, A[1]));
	delta3 = min(delta3, f(A[n], x) + f(x, 1));
	delta3 = min(delta3, f(A[n], 1) + f(1, x));
	delta3 = min(delta3, delta2 + delta1);

	cout << ans + delta3 << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}