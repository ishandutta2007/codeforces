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
mt19937 rnd(time(nullptr));
#define int long long
#define all(v) v.begin(), v.end()
int gcd(int a, int b) {
	while (b != 0) {
		int c = a % b;
		a = b;
		b = c;
	}
	return a;
}
signed main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	for (int q = 0; q < t; q++) {
		int n, m;
		cin >> n >> m;
		vector<int>c(n);
		vector<vector<int>>g(n);
		for (int i = 0; i < n; i++) {
			cin >> c[i];
		}
		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			u--; v--;
			g[v].push_back(u);
		}
		vector<int>a(n);
		for (int i = 0; i < n; i++) {
			a[i] = rnd() % 1000000000000;
		}
		vector<pair<int, int>>b(n);
		for (int i = 0; i < n; i++) {
			int cnt = 0;
			for (auto x : g[i]) {
				cnt += a[x];
			}
			b[i].first = cnt;
			if (cnt == 0) {
				b[i].first = -1;
			}
			b[i].second = i;
		}
		sort(all(b));
		int ans = 0;
		int z = c[b[0].second];
		for (int i = 1; i < n; i++) {
			if (b[i].first != b[i - 1].first) {
				if (b[i - 1].first != -1) {
					ans = gcd(ans, z);
				}
				z = c[b[i].second];
			}
			else {
				z += c[b[i].second];
			}
		}
		ans = gcd(ans, z);
		cout << ans << '\n';
	}



	return 0;
}