#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
const ll MD = 998244353;

vector<vector<int>> c;
void init() {
	int mx = 2100;
	c.resize(mx);
	for (int i = 0; i < mx; i++) {
		c[i].resize(i + 1);
		c[i][i] = c[i][0] = 1;
		for (int j = 1; j < i; j++) {
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MD;
		}
	}
}

ll step(ll a, ll st) {
	if (st == 0) return 1;
	if (st % 2) return step(a, st - 1) * a % MD;
	ll q = step(a, st / 2);
	return q * q % MD;
}

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	cout << (ll)c[n - 1][k] * m % MD * step(m - 1, k) % MD << "\n";
}

int main() {
	init();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
#ifdef MADE_BY_SERT
	int T = 2;
	for (int i = 1; i < T; i++) solve();	
#endif
}