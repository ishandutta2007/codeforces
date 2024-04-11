// orz
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

const ll MAXN = 14;
const ll MOD = 1e9 + 7;

inline ll poww(ll a, ll b) {
	ll ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}

	return ans;
}

inline ll inv(ll a) {
	return poww(a, MOD - 2);
}

inline bool wtf(ll msk, int ind) {
	if (msk & (1 << ind)) return true;
	return false;
}

int n, MASK;
ll F[1 << MAXN], A[MAXN][MAXN], B[MAXN], ans, I[MAXN][MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	MASK = (1 << n);

	for (int i = 0; i < n; i++) cin >> B[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			A[i][j] = B[i] * inv(B[i] + B[j]) % MOD, I[i][j] = inv(A[i][j]);

	for (int msk = 1; msk < MASK; msk++) {
		F[msk] = 1;
		

		vector<int> v, v2;
		for (int i = 0; i < n; i++) {
			if (wtf(msk, i))
				v.push_back(i);
			else 
				v2.push_back(i);
		}

		for (int s = msk; s; s = (s - 1) & msk) {
			if (s == msk) continue;
			ll t = F[s];

			for (int i : v)
				for (int j : v2)
					if (wtf(s, i))
						t = t * I[i][j] % MOD;
			
			F[msk] = (F[msk] - t + MOD) % MOD;

		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (wtf(msk, i) && !wtf(msk, j)) {
					F[msk] = F[msk] * A[i][j] % MOD;
				}
			}
		}

		ans = (ans + F[msk] * __builtin_popcount(msk)) % MOD;
	}
	
	cout << ans << endl;
	return 0;
}