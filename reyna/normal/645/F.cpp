//In the name of God

#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin(P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax(P &a, Q b) { if (a < b) a = b; return a; }

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)

const int N = 1e6 + 6, mod = 1e9 + 7;

int mul(int x, int y) { return 1LL * x * y % mod; }
int addd(int x, int y) { int z = x + y; while (z >= mod) z -= mod; while(z < 0) z += mod; return z; }
int pw(int a, int b) { return b? 1LL * pw(a * 1LL * a % mod, b >> 1) * (b & 1? a: 1) % mod: 1; }
int inv(int x) { return pw(x, mod - 2); }


int read() { int x; cin >> x; return x; }

int res = 0, comb[N], f[N], pr[N], cnt[N], dp[N], change[N];
vector<int> dv[N], primes, in[N], out[N];

void add(int x) {
	for (int d : dv[x])
		res = (res - (dp[d] * 1LL * d % mod) + mod) % mod;
	for (int j = dv[x].size() - 1; j >= 0; --j) {
		int i = dv[x][j];
//		dp[i] = add(dp[i], add(comb[cnt[i] + 1], -comb[cnt[i]]));
		change[i] = addd(change[i], comb[cnt[i] + 1] - comb[cnt[i]]);
//		change[i] %= mod;
//		dp[i] %= mod;
		cnt[i]++;
		dp[i] = addd(dp[i], change[i]);
		for (int d : dv[i]) {
			change[d] = addd(change[d], -change[i]);
//			dp[d] = add(dp[d], change[i]);
//			change[d] -= change[i] - mod;
//			dp[d] -= change[i] - mod;	
//			change[d] %= mod;
//			dp[d] %= mod;
		}
	}
	for (int d : dv[x]) {
//		dp[d] = add(dp[d], change[d]);
//		cout << d << ' ' << dp[d] << endl;
		res = (res + (dp[d] * 1LL * d % mod)) % mod;
		change[d] = 0;
	}
}

int32_t main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n = read(), k = read(), q = read();
	f[0] = 1;
	for (int i = 1; i < N; ++i)
		f[i] = f[i - 1] * 1LL * i % mod;
	for (int i = k; i < N; ++i)
		comb[i] = mul(f[i], mul(inv(f[i - k]), inv(f[k])));
	for (int i = 1; i < N; ++i)
		for (int j = i; j < N; j += i)
			dv[j].push_back(i);
	for (int i = 2; i < N; ++i)
		if (dv[i].size() == 2)
			primes.push_back(i), pr[i] = 1;
//	for (int i = 1; i < N; ++i)
//		
//			in[j].push_back(i);
	rep(i, n + q) {
		int x; cin >> x;
		add(x);
//		for (int j = 1; j < 7; ++j)
//			cout << j << ' ' << dp[j] << endl;
//		cout << endl << endl;
		if (i >= n)
			cout << res << '\n';
	}
}