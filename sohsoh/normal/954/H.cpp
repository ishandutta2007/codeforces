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

const ll MAXN = 1e4 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll VV[MAXN], LV[MAXN], LL[MAXN], n, VV_n[MAXN], LV_n[MAXN], LL_n[MAXN];

inline void DP_Swap() {
	for (int i = 0; i < MAXN; i++) {
		VV[i] = VV_n[i];
		LV[i] = LV_n[i];
		LL[i] = LL_n[i];
		VV_n[i] = 0;
		LV_n[i] = 0;
		LL_n[i] = 0;
	}
}

inline void mkey(ll& x) {
	if (x >= MOD) x -= MOD;
	if (x < 0) x += MOD;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	VV[0] = LV[0] = LL[0] = 1;
	int inv2 = poww(2, MOD - 2, MOD);
	for (int i = 2; i <= n; i++) {
		int k;
		cin >> k;
		LV_n[0] = LL_n[0] = LV[0] * k % MOD;
		mkey(VV_n[0] = VV[0] + LL_n[0]);
		LV_n[1] = LL_n[0];
		mkey(VV_n[1] = VV_n[0] - 1);
		LL_n[2] = LL[0] * k % MOD * (k - 1) % MOD * inv2 % MOD;
		for (int j = 2; j <= 2 * i - 2; j++) {
			if (j != 2) LL_n[j] = LL[j - 2] * k % MOD * k % MOD;
			mkey(LV_n[j] = LL_n[j] + k * (LV[j - 1] + LL[j - 1]) % MOD);
			mkey(VV_n[j] = VV[j] + LV_n[j]);
		}
	
		DP_Swap();
	}

	for (int i = 1; i <= 2 * n - 2; i++) cout << VV[i] << sep;
	cout << endl;
	return 0;
}