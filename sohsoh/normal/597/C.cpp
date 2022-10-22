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

const ll MAXN = 1e5 + 10;

struct Fenwick {
	ll fen[MAXN];

	inline void Add(int ind, ll val) {
		for (++ind; ind < MAXN; ind += ind & -ind)
			fen[ind] += val;
	}

	inline ll Query(int ind) {
		ll ans = 0;
		for (++ind; ind > 0; ind -= ind & -ind)
			ans += fen[ind];
		return ans;
	}
};

int n, k;
ll ans;
Fenwick fen[12];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	fen[0].Add(0, 1);
	
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		for (int t = 1; t <= k + 1; t++) {
			ll c = fen[t - 1].Query(x - 1);
			fen[t].Add(x, c);
			
			if (t == k + 1) ans += c;
		}
	}

	cout << ans << endl;
	return 0;
}