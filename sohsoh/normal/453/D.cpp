#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 2e6 + 10;
ll MOD = 1e9 + 7;

ll m, t, p, A[MAXN], B[MAXN], C[MAXN];

inline void mkey(ll& a) {
	if (a >= MOD) a -= MOD;
	if (a < 0) a += MOD;
}

inline void FWHT(ll* A, bool inv) {
	for (int b = 0; b < m; b++) {
		for (int i = 0; i < (1 << m); i++) {
			if (i & (1 << b)) {
				ll y = A[i], x = A[i ^ (1 << b)];
				mkey(A[i ^ (1 << b)] = x + y);
				mkey(A[i] = x - y);
			}
		}
	}
	
	if (inv) {
		for (int i = 0; i < (1 << m); i++)
			A[i] >>= m;
	}
}

inline ll poww(ll a, ll b) {
	ll ans = 1;
	while (b) {
		if (b & 1)
			ans = __int128(ans) * a % MOD;
		a = __int128(a) * a % MOD;
		b >>= 1;
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> m >> t >> MOD;
	MOD <<= m;

	for (int i = 0; i < (1 << m); i++)
		cin >> A[i];

	for (int i = 0; i <= m; i++)
		cin >> B[i];

	for (int i = 0; i < (1 << m); i++)
		C[i] = B[__builtin_popcount(i)];

	FWHT(A, false);
	FWHT(C, false);
	for (int i = 0; i < (1 << m); i++)
		A[i] = __int128(A[i]) * poww(C[i], t) % MOD;

	FWHT(A, true);
	for (int i = 0; i < (1 << m); i++)
		cout << A[i] << endl;
	return 0;
}