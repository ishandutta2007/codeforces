#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

ll kk(ll sz, ll k) {
	return (sz + k - 1) / k;
}

void solve() {
	ll n, k;
	cin >> n >> k;
	cout << kk(n * 2, k) + kk(n * 5, k) + kk(n * 8, k) << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
#ifdef MADE_BY_SERT
	int T = 2;
	for (int i = 1; i < T; i++) solve();	
#endif
}