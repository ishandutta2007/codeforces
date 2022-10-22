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

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;
const ll LOG = 22;

ll par[MAXN][LOG], ps[MAXN][LOG], q, W[MAXN];
ll last = 0, cnt = 1;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> q;
	while (q--) {
		ll c, p, q;
		cin >> c >> p >> q;
		if (c == 1) {
			ll u = p ^ last, w = q ^ last, v = ++cnt;	
			W[v] = w;
			for (par[v][0] = u; par[v][0] && W[par[v][0]] < W[v]; par[v][0] = par[par[v][0]][0]);
			ps[v][0] = W[par[v][0]];
			for (int i = 1; i < LOG; i++) {
				par[v][i] = par[par[v][i - 1]][i - 1];
				ps[v][i] = ps[v][i - 1] + ps[par[v][i - 1]][i - 1];
			}
		} else {
			ll v = p ^ last, x = q ^ last, val = W[v], ans = 1;
			if (W[v] > x) {
				cout << 0 << endl;
				last = 0;
				continue;
			}	

			for (int i = LOG - 1; i >= 0; i--) {
				if (val + ps[v][i] <= x && par[v][i] != 0) {
					ans += (1 << i);
					val += ps[v][i];
					v = par[v][i];
				}
			}

			cout << ans << endl;
			last = ans;
		}
	}

	return 0;
}