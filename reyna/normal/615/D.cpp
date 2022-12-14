//In the name of God

#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin(P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax(P &a, Q b) { if (a < b) a = b; return a; }


constexpr int N = 2e5 + 5, mod = 1e9 + 7;

int read() { int x; cin >> x; return x; }

ll cnt[N], dp[N], suf[N], pre[N];

ll pw(ll a, ll b) {
	return b? pw(a * a % mod, b >> 1) * (b & 1? a: 1) % mod: 1;	
}

int32_t main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	fill(cnt, cnt + N, 1);
	fill(dp, dp + N, 1);
	int n = read();
	while (n--) {
		int x = read();
		cnt[x]++;
	}
	ll res = 1;
	pre[0] = suf[N - 1] = 1;
	for (int i = 1; i < N; ++i)
		pre[i] = pre[i - 1] * cnt[i] % (mod - 1);
	for (int i = N - 2; i >= 0; --i)
		suf[i] = suf[i + 1] * cnt[i] % (mod - 1);
	for (int i = 2; i < N - 1; ++i) {
		ll c = suf[i + 1] * pre[i - 1] % (mod - 1);
		ll x = 1;
		for (int k = 1; k <= cnt[i]; ++k) {
			res = res * pw(x, c) % mod;
			x = x * i % mod;	
		}
	}
	cout << res << endl;
}