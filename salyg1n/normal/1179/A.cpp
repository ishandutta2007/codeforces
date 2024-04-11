#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <deque>
#include <unordered_map>
#include <time.h>
#include <set>
#include <unordered_set>
#include <cmath>
#include <queue>

#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n, q;
	cin >> n >> q;
	deque<ll> d(n);
	ll mx = -1;
	for (auto& i : d) {
		cin >> i;
		mx = max(mx, i);
	}

	vector<pair<ll, ll>> a;
	ll b = -1, c = -1;
	while (b != mx && c != mx) {
		b = d.front();
		d.pop_front();
		c = d.front();
		d.pop_front();
		a.push_back({ b, c });
		d.push_back(min(c, b));
		d.push_front(max(b, c));
	}
	for (ll i = 0; i < q; ++i) {
		ll x;
		cin >> x;
		if (x <= a.size())
			cout << a[x - 1].first << " " << a[x-1].second << "\n";
		else {
			x -= a.size();
			x = (x-1) % (n - 1);
			cout << mx << " " << d[x + 1] << '\n';
		}
	}
	return 0;
}