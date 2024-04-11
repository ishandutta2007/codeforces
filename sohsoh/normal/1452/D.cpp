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
const ll MOD = 998244353; // 1e9 + 9;

ll dp[MAXN], ch[MAXN], fib[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	fib[1] = fib[2] = 1;
	for (int i = 3; i < MAXN; i++) fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
	int n;
	cin >> n;
	ll ans = fib[n];
	ll inv2 = poww(2, MOD - 2, MOD);
	for (int i = 0; i < n; i++) ans = ans * inv2 % MOD;
	cout << ans << endl;
	return 0;
}