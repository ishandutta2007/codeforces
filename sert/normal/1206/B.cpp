#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

void solve() {
	int n;
	cin >> n;
	ll ans = 0;
	int z = 0, neg = 0;
	while (n--) {
		int x;
		cin >> x;
		z += !x;
		ans += min(abs(x - 1), abs(x + 1));
		if (x < 0) neg++;
	}
	if (!z && neg % 2) ans += 2;
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
#ifdef MADE_BY_SERT
	int T = 3;
	for (int i = 1; i < T; i++) solve();	
#endif
}