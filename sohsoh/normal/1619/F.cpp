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

inline void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	
	int sz = n / m;
	int t2 = n - sz * m, t1 = m - t2;

	ll s = 0;
	while (k--) {	
		for (int i = 0; i < t1 * sz; i++) {
			if (i % sz == 0) cout << sz << sep;
			cout << (i + s) % n + 1 << sep;
			if (i % sz == sz - 1) cout << endl;
		}

		for (int i = t1 * sz; i < n; i++) {
			if ((i - t1 * sz) % (sz + 1) == 0) cout << sz + 1 << sep;
			cout << (i + s) % n + 1 << sep;
			if ((i - t1 * sz) % (sz + 1) == sz) cout << endl;
		}

		s += t1 * sz;
	}

	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}