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
mt19937 rnd(time(NULL));
#define int long long

signed main() {
	int n, m;
	cin >> n >> m;
	int ans = 0;
	vector<vector<int>>a(n + 1, vector<int>(m + 1));
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			char tmp;
			cin >> tmp;
			a[i][j] = tmp - 'a';
		}
	}
	vector<vector<pair<int, int>>>pref1(n + 2, vector<pair<int, int>>(m + 2, { -1, -1 }));
	for (int j = 1; j < m + 1; j++) {
		for (int i = n ; i > 0; i--) {
			if (a[i][j] != pref1[i + 1][j].first) {
				pref1[i][j] = { a[i][j], 1 };
			}
			else {
				pref1[i][j] = { a[i][j], pref1[i + 1][j].second + 1 };
			}
		}
	}
	vector<vector<pair<int, int>>>pref2(n + 2, vector<pair<int, int>>(m + 2, { -1, -1 }));
	for (int i = 1; i < n + 1; i++) {
		for (int j = m; j > 0; j--) {
			if (a[i][j] != pref2[i][j + 1].first) {
				pref2[i][j] = { a[i][j], 1 };
			}
			else {
				pref2[i][j] = { a[i][j], pref2[i][j + 1].second + 1 };
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		int j2 = 0;
		for (int j = 1; j <= m; j++) {
			if (j2 <= j) {
				if (pref1[i][j].second == pref1[i + pref1[i][j].second][j].second && pref1[i][j].second <= pref1[i + 2 * pref1[i][j].second][j].second) {
					int mi = 1001;
					for (int q = i; q < i + 3 * pref1[i + pref1[i][j].second][j].second; q++) {
						mi = min(mi, pref2[q][j].second);
					}
					ans += mi * (mi + 1) / 2;
					j2 = j + mi;
				}
			}
		}
	}
	cout << ans;
	return 0;
}