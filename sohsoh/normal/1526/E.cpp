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
const ll MOD = 998244353; // 1e9 + 9;

int n, k, A[MAXN], ind[MAXN];
ll fact[MAXN];

inline ll inv(ll a) {
	ll b = MOD - 2, ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}

	return ans;
}

inline ll C(ll k, ll n) {
	if (k < 0 || n < k) return 0;
	return fact[n] * inv(fact[k]) % MOD * inv(fact[n - k]) % MOD;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
		ind[A[i]] = i;
	}

	int cnt = 1;
	for (int i = 1; i < n; i++) {
		if (A[i] == n - 1) {
			cnt++;
			continue;
		}

		if (A[i - 1] == n - 1) continue;
		if (ind[A[i] + 1] < ind[A[i - 1] + 1]) cnt++;
	}
	
	fact[0] = 1;
	for (int i = 1; i < MAXN; i++) fact[i] = fact[i - 1] * i % MOD;

	cout << C(k - cnt, n + k - cnt) << endl;
	return 0;
}