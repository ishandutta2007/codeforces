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
 
const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int main() {
	fast_io;
	ll n;
	cin >> n;
	if (n % 2 == 0) return cout << "NO" << endl, 0;
	vector<ll> v1, v2;
	for (int i = 1; i <= 2 * n; i += 2) {
		if ((i - 1) % 4 == 0) v1.push_back(i), v2.push_back(i + 1);
		else v1.push_back(i + 1), v2.push_back(i);
	}	

	cout << "YES" << endl;
	for (ll e : v1) cout << e << sep;
	for (ll e : v2) cout << e << sep;
	cout << endl;
	return 0;
}