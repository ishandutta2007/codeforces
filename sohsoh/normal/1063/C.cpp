#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
 
#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
//#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
 
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}
 
const ll MAXN = 2000 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll L = 0, R = 1e9;
	ll n;
	cin >> n;
	cout << 0 << sep << 10 << endl;
	string s, ps;
	cin >> s;
	ps = s;	

	ll p = 1;
	while (p < n) {
		p++;
		ll mid = (L + R) / 2;
		cout << mid << sep << 10 << endl;
		cin >> s;
		ll x = -1;
		if (s == ps) x = 1;

		if (x > 0) L = mid;
		else R = mid;
	} 

	cout << L << sep << 11 << sep << R << sep << 9  << endl; 
	return 0;
}