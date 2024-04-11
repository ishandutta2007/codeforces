/*
    Soheil Mohammadkhani
    Sos Goge Tabarok :)
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
 
const ll MAXN = 1e4 + 10;
const ll MAXK = 1e3 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;
const ld EPS = 1e-7;

ld dp[MAXN][MAXK] = {0};

int main() {
	fast_io;
	ll k, q;
	cin >> k >> q;
	dp[0][0] = 1;
	for (int i = 0; i < MAXN - 1; i++) {
		for (int j = 0; j <= k; j++) {
			ld p1 = dp[i][j] * ld(j) / ld(k);
			ld p2 = dp[i][j] - p1;
		
			dp[i + 1][j] += p1;
		      	dp[i + 1][j + 1] += p2;	
		}
	}

	while (q--) {
		ld p;
		cin >> p;
		for (int i = 0; i < MAXN; i++) if (dp[i][k] > ld(p - EPS) / ld(2000)) {
			cout << i << endl;
			break;
		}
	}
}