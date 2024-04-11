#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	ll s, a, b, c;
	while (t--) {
		cin >> s >> a >> b >> c;
		ll take = s/c;
		ll ans = take ;
		ll grp = take/a;
		ans += grp*b;
		cout << ans << endl;
	}
}