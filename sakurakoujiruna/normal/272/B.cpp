#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios :: sync_with_stdio(false);
	int n; cin >> n;
	map <int, ll> cnt;
	for(int i = 0; i < n; i ++) {
		int x; cin >> x;
		cnt[__builtin_popcount(x)] ++;
	}
	ll ans = 0;
	for(auto p : cnt)
		ans += (p.second - 1) * (p.second) / 2;
	cout << ans << '\n';
	return 0;
}