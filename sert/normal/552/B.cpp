#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

void solve() {
	ll n;
	cin >> n;
	
	vector<ll> st = {1};
	for (int i = 1; i < 12; i++) {
		st.push_back(st.back() * 10);
	}

	ll ans = 0;
	for (int len = 1; len < 12; len++) {
		if (n < st[len]) {
			cout << ans + len * (n + 1 - st[len - 1]) << "\n";
			return;
		}
		ans += len * (st[len] - st[len - 1]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
#ifdef MADE_BY_SERT
	int T = 1;
	for (int i = 1; i < T; i++) solve();	
#endif
}