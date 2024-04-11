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

ll tree[MAXN] = {0}, A[MAXN], n;

void add(ll ind, ll val) {
	for (ind++; ind < MAXN; ind += ind & -ind) tree[ind] += val;
}

void range_update(ll l, ll r, ll val) {
	add(l, val);
	add(r + 1, -val);
}

ll point(ll ind) {
	ll ans = 0;
	for (ind++; ind > 0; ind -= ind & -ind) ans += tree[ind];
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	
	ll inv = 0;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
		inv += point(A[i]);
		range_update(1, A[i], 1);
	}

	if (inv % 2 == n % 2) return cout << "Petr" << endl, 0;
	cout << "Um_nik" << endl;
	return 0;
}