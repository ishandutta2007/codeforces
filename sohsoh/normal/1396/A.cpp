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

ll A[MAXN];

int main() {
	fast_io;
	ll n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> A[i];
	if (n == 1) {
		cout << 1 << sep << 1 << endl << -1 * A[0] << endl;
		cout << 1 << sep << 1 << endl <<  0 << endl;
		cout << 1 << sep << 1 << endl <<  0 << endl;
		return 0;
	}

	cout << 1 << sep << n - 1 << endl;
	for (int i = 0; i < n - 1; i++) {
		cout << (A[i] % n) * (n - 1) << sep;
		A[i] +=  (A[i] % n) * (n - 1); 
	}

	cout << endl;
	cout << n << sep << n << endl << -1 * A[n - 1] << endl;	
	A[n - 1] = 0;
	cout << 1 << sep << n << endl;
	for (int i = 0; i < n; i++) cout << -1 * A[i] << sep;
	cout << endl;
	return 0;
}