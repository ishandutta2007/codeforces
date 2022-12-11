#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = (int)3e5 + 34;
//const ll INF = (ll)1e18 + 41;
const int INF = (int)1e9 + 41;
const ll MD = (ll)1e9 + 7;
bool D = false;

int dp[N][7];
ll fac[N];
ll ofac[N];

ll step(ll a, ll st) {
	if (st == 0) return 1;
	if (st % 2) return a * step(a, st - 1) % MD;
	ll q = step(a, st / 2);
	return q * q % MD;
}

ll bak(ll x) {
	return step(x, MD - 2);
}

void init() {
	fac[0] = ofac[0] = 1;
	for (int i = 1; i < N; i++) {
		fac[i] = fac[i - 1] * i % MD;
		ofac[i] = bak(fac[i]);
	}
}

ll C(int n, int k) {
	if (k < 0 || k > n) return 0;
	return fac[n] * ofac[n - k] % MD * ofac[k];
}

void solve() {
	vector<int> numDiv(N, 0);
	int n, g = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		g = __gcd(g, x);
		for (int q = 1; q * q <= x; q++) {
			if (x % q) continue;
			numDiv[q]++;
			if (q * q != x) numDiv[x / q]++;
		}
	}

	if (g > 1) {
		cout << "-1\n";
		return;
	}

	for (int ans = 1; true; ans++) {
		vector<ll> dp(N, 0);
		for (int i = N - 1; i > 0; i--) {
			dp[i] = C(numDiv[i], ans);
			for (int j = i * 2; j < N; j += i) {
				dp[i] = (dp[i] - dp[j] + MD) % MD;
			}
		}
		if (dp[1] > 0) {
			cout << ans << "\n";
			return;
		}
	}
}

int main() {
	init();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tst = 1;
	//scanf("%d", &tst);
	//cin >> tst;
#ifdef MADE_BY_SERT
	D = true;	
	tst = 3;
	while (tst--) {
		solve();
	}
#else
	while (tst--) solve();
#endif
}