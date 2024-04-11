#include <bits/stdc++.h>

using namespace std;
using nagai = long long;

const int N = 50000;
int rofl[N][5];

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<pair<int, int>> a(k);
		vector<bool>used(2 * n);
		for(int i = 0; i < k; ++i) {
			cin >> a[i].first >> a[i].second;
			--a[i].first;
			--a[i].second;
			if (a[i].first > a[i].second) swap(a[i].first, a[i].second);
			used[a[i].first] = used[a[i].second] = true;
		}
		vector<int>kek;
		for(int i = 0; i < 2 * n; ++i) 
			if(!used[i])kek.push_back(i);
		for(int i = 0; i < n - k; ++i) 
			a.emplace_back(kek[i], kek[i + n - k]);
		int cnt = 0;
		for(int i = 0; i < a.size(); ++i)
			for(int j = 0; j < i; ++j) {
				vector<int> rofl = {a[i].first, a[j].first, a[i].second, a[j].second};
				sort(rofl.begin(),rofl.end());
				if (rofl[0] == a[i].first && rofl[2] == a[i].second || rofl[0] == a[j].first && rofl[2] == a[j].second)
					++cnt;
			}
		cout << cnt << '\n';
	}
  return 0;
}