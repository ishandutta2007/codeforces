#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int kk(ll &x, int d, int c) {
	int ans = 0;
	while (x % d == 0) {
		x /= d;
		ans += c;
	}
	return ans;
}

void k() {
	ll x;
	cin >> x;
	int ans = kk(x, 5, 3) + kk(x, 3, 2) + kk(x, 2, 1);
	cout << (x == 1 ? ans : -1) << "\n";
}

void solve() {
	int t;
	cin >> t;
	while (t--) k();
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