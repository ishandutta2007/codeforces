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

int n, B[MAXN], A[MAXN];

inline int solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		char c;
		cin >> c;
		B[i] = char(c - '0');
	}
	
	int p = 0;
	for (int i = 1; i <= n; i++) {
		if (1 + B[i] == p) cout << 0, p = B[i];
		else cout << 1, p = 1 + B[i];
	}

	cout << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}