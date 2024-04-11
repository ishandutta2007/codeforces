#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
 
#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
 
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}
 
const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;
const ll LOG = 22;

ll mn[LOG][LOG], D[MAXN][LOG], A[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll n, q;
	cin >> n >> q;
	for (int i = 0; i < n; i++) cin >> A[i], fill(D[i], D[i] + LOG, INF);
	for (int i = 0; i < LOG; i++) for (int j = 0; j < LOG; j++) mn[i][j] = INF;
	for (int i = n - 1; i >= 0; i--) {
		ll x = A[i], j = 0;
		vector<ll> v;
		while (x > 0) {
			if (x & 1) {
				D[i][j] = i;
				for (ll u : v) mn[u][j] = mn[j][u] = i;
				v.push_back(j);
			}

			x /= 2;
			j++;
		}	
		
		for (int k = 0; k < LOG; k++) {
			if (D[i][k] == INF) {
				for (ll e : v) {
					D[i][k] = min(D[i][k], mn[e][k]);
				}	
			}
		}	

		for (ll e : v) {
			for (int k = 0; k < LOG; k++) {
				mn[e][k] = min(mn[e][k], D[i][k]); 
			}
		}
	}

	while (q--) {
		ll x, y;
		cin >> x >> y;
		x--; y--;
		ll t = A[y];
		ll j = 0;
		bool ok = false;
		while (t > 0) {
			if (t % 2 == 1 && D[x][j] <= y) ok = true;
			t /= 2;
			j++;
		}

		if (ok) cout << "Shi" << endl;
		else cout << "Fou" << endl;
	}
	return 0;
}