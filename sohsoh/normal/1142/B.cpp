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
const ll INF2 = 8e18;
const ll INF = 2e18; // :/
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;
const ll LOG = 22;

ll mn_r[MAXN], nxt[MAXN], P[MAXN], A[MAXN], n, m, qr;
set<ll> ind[MAXN];

ll table[MAXN][LOG];

ll walk(ll i, ll k) {
	ll j = 0;
	ll ans = i;
	while (k > 0) {
		if (k & 1) ans = table[ans][j];
	       	k /= 2;
		j++;	
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	fill(mn_r, mn_r + MAXN, INF2);
	cin >> n >> m >> qr;
	if (n == 1) {
		while (qr--) cout << 1;
		cout << endl;
		return 0;
	}

	for (int i = 0; i < n; i++) cin >> P[i];
	nxt[P[n - 1]] = P[0];
	for (int i = 1; i < n; i++) nxt[P[i - 1]] = P[i];
	
	for (int i = 0; i < m; i++) cin >> A[i], ind[A[i]].insert(i);
	for (int i = 0; i < m; i++) {
		auto it = ind[nxt[A[i]]].upper_bound(i);
		if (it == ind[nxt[A[i]]].end()) table[i][0] = m;
		else table[i][0] = *it;
	}
	
	fill(table[m], table[m] + LOG, m);
	for (int i = m - 1; i >= 0; i--) {
		ll j = 1;
		while (j < LOG) table[i][j] = table[table[i][j - 1]][j - 1], j++;
	}

	mn_r[m - 1] = m;
	for (int i = m - 2; i >= 0; i--)
		mn_r[i] = min(mn_r[i + 1], walk(i, n - 1));
	while (qr--) {
		ll l, r;
		cin >> l >> r;
		l--;
		r--;
		if (mn_r[l] <= r) cout << 1;
		else cout << 0;
	}

	cout << endl;
	return 0;	
}