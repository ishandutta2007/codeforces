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

ll n, A[MAXN], B[MAXN], C[MAXN], D[MAXN];

ll solve() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> A[i];
	for (int i = 0; i < n; i++) cin >> B[i];
	for (int i = 0; i < n; i++) cin >> C[i];
	D[0] = A[0];
	for (int i = 0; i < n; i++) {
		D[i] = A[i];
		if (A[i] == D[i - 1]) D[i] = B[i];
	}

	if (A[n - 1] != D[n - 2] && A[n - 1] != D[0]) D[n - 1] = A[n - 1];
	if (B[n - 1] != D[n - 2] && B[n - 1] != D[0]) D[n - 1] = B[n - 1];
	if (C[n - 1] != D[n - 2] && C[n - 1] != D[0]) D[n - 1] = C[n - 1];

	for (int i = 0; i < n; i++) cout << D[i] << sep;
	cout << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll t;
	cin >> t;
	while (t--) solve();
	return 0;
}