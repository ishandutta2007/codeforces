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

ll A[MAXN], B[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll n, m;
	cin >> n >> m;
	ll ans = 0;
	for (int i = 0; i < n; i++) cin >> A[i], ans += A[i] * m;
	for (int i = 0; i < m; i++) cin >> B[i];
	if (*max_element(A, A + n) > *min_element(B, B + m)) return cout << -1 << endl, 0;
      	sort(B, B + m);
	sort(A, A + n);
	if (B[0] > A[n - 1]) ans += B[0] - A[n - 2];
	for (int i = 1; i < m; i++) {
		ans += B[i] - A[n - 1];
	}

	cout << ans << endl;
	return 0;
}