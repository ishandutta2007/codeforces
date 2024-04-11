#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<ll> v(n);
	vector<ll> d;
	for(auto &x : v)
		cin >> x;
	sort(v.begin(), v.end());
	d = v;
	for(int i = m; i < n; i++)
		d[i] += d[i - m];
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		ans += d[i];
		cout << ans << " ";
	}
	cout << '\n';
}