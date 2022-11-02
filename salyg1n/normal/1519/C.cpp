#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <queue>
#include <deque>
#include <set>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll t;
	cin >> t;
	for (ll T = 0; T < t; ++T) {
		ll n;
		cin >> n;
		vector<ll> u(n), s(n);
		for (auto& i : u)
			cin >> i;
		for (auto& i : s)
			cin >> i;
		vector<vector<ll>> a(n + 1);
		set<int> uni1;
		for (ll i = 0; i < n; ++i) {
			a[u[i]].push_back(s[i]);
			uni1.insert(u[i]);
		}
		for (auto& i : a)
			sort(i.rbegin(), i.rend());
		vector<vector<ll>> p(n + 1);
		for (ll i = 1; i <= n; ++i) {
			p[i].resize(a[i].size() + 1);
			p[i][0] = 0;
			for (ll j = 0; j < a[i].size(); ++j) {
				p[i][j + 1] = p[i][j] + a[i][j];
			}
		}
		vector<int> uni, uni2;
		for (auto i : uni1)
			uni.push_back(i);
		for (ll i = 1; i <= n; ++i) {
			ll ans = 0;
			for (auto j : uni) {
				ans += p[j][a[j].size() / i * i];
				if (p[j][a[j].size() / i * i])
					uni2.push_back(j);
			}
			cout << ans << " ";
			uni = uni2;
			uni2.resize(0);
		}
		cout << "\n";
	}
	return 0;
}