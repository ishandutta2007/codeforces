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

int A[MAXN], B[MAXN], n;

inline void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> B[i] >> A[i];

	int l = 1, r = n;
	while (l < r) {
		int mid = (l + r + 1) >> 1, mx = 0;
		for (int i = 1; i <= n; i++) {
			if (mx > A[i] || mid - mx - 1 > B[i]) continue;
			mx++;
		}

		if (mx < mid) r = mid - 1;
		else l = mid;
	}

	cout << l << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}