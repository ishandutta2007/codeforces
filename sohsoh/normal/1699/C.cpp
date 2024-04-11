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
const ll MOD = 1e9 + 7;

int A[MAXN], pos[MAXN], n;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> A[i], pos[A[i]] = i;

		int l, r;
		l = r = pos[0];
		ll ans = 1;
		for (int i = 1; i < n; i++) {
			int ind = pos[i];
			if (ind > r || ind < l) {
				l = min(l, ind);
				r = max(r, ind);
			} else ans = ans * (r - l + 1 - i) % MOD;
		}

		cout << ans << endl;
	}
	return 0;
}