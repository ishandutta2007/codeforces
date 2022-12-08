#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll A, B;
	cin >> A >> B;
	ll x, y, z;
	cin >> x >> y >> z;
	ll ans = 0LL;
	ll aneed = x*2LL + y;
	ll bneed = y + z*3LL;
	ans += max(0LL, aneed-A);
	ans += max(0LL, bneed-B);
	cout << ans << endl;
	cin >> ans;
}