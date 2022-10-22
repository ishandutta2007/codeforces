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
 
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}
 
const ll MAXN = 3e5 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;
const ll LOG = 31;

ll n, A[MAXN], B[MAXN] = {0}, C[MAXN] = {0};
ll Z[MAXN] = {0}, O[MAXN] = {0};

void compress() {
	vector<pll> v;
	for (int i = 0; i < n; i++) v.push_back({A[i], i});
	sort(all(v));
	ll ind = 1;
	for (int i = 0; i < n; i++) A[v[i].Y] = ind++;
}

void compress2() {
	vector<pll> v;
	for (int i = 0; i < n; i++) v.push_back({C[i], i});
	sort(all(v));
	ll ind = 0;
	for (int i = 0; i < n; i++) {
		if (i == 0 || v[i].X != v[i - 1].X) ind++;
		B[v[i].Y] = ind;
	}
}

ll fen[MAXN] = {0};

void add(ll ind, ll val) {
	for (++ind; ind < MAXN; ind += ind & -ind) fen[ind] += val;
}

void range_add(ll l, ll r, ll val) {
	add(l, val);
	add(r + 1, -val);
}

ll point(ll x) {
	ll ans = 0;
	for (++x; x > 0; x -= x & -x) ans += fen[x];
	return ans;
}



int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> A[i];
	
	ll ans = 0;
	
	for (ll i = LOG; i >= 0; i--) {
		ll x = (1 << i);
		ll tot = 0;
		compress2();
		for (int j = 0; j < n; j++) {	
			if (A[j] & x) tot += Z[B[j]];
			else tot -= O[B[j]];

			if (A[j] & x) O[B[j]]++;
			else Z[B[j]]++;
		
			C[j] ^= (A[j] & x);
		}

		if (tot < 0) ans ^= x;
		memset(Z, 0, sizeof Z);
		memset(O, 0, sizeof O);
	}

	for (int i = 0; i < n; i++) A[i] ^= ans;
	compress();
	

	ll ans2 = 0;
	for (int i = 0; i < n; i++) {
		ans2 += point(A[i]);	
		range_add(0, A[i] - 1, 1);
	}

	cout << ans2 << sep << ans << endl;
	return 0;
}