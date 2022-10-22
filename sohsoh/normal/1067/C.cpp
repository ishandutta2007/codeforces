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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	cout << 0 << sep << 0 << endl;
	n--;
	ll x = n / 4;
	for (int i = 1; i <= x; i++) cout << 0 << sep << i << endl << 0 << sep << -1 * i << endl << i << sep << 0 << endl << -i << sep << 0 << endl;
	if (n % 4 == 1) cout << 0 << sep << x + 1 << endl;
	if (n % 4 == 2) cout << 0 << sep << x + 1 << endl << x + 1 << sep << 0 << endl;
	if (n % 4 == 3) cout << 0 << sep << x + 1 << endl << x + 1 << sep << 0 << endl << 0 << sep << -1 * (x + 1) << endl;
	return 0;
}