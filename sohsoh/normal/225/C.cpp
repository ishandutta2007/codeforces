/*
    Soheil Mohammadkhani
    OK, im back :)
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
 
const ll MAXN = 1e3 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

// i: col
// j: rep
// k: color
// 1: black
// 0: white

ll dp[MAXN][2], w_c[MAXN], b_c[MAXN], A[MAXN][MAXN], n, m, x, y;

int main() {
	fast_io;
	cin >> n >> m >> x >> y;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;
			if (c == '#') A[i][j] = 1;
			else A[i][j] = 0;
		}
	}

	for (int i = 0; i < m; i++) {
		ll b = 0;
		dp[i][0] = dp[i][1] = INF;
		for (int j = 0; j < n; j++) b += A[j][i];
		w_c[i] = b;
		b_c[i] = n - b;
	}
	
	for (int i = 0; i < m; i++) {
		ll bc = 0, wc = 0;
		for (int j = i; j >= -1 && i - j <= y; j--) {
			if (i - j >= x) {
				ll tb = wc, tw = bc;
				if (j >= 0) {
					tb += dp[j][0];
					tw += dp[j][1];	
				}

				dp[i][0] = min(dp[i][0], tw);
				dp[i][1] = min(dp[i][1], tb);
			}
			
			if (j < 0) break;
			bc += b_c[j];
			wc += w_c[j];
		}
	}	
	
	cout << min(dp[m - 1][0], dp[m - 1][1]);
}