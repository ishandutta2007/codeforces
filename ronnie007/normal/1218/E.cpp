#include <bits/stdc++.h>
#define endl '\n'

#define SZ(x) ((int)x.size())
#define ALL(V) V.begin(), V.end()
#define L_B lower_bound
#define U_B upper_bound
#define pb push_back

using namespace std;
template<class T, class T1> int chkmin(T &x, const T1 &y) { return x > y ? x = y, 1 : 0; }
template<class T, class T1> int chkmax(T &x, const T1 &y) { return x < y ? x = y, 1 : 0; }
const int MAXN = (1 << 15);
const int mod = 998244353;

int n, k;
int _a[MAXN], a[MAXN];

void read() {
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		cin >> _a[i];
	}
}

int perm[MAXN], iperm[MAXN];

int pw(int x, int p) { 
	int r = 1;
	while(p) {
		if(p & 1) r = r * 1ll * x % mod;
		x = x * 1ll * x % mod;
		p >>= 1;
	}

	return r;
}

void precompute() {
	perm[0] = 1;
	for(int i = 1; i < MAXN; i++) {
		perm[i] = i * 1ll * perm[i - 1] % mod;
	}

	iperm[MAXN - 1] = pw(iperm[MAXN - 1], mod - 2);
	for(int i = MAXN - 2; i >= 0; i--) {
		iperm[i] = iperm[i + 1] * 1ll * (i + 1) % mod;
	}
}

int dp[MAXN];

int solve_fast() {
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = min(i + 1, k); j >= max(1, k - (n - i - 1)); --j) {
            dp[j] = (dp[j] + dp[j - 1] * 1ll * a[i]) % mod;
        }
    }

	return dp[k];
}

void solve() {
	precompute();

	int q;
	cin >> q;
	while(q--) {
		int type, x;
		cin >> type >> x;

		for(int i = 0; i < n; i++) a[i] = _a[i];

		if(type == 1) {
			int i, d;
			cin >> i >> d;
			a[i - 1] = d;
		} else {
			int l, r, d;
			cin >> l >> r >> d;
			for(int i = l - 1; i < r; i++) 
				a[i] += d, a[i] %= mod;
		}

		for(int i = 0; i < n; i++) {
			a[i] = (x - a[i] + mod) % mod; 
		}

		cout << solve_fast() << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	read();
	solve();
	return 0;
}