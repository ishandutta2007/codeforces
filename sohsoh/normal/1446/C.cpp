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

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;
const ll LOG = 35;

ll n, A[MAXN];

ll solve(ll L, ll R, ll bt) {
	if (R <= L || bt < 0) return 0;
	ll x = (1ll << bt);
	if (A[L] & x) return solve(L, R, bt - 1);
	if (A[R - 1] & x) {
		ll Lt = L, Rt = R - 1;
		while (Lt < Rt) {
			ll mid = (Lt + Rt) / 2;
			if (A[mid] & x) Rt = mid;
			else Lt = mid + 1;
		}
	
		ll sz1 = Lt - L, sz2 = R - Lt;
		return min(sz2 - 1 + solve(L, Lt, bt - 1), sz1 - 1 + solve(Lt, R, bt - 1));
	} else return solve(L, R, bt - 1);
	
	return solve(L, R, bt - 1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> A[i];
	sort(A, A + n);
	cout << solve(0, n, LOG) << endl;
	return 0;
}