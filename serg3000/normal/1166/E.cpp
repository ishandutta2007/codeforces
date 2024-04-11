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
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("no-stack-protector")
signed main() {
	int m, n;
	cin >> m >> n;
	vector<vector<int>>a(m);
	for (int i = 0; i < m; i++) {
		int k;
		cin >> k;
		for (int j = 0; j < k; j++) {
			int x;
			cin >> x;
			a[i].push_back(x);
		}
	}
	for (int i = 0; i < m; i++) {
		map<int, int> mp;
		for (int j = 0; j < (int)a[i].size(); j++) {
			mp[a[i][j]] = 1;
		}
		int fl = 0;
		for (int j = 0; j < m; j++) {
			int c = 0;
			for (int q = 0; q < (int)a[j].size(); q++) {
				if (mp[a[j][q]] == 1) {
					c++;
					break;
				}
			}
			if (c == 0) {
				fl = 1;
				break;
			}
		}
		if (fl == 1) {
			cout << "impossible";
			return 0;
		}
	}
	cout << "possible";
	return 0;
}