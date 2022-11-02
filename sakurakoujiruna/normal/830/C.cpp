#include <bits/stdc++.h>
using namespace std;

#define pb push_back
const int N = 121;
using ll = long long;

ll a[N];
ll f(ll n, ll k) {
	return (n + k - 1) / k;
}
ll now[N];

int main() {
	ios :: sync_with_stdio(0);
	int n; ll k; cin >> n >> k;
	vector <pair <int, int>> v;
	ll all = 0;
	for(int i = 1; i <= n; i ++) {
		ll j = 1;
		cin >> a[i];
		all += a[i];
		
		v.pb({1, i});
		for(int j = 1; j <= a[i]; j = a[i] / (a[i] / (j + 1))) {
			if(j == a[i]) break;
			v.pb({j + 1, i});
		}
		for(int j = 1; j * j <= a[i]; j ++) if(a[i] % j == 0) {
			v.pb({j, i}); v.pb({a[i] / j, i});
		}
	}
	
	sort(v.begin(), v.end());
	//cout << v.size() << '\n';
	//for(auto i : v) cout << i.first << ' ' << i.second << '\n';
	ll ans = 0, sum = 0;
	for(int i = 0; i < v.size(); i ++) {
		sum -= now[v[i].second];
		sum += f(a[v[i].second], v[i].first);
		now[v[i].second] = f(a[v[i].second], v[i].first);

		ll l = v[i].first, r = (i + 1 == v.size()) ? 2e11L : v[i + 1].first - 1;
		//cout << sum << ' ' << l << ' ' << r << '\n';
		
		r = min(r, (k + all) / sum);
		if(l <= r) ans = max(ans, r);
		
	}
	cout << ans << '\n';
	
}