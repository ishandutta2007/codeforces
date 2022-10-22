#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 3e5 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353;

vector<pll> A;
ll dp[MAXN], n, inv[MAXN], h, w, fact[MAXN];


inline ll poww(ll a, ll b) {
	ll ans = 1;
	while (b > 0) {
		if (b & 1) ans = ans * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}

	return ans;
}

inline ll C(int k, int n) {
	if (k < 0 || k > n) return 0;
	return fact[n] * inv[k] % MOD * inv[n - k] % MOD;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	fact[0] = inv[0] = 1;
	for (int i = 1; i < MAXN; i++) fact[i] = fact[i - 1] * i % MOD, inv[i] = poww(fact[i], MOD - 2);

	cin >> h >> w >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		A.push_back({x, y});
	}

	A.push_back({h, w});
	n++;
	
	sort(all(A));
	for (int i = 0; i < n; i++) {
		int x = A[i].X, y = A[i].Y;
		dp[i] = C(x - 1, x + y - 2);
		
		for (int j = 0; j < i; j++) {
			dp[i] += MOD - (dp[j] * C(x - A[j].X, x - A[j].X + y - A[j].Y)) % MOD;
			dp[i] %= MOD;
		}
	}

	cout << dp[n - 1] << endl;	
	return 0;
}