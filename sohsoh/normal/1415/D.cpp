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

int n, A[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	for (int i = 1; i < n; i++) {
		int x = A[i] ^ A[i + 1];
		if (i > 1 && x < A[i - 1]) return cout << 1 << endl, 0;
	       	if (i < n - 2 && x > A[i + 2]) return cout << 1 << endl, 0;	
	}

	// n <= 100 :)
	int ans = 1e7;
	for (int i = 1; i <= n; i++) {
		int x = 0;
		for (int j = i; j <= n; j++) {
			x ^= A[j];
			int y = 0;
			for (int k = j + 1; k <= n; k++) {
				y ^= A[k];
				if (x > y) ans = k - i - 1;
			}
		}
	}

	if (ans > n) ans = -1;
	cout << ans << endl;
	return 0;
}