// \_()_/
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

int t, A[MAXN], n;

inline int solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];

	for (int i = 1; i <= n; i++) {
		bool flag = true;
		for (int j = i; j > 0; j--) {
			if (A[i] % (j + 1)) {
				flag = false;
				break;
			}
		}

		if (flag) return cout << "NO" << endl, 0;
	}

	cout << "YES" << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> t;
	while (t--) solve();
	return 0;
}