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

ll A[MAXN], ps[MAXN], n, B[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> A[i];
	ll ind = 0;
	for (int i = 0; i < n; i += 2) B[ind] = A[i], ind++;
	for (int i = 1; i < n; i += 2) B[ind] = A[i], ind++;
	for (int i = 0; i < n; i += 2) B[ind] = A[i], ind++;
	for (int i = 1; i < n; i += 2) B[ind] = A[i], ind++;
	ps[0] = 0;
	for (int i = 0; i < ind; i++) ps[i + 1] = ps[i] + B[i];
       	
	ll ans = 0;
	for (int i = (n + 1) / 2; i <= ind; i++) {
		ans = max(ans, ps[i] - ps[i - (n + 1) / 2]);
	}	

	cout << ans << endl;
	return 0;
}