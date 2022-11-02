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
	int t;
	cin >> t;
	for (int q = 0; q < t; q++) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>>c(n, vector<int>(m));
		vector<pair<int, int>>b(n * m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> c[i][j];
				b[i * m + j] = { -c[i][j], j };
			}
		}
		sort(b.begin(), b.end());
		set<int>s;
		for (int i = 0; i < min(n * m, 7ll); i++) {
			s.insert(b[i].second);
		}
		vector<vector<int>>a(2 * n, vector<int>((int)s.size()));
		int z = 0;
		for (auto u : s) {
			for (int i = 0; i < n; i++) {
				a[i][z] = c[i][u];
			}
			for (int i = 0; i < n; i++) {
				a[i + n][z] = c[i][u];
			}
			z++;
		}
		int k = (int)s.size();
		int ans = 0;
		vector<vector<int>>d(n, vector<int>((int)s.size()));
		for (int q = 0; q < 40000; q++) {
			int q2 = q;
			vector<int>num(k);
			for (int i = 0; i < k; i++) {
				num[i] = q2 % n;
				q2 /= n;
			}
			for (int j = 0; j < k; j++) {
				for (int i = 0; i < n; i++) {
					d[i][j] = a[num[j] + i][j];
				}
			}
			int cnt = 0;
			for (int i = 0; i < n; i++) {
				int ma = 0;
				for (int j = 0; j < k; j++) {
					ma = max(d[i][j], ma);
				}
				cnt+=ma;
			}
			ans = max(ans, cnt);
		}
		cout << ans << '\n';
	}
	return 0;
}