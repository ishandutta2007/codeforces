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
 
const ll MAXN = 3e4 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll A[MAXN], B[MAXN];

int main() {
	fast_io;
	ll n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> A[i];
	for (int i = 0; i < m; i++) cin >> B[i];
	for (int i = 0; i < 514; i++) {
		bool b = true;
		for (int j = 0; j < n; j++) {
			bool bb = false;
			for (int k = 0; k < m; k++) if ((i | (B[k] & A[j])) == i) bb = true;
			b = b & bb;
		}

		if (b) return cout << i << endl, 0;
	}

	return 0;	
}