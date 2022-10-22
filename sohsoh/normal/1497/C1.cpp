#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
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

inline int solve(int n) {
	if (n % 4 == 0) return cout << n / 4 << sep << n / 4 << sep << n / 2 << endl, 0;
	if (n % 4 == 2) return cout << 2 << sep << (n - 2) / 2 << sep << (n - 2) / 2 << endl, 0;
	return cout << 1 << sep << (n - 1) / 2 << sep << (n - 1) / 2 << endl, 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
	  	int n, k;
		cin >> n >> k;
		solve(n);
	}
	return 0;
}