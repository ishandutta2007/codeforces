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

ll B[MAXN] = {0}, A[MAXN], P[MAXN] = {0};

int main() {
	fast_io;	
	ll n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	ll q;
	cin >> q;
	for (int i = 1; i <= q; i++) {
		ll cmd;
		cin >> cmd;
		if (cmd == 1) {
			ll p, x;
			cin >> p >> x;
			A[p] = x;
			P[p] = i;
		} else {
			ll x;
			cin >> x;
			B[i] = x;
		}
	}

	for (int i = q - 1; i >= 0; i--) B[i] = max(B[i], B[i + 1]);
	for (int i = 1; i <= n; i++) cout << max(A[i], B[P[i]]) << sep;
	cout << endl;
	return 0;
}