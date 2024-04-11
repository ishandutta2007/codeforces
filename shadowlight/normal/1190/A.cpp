#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	//freopen("A.in", "r", stdin);
	//freopen("A.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	ll n, m, k;
	cin >> n >> m >> k;
	vector <ll> a(m);
	for (ll i = 0; i < m; i++) {
		cin >> a[i];
	}
	ll cnt = 0;
	ll del = 0;
	while (del < m) {
		cnt++;
		ll now = a[del] - del;
		ll l = (now - 1) / k * k + 1, r = l + k;
		ll last = del;
		while (del < m && a[del] - last < r) {
			//cout << a[del] - last << " ";
			del++;
		}
		//cout << "\n";
	}
	cout << cnt << "\n";
}