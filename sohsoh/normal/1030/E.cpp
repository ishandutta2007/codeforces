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

int A[MAXN], n;
int dp[MAXN] = {0};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		ll x;
		cin >> x;
		A[i] = __builtin_popcountll(x);
	}

	ll false_red = 0;
	for (int i = 1; i <= n; i++) {
		int s = 0, mx = 0;
		for (int j = 0; j <= 64 && i + j <= n; j++) {
			s += A[i + j];
			mx = max(A[i + j], mx);
			if (s % 2 == 0 && mx > s / 2) false_red++;
		}
	}

	ll ans = 0;
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		if (A[i] % 2 == 0) dp[i] = dp[i - 1] + 1;
		else dp[i] = i - dp[i - 1] + 1;
		ans += dp[i] - 1;
	}

	cout << ans - false_red << endl;
	return 0;
}