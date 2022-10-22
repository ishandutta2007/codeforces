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

const ll MAXN = 2e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;
const ll LOG = 20;

int n, A[MAXN];
ll ans = 1, tpow[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		A[x]++;	
	}

	for (int i = 0; i < LOG; i++)
		for (int mask = 0; mask < (1 << LOG); mask++)
			if (!(mask & (1 << i)))
				A[mask] += A[mask ^ (1 << i)];
	
	tpow[0] = 1;
	for (int i = 1; i < MAXN; i++) tpow[i] = tpow[i - 1] * 2 % MOD;

	ans = tpow[n];
	for (int i = 1; i < (1 << LOG); i++) {
		if (__builtin_popcount(i) & 1) ans -= tpow[A[i]];
		else ans += tpow[A[i]];
		ans = (ans + MOD) % MOD;
	}

	cout << ans << endl;
	return 0;
}