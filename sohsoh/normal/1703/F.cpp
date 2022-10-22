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

int fen[MAXN], n;

inline void update(int ind, int val) {
	for (++ind; ind < n + 5; ind += ind & -ind)
		fen[ind] += val;
}

inline int query(int ind) {
	int ans = 0;
	for (++ind; ind > 0; ind -= ind & -ind)
		ans += fen[ind];
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		fill(fen, fen + n + 10, 0);
		cin >> n;

		ll ans = 0;
		for (int i = 1; i <= n; i++) {
			int x;
			cin >> x;
			if (x >= i) continue;
		
			ans += query(x - 1);
			update(i, 1);
		}

		cout << ans << endl;
	}
	return 0;
}