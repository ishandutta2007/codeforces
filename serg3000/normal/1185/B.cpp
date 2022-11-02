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
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")
#pragma comment(linker, "/STACK:256000000")
#pragma warning(disable:4996)
using namespace std;
mt19937 rnd(time(NULL));

signed main() {
	int n;
	cin >> n;
	vector<string>a(n);
	vector<string>b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cin >> b[i];
	}
	for (int i = 0; i < n; i++) {
		vector<pair<int, int>>c;
		vector<pair<int, int>>d;
		c.push_back({ a[i][0] - 'a', 1 });
		d.push_back({ b[i][0] - 'a', 1 });
		for (int j = 1; j < a[i].size(); j++) {
			if (a[i][j] != a[i][j - 1]) {
				c.push_back({ a[i][j] - 'a', 1 });
			}
			else {
				c[(int)c.size() - 1].second++;
			}
		}
		for (int j = 1; j < b[i].size(); j++) {
			if (b[i][j] != b[i][j - 1]) {
				d.push_back({ b[i][j] - 'a', 1 });
			}
			else {
				d[(int)d.size() - 1].second++;
			}
		}
		if (d.size() == c.size()) {
			int z = 0;
			for (int i = 0; i < d.size(); i++) {
				if (d[i].first != c[i].first || d[i].second < c[i].second) {
					cout << "NO" << '\n';
					z = 1;
					break;
				}
			}
			if (z == 0) {
				cout << "YES" << '\n';
			}
		}
		else {
			cout << "NO" << '\n';
		}
	}

	
	return 0;
}