#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
	ll x;
	cin >> x;
	cout << (x < 13 ? (1ll << x) : (8092ll << (x - 13))) << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
#ifdef SERT
	int t = 4;
	for (int i = 1; i < t; i++) {
		solve();
	}
#endif
}