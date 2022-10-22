/*
    Soheil Mohammadkhani
    final test contest on vim
*/
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
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e5 + 10;
const ll MAXK = 900;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll dp_r[MAXN] = {0}, dp_l[MAXN] = {0}, n, A[MAXN], B[MAXN];

int main() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) cin >> A[i];
	for (int i = 0; i < n - 1; i++) {
		B[i] = A[i];
		if (B[i] % 2 == 0) B[i]--;
	}
	for (int i = 1; i < n; i++) {
		if (A[i - 1] < 2) continue;
		dp_l[i] = dp_l[i - 1] + A[i - 1];
		dp_l[i] -= A[i - 1] % 2;
	}

	for (int i = n - 2; i >= 0; i--) {
		if (A[i] < 2) continue;
		dp_r[i] = dp_r[i + 1] + A[i];
		dp_r[i] -= A[i] % 2;
	}
	
	ll sc = 0;
	set<pll> st;
	for (int i = 0; i < n; i++) st.insert({dp_r[i] + sc, i}), sc += B[i];
	
	ll ans = 0, red = 0;
	//alog(dp_l, n - 1);
	//alog(dp_r, n - 1);
	for (int i = 0; i < n; i++) {
		ll mx = st.rbegin() -> X;
		mx -= red;
		ans = max(ans, mx + dp_l[i]);	
		st.erase({dp_r[i] + red, i});
		red += B[i];
	}

	cout << ans << endl;
}