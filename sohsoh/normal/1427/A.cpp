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
 
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}
 
const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll A[MAXN], n;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll t;
	cin >> t;
	while (t--) {
		cin >> n;
		ll s = 0;
		for (int i = 0; i < n; i++) cin >> A[i], s += A[i];
		if (s == 0) cout << "NO" << endl;
		else {
			cout << "YES" << endl;
			sort(A, A + n);
			if (s < 0) {
				for (int i = 0; i < n; i++) cout << A[i] << sep;
				cout << endl;
			} else {
				reverse(A, A + n);
				for (int i = 0; i < n; i++) cout << A[i] << sep;
				cout << endl;
			}
		}
	}
	return 0;
}