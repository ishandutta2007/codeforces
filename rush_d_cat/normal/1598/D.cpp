#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	int t;
	cin >> t;
	while (t --) {
		ll n;
		cin >> n;
		int a[n], b[n];
		for (int i = 0; i < n; i ++)
			cin >> a[i] >> b[i];

		vector<ll> ca(n + 1, 0), cb(n + 1, 0);
		for (int i = 0; i < n; i ++) {
			ca[a[i]] ++, cb[b[i]] ++;
		}		

		ll ans = n * (n - 1) * (n - 2) / 6;
		for (int i = 0; i < n; i ++) {
			ca[a[i]] --, cb[b[i]] --;
			ans -= 1ll * ca[a[i]] * cb[b[i]];
			ca[a[i]] ++, cb[b[i]] ++;
		}
		cout << ans << "\n";

	}
}