/*
    Soheil Mohammadkhani
    IDK :)
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 2e5 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9


ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}
 
ll dp[MAXN], A[MAXN];

int main() {
	ll n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> A[i];
	ll s = 0;
	for (int i = 0; i < k; i++) s += A[i];
	dp[0] = s;
	for (int i = 1; i < n - k + 1; i++) {
		s -= A[i - 1];
		s += A[i + k - 1];
		dp[i] = s;
	}

	ll mx_ind = n - k;
	ll ans = 0, a = 0, b = 0;
	for (int i = n - 2 * k; i >= 0; i--) {
		if (dp[i + k] >= dp[mx_ind]) mx_ind = i + k;
		//debug(i)
		//debug(mx_ind)
		if (dp[i] + dp[mx_ind] >= ans) {
			a = i;
			b = mx_ind;
			ans = dp[i] + dp[mx_ind];
		}
	}

	cout << a + 1 << sep << b + 1 << endl;
}