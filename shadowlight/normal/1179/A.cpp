#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	//freopen("A.in", "r", stdin);
	//freopen("A.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	ll n, q;
	cin >> n >> q;
	deque <ll> a;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a.push_back(x);
	}
	vector <pair <int, int> > res;
	for (int i = 0; i < 2 * n; i++) {
		ll x = a[0], y = a[1];
		res.push_back({x, y});
		a.pop_front();
		a.pop_front();
		a.push_front(max(x, y));
		a.push_back(min(x, y));
	}
	for (int i = 0; i < q; i++) {
		ll s;
		cin >> s;
		if (s <= (ll) res.size()) {
			cout << res[s - 1].first << " " << res[s - 1].second << "\n";
		} else {
			s -= (res.size() + 1);
			s %= n - 1;
			cout << a[0] << " " << a[s + 1] << "\n";
		}
	}
}