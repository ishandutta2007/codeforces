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

const ll MAXN = 2000 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9


ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

ll n, k, dp[MAXN][MAXN] = {0};
vector<ll> div1[MAXN];

int main() {
	for (int i = 1; i < MAXN; i++) {
		for (int j = 1 ; j * i < MAXN; j++) {
			div1[i * j].push_back(i);
		}
	}

	cin >> n >> k;
	fill(dp[1], dp[1] + MAXN, 1);
	for (int i = 2; i <= k; i++) {
		for (int j = 1; j < MAXN; j++) {
			for (ll e : div1[j]) dp[i][j] = (dp[i][j] + dp[i - 1][e]) % MOD;
		} 
	}


	ll ans = 0;
	for (int i = 1; i <= n; i++) ans = (ans + dp[k][i]) % MOD;
	cout << ans << endl;
}