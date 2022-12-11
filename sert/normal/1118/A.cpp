#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

void kek() {
	ll n, a, b;
	cin >> n >> a >> b;
	cout << min(n * a, n / 2 * b + n % 2 * a) << "\n";
}

void solve() {
	int t;
	cin >> t;
	while (t--) {
		kek();
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