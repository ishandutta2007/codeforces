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
//#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}
 
const ll MAXN = 50 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll A[MAXN][MAXN], B[MAXN][MAXN];
ll tpow[MAXN];

bool ith_bit(ll n, ll k) {
	return (n & (1ll << (k - 1))); 
}

int main() {
	fast_io;
	ll n;
	cin >> n;
	tpow[0] = 1;
	for (int i = 1; i < MAXN; i++) tpow[i] = tpow[i - 1] * 2;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i & 1) A[i][j] = 0;
			else A[i][j] = tpow[i + j];
			cout << A[i][j] << sep;
		}

		cout << endl;
	}

	ll q;
	cin >> q;
	while (q--) {
		ll k;
		cin >> k;
		cout << 1 << sep << 1 << endl;
		pll p = {0, 0};
		while (p.X < n - 1 || p.Y < n - 1) {
			if (p.Y & 1) {
				if (p.Y + 1 < n && ith_bit(k, p.X + p.Y + 2)) p.Y++;
				else p.X++;
			} else {	
				if (p.X + 1 < n && ith_bit(k, p.X + p.Y + 2)) p.X++;
				else p.Y++;
			}

			cout << p.Y + 1 << sep << p.X + 1 << endl;
			
		}
	}
	
}