#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = (ll)1e18 + 41;

void solve() {
	int n;
	cin >> n;
	map<int, vector<pair<ll, int>>> mp;
	vector<pair<ll, int>> maxS(n, make_pair(-INF, -1));
	for (int i = 0; i < n; i++) {
		int c, s;
		cin >> c >> s;
		mp[c].push_back(make_pair(s, i + 1));
	}
	ll ans = -1;
	int c1, c2, n1 = 0, n2 = 0;
	for (auto it : mp) {
		vector<ll> v;
		for (const auto &q : it.second) v.push_back(q.first);
		sort(v.rbegin(), v.rend());		

		for (int i = 1; i < (int)v.size(); i++) v[i] += v[i - 1];
		for (int i = 0; i < (int)v.size(); i++) {
			for (int j = max(0, i - 1); j <= i + 1; j++) {
				if (ans < maxS[j].first + v[i]) {
					ans = maxS[j].first + v[i];
					c1 = maxS[j].second;
					c2 = it.first;
					n1 = j + 1;
					n2 = i + 1;
				}
			}
		}

		for (int i = 0; i < (int)v.size(); i++) 
			maxS[i] = max(maxS[i], make_pair(v[i], it.first));
	}
	cout << ans << "\n";
	cout << n1 + n2 << "\n";
	if (n1 < n2) {
		swap(n1, n2);
		swap(c1, c2);
	}
	auto v1 = mp[c1];
	auto v2 = mp[c2];
	sort(v1.rbegin(), v1.rend());
	sort(v2.rbegin(), v2.rend());

	for (int i = 0; i < n1; i++) {
		cout << v1[i].second << " ";
		if (i < n2) cout << v2[i].second << " ";
	}
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
#ifdef SERT
	int t = 2;
	for (int i = 1; i < t; i++) {
		solve();
	}
#endif
}