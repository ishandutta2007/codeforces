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

vector<pll> Q[MAXN], ans;
ll fen[MAXN] = {0}, A[MAXN];

void add(ll ind, ll val) {
	for (++ind; ind < MAXN; ind += ind & -ind) fen[ind] += val;
}

void update(ll l, ll r, ll val) {
	add(l, val);
	add(r + 1, -val);
}

ll point(ll ind) {
	ll ans = 0;
	for (++ind; ind > 0; ind -= ind & -ind) ans += fen[ind];
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> A[i], A[i] = i - A[i];
       	for (int i = 0; i < q; i++) {
		ll l, r;
		cin >> l >> r;	
		l++;
		r = n - r;
		Q[r].push_back({i, l});
	}	

	for (int r = 1; r <= n; r++) {
		ll L = 0, R = r;
		while (L < R) {
			ll mid = (L + R + 1) / 2;
			if (A[r] < 0 || point(mid) < A[r]) R = mid - 1;
		       	else L = mid;	
		}
		
		update(0, L, 1);	
		for (pll e : Q[r]) ans.push_back({e.X, point(e.Y)});
	}

	sort(all(ans));
	for (pll e : ans) cout << e.Y << endl;
	return 0;
}