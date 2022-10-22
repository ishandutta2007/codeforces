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

int n, q, A[MAXN];

inline bool check(int x, bool f) {
	int c = q;
	for (int i = 1; i <= n; i++) {
		if (A[i] <= c) {
			if (f) cout << 1;
			x--;
		} else if (n - i < x) {
			if (f) cout << 1;
			x--;
			c--;
		} else {
			if (f) cout << 0;
		}
	}

	if (f) cout << endl;
	return c >= 0;
}

inline void solve() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> A[i];

	int l = 0, r = n;
	while (l < r) {
		int mid = (l + r + 1) >> 1;
		if (check(mid, false)) l = mid;
		else r = mid - 1;
	}

	check(l, true);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}