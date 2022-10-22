#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;

vector<pll> vec[2];
ll A[MAXN], B[MAXN], C[MAXN], D[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll n, m, k, x, s;
	cin >> n >> m >> k >> x >> s;
	A[0] = x;
	B[0] = 0;
	C[0] = 0;
	D[0] = 0;
	
	for (int i = 1; i <= m; i++) cin >> A[i];
	for (int i = 1; i <= m; i++) cin >> B[i];
	for (int i = 1; i <= k; i++) cin >> C[i];
	for (int i = 1; i <= k; i++) cin >> D[i];

	ll ans = ll(8e18);
	for (int i = 0; i <= m; i++) {
		if (B[i] > s) continue;
		int ind = upper_bound(D, D + k + 1, s - B[i]) - D;

		ans = min(ans, (n - C[ind - 1]) * A[i]);
	}

	cout << max(ans, 0ll) << endl;
	return 0;
}