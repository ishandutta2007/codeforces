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
#define int			    ll

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int A[MAXN], B[MAXN];

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int s = 0, tot_s = 0;
		for (int i = 0; i < n; i++) {
			cin >> A[i];
			tot_s += A[i];
			int x = A[i];
			if (i % 2 == 1) x = 1;
			B[i] = x;
			s += abs(A[i] - B[i]);
		}
		
		if (2 * s <= tot_s) {
			for (int i = 0; i < n; i++) cout << B[i] << sep;
			cout << endl;
		} else {
			for (int i = 0; i < n; i++) {
				int x = A[i];
				if (i % 2 == 0) x = 1;
				B[i] = x;
			}	
			
			for (int i = 0; i < n; i++) cout << B[i] << sep;
			cout << endl;
			
		}

	}
	return 0;
}