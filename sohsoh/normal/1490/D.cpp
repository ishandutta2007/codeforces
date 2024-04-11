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

int n, A[MAXN], ans[MAXN];

inline void calc(int l, int r, int d = 0) {
	if (r < l) return;
	if (r == l) {
		ans[l] = d;
		return;
	}
	
	int ind = max_element(A + l, A + r + 1) - A;
	ans[ind] = d;
	calc(l, ind - 1, d+  1);
	calc(ind + 1, r, d + 1);
}

inline int solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	calc(1, n);
	for (int i = 1; i <= n; i++) cout << ans[i] << sep;
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