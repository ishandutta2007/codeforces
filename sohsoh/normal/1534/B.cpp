// Sohsoh84 O_o //
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

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n, A[MAXN];

inline int solve() {
	fill(A, A + n + 10, 0);
	ll ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i], ans += abs(A[i] - A[i - 1]);
	ans += A[n];

	for (int i = 1; i <= n; i++)
		if (A[i] > A[i - 1] && A[i] > A[i + 1]) ans -= (A[i] - max(A[i - 1], A[i + 1])) ,
		       	A[i] = max(A[i - 1], A[i + 1]);
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