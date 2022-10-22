// Sohsoh84 :)))
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define int			    ll

const ll MAXN = 3e5 + 10;

int fen[2][MAXN], n;
ll s = 0, ans = 0;

inline void Add(int i, int ind, int val) {
	for (++ind; ind < MAXN; ind += ind & -ind)
		fen[i][ind] += val;
}

inline int Query(int i, int ind) {
	int ans = 0;
	for (++ind; ind > 0; ind -= ind & -ind)
		ans += fen[i][ind];
	return ans;
}

inline int Query(int i, int L, int R) {
	int ans = Query(i, R);
	if (L) ans -= Query(i, L - 1);
	return ans;
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		ans += x * (i - 1);
		ans -= Query(1, x);

		ans += s;
		for (int L = x; L < MAXN; L += x) {
			int R = min(1ll * L + x - 1, MAXN - 5);
			ll cnt = Query(0, L, R);
			ans -= cnt * L;
			Add(1, L, x);
		}

		s += x;
		Add(0, x, 1);

		cout << ans << sep;
	}
	return 0;
}