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

int A[MAXN];
bool ok1[MAXN], ok2[MAXN];

int solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> A[i];
	fill(ok1, ok1 + n + 10, true);
	fill(ok2, ok2 + n + 10, true);

	int open = 0;
	for (int i = 0; i < n; i++) {
		if (i > 0) ok1[i] = ok1[i - 1];
		if (i > 0) open -= A[i] - A[i - 1] - 1;
		open = max(open, 0);
		if (2 * n - A[i] - (n - i - 1) - open < 1) ok1[i] = false;
		open++;
	}


	open = 0;
	for (int i = n - 1; i >= 0; i--) {
		ok2[i] = ok2[i + 1];
		if (i < n - 1) open -= A[i + 1] - A[i] - 1;
		open = max(open, 0);
		if (A[i] - 1 - i - open < 1) ok2[i] = false;
		open++;
	}

	
	int ans = 0;
	for (int i = 0; i <= n; i++) if ((i == 0 || ok1[i - 1]) && ok2[i]) ans++;
	cout << ans << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}