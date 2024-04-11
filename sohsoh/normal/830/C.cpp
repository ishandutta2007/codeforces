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
const ll MOD = 1e9 + 7; // 998244353;

ll k, n, A[MAXN];

bool solve(ll d) {
	ll t = 0;
	for (int i = 1; i <= n; i++) {
		ll c = A[i] / d;
		if (A[i] % d) c++;
		t += c * d;
		if (t > k) return false;
	}

	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		k += A[i];
	}

	ll ans = 0;
	for (ll i = 1; i * i <= k; i++) {
		if (solve(i)) ans = max(ans, i);
		if (solve(k / i)) ans = max(ans, k / i);
	}

	cout << ans << endl;
	return 0;
}