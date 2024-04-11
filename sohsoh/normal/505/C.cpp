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

const ll MAXN = 30000 + 100;
const ll MAXK = 300 + 20;
const ll cst = 300 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll cnt[MAXN] = {0}, dp[MAXN][2 * MAXK];


int main() {
	fast_io;
	ll n, d;
	cin >> n >> d;
	for (int i = 1; i <= n; i++) {
		ll x;
		cin >> x;
		cnt[x]++;
	}

	for (int i = 0; i < MAXN; i++) fill(dp[i], dp[i] + 2 * MAXK, -1 * INF);
	dp[d][cst] = cnt[d];
	//fill(dp[0], dp[0] + 2 * MAXK, 0);
	for (int i = d + 1; i < MAXN; i++) {
		for (int j = -1 * cst; j < cst; j++) {
			ll jmp = d + j;
			if (jmp <= 0 || i - jmp < 0) continue;
			dp[i][j + cst] = max(dp[i][j + cst], dp[i - jmp][j + cst] + cnt[i]);	
			if (j - 1 + cst >= 0) dp[i][j + cst] = max(dp[i][j + cst], dp[i - jmp][j - 1 + cst] + cnt[i]);	
			if (j + 1 + cst < MAXK * 2) dp[i][j + cst] = max(dp[i][j + cst], dp[i - jmp][j + 1 + cst] + cnt[i]);	
		}
	}

	//debug(*max_element(dp[9], dp[9] + 2 * MAXK));
	ll ans = 0;
	for (int i = 0; i < MAXN; i++) {
		ans = max(ans, *max_element(dp[i], dp[i] + 2 * MAXK));
	}
	cout << ans << endl;
}