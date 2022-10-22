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

inline int solve() {
	ll n, k;
	cin >> n >> k;
	if (n == 4 && k == 3) return cout << -1 << endl, 0;
	if (k == n - 1) {
		cout << n - 1 << sep << n - 2 << endl;
		cout << 1 << sep << 3 << endl;
		cout << 0 << sep << n - 3 << endl;
		cout << 2 << sep << n - 4 << endl;
		for (int i = 4; i < n / 2; i++)
			cout << i << sep << n - 1 - i << endl;
		return 0;
	}

	cout << k << sep << n - 1 << endl;
	if (k != 0) cout << 0 << sep << n - 1 - k << endl;
	for (int i = 1; i < n / 2; i++) {
		if (i != k && (n - 1 - i) != k)
			cout << i << sep << n - 1 - i << endl;
	}

	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}