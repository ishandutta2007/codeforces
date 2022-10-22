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
 
const ll MAXN = 2e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll cnt[2][MAXN] = {0}, A[MAXN], n;

map<ll, ll> suff;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	ll arr_xor = 0;
	for (int i = 0; i < n; i++) cin >> A[i], arr_xor ^= A[i];
	ll xx = 0, ind = 1;
	suff.insert({0, 0});
	cnt[0][0]++;
	for (int i = n - 1; i > 0; i--) {
		xx ^= A[i]; 
		if (ind & 1) cnt[1][xx]++;
		else cnt[0][xx]++;
		suff.insert({ind, xx});
		ind++;
	}

	xx = 0;
	ll ans = cnt[n % 2][arr_xor];
	for (int i = 0; i < n - 1; i++) {
		cnt[(suff.rbegin() -> X) % 2][suff.rbegin() -> Y]--;
		suff.erase(suff.rbegin() -> X);
		xx ^= A[i];
		ans += cnt[(n - i - 1) % 2][xx ^ arr_xor];
	}

	cout << ans << endl;
	return 0;
}