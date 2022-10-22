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

ll ps[MAXN], ss[MAXN], A[MAXN], n;

inline int solve() {	
	for (int i = 0; i < n + 10; i++)
		ps[i] = ss[i] = 0;
	
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	for (int i = 1; i <= n; i++) {
		ps[i] = ps[i - 1];
		if (i & 1) continue;
		ps[i] += max(0ll, max(A[i - 1], A[i + 1]) - A[i] + 1);
	}

	for (int i = n; i > 0; i--) {
		ss[i] = ss[i + 1];
		if (i & 1) {
			ss[i] += max(0ll, max(A[i - 1], A[i + 1]) - A[i] + 1);
		}
	}

	if (n & 1) return cout << ps[n] << endl, 0;
	ll ans = min(ps[n - 1], ss[2]);
	
	for (int i = 2; i < n - 2; i += 2)
		ans = min(ans, ps[i] + ss[i + 3]);

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