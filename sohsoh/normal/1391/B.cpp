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
 
const ll MAXN = 1000 + 10; // change
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

bool A[MAXN][MAXN];

int main() {
	fast_io;
	ll t;
	cin >> t;
	while (t--) {
		ll n, m;
		cin >> n >> m;
		ll ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				char c;
				cin >> c;
				if (i == n - 1 && j < m - 1) {
					if (c != 'R') ans++;
				}

				if (j == m - 1 && i < n - 1) {
					if (c != 'D') ans++;
				}
			}
		}

		cout << ans << endl;
	}
	return 0;
}