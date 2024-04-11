#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <set>
#include <queue>
#include <deque>
#include <unordered_set>
#include <map>
#include<unordered_map>
#include <bitset>
#include <random>
#include <ctime>
using namespace std;
#define int long long
signed main() {
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>>a(k);
	vector<vector<pair<int, int>>>g(n);
	for (int i = 0; i < k; i++) {
		cin >> a[i].first >> a[i].second;
		a[i].first--;
		a[i].second--;
		g[a[i].first].push_back({ i, a[i].second });
		g[a[i].second].push_back({i, a[i].first});
	}
	vector<int>used(n);
	vector<int>b;
	used[a[0].first] = 1;
	used[a[0].second] = 1;
	int ans = 1;
	vector<int>d(k);
	d[0] = 1;
	int z = 0;
	b.push_back(a[0].first);
	b.push_back(a[0].second);
	int i2 = 0;
	while (1) {
		if (i2 == b.size()) {
			while (z != k) {
				if (d[z] == 0) {
					if (used[a[z].first] == 0 || used[a[z].second] == 0) {
						used[a[z].first] = 1;
						used[a[z].second] = 1;
						d[z] = 1;
						b.push_back(a[z].first);
						b.push_back(a[z].second);
						ans++;
						break;
					}
				}
				z++;
			}
		}
		if (z == k) {
			break;
		}
		for (auto x : g[b[i2]]) {
			if (used[x.second] == 0) {
				used[x.second] = 1;
				ans++;
				d[x.first] = 1;
				b.push_back(x.second);
			}
		}
		i2++;
	}
	cout << k - ans;
	return 0;
}