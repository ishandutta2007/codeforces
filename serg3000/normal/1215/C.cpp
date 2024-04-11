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
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	vector<int>a(n);
	vector<int>b(n);
	vector<int>c, d, e;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'b') {
			a[i] = 1;
		}
		if (t[i] == 'b') {
			b[i] = 1;
		}
		cnt += a[i] + b[i];
		if (a[i] == b[i]) {
			e.push_back(i);
		}
		if (a[i] == 0 && b[i] == 1) {
			c.push_back(i);
		}
		if (b[i] == 0 && a[i] == 1) {
			d.push_back(i);
		}
	}
	if (cnt % 2 == 1) {
		cout << -1;
		return 0;
	}
	int m1 = c.size();
	int m2 = d.size();
	vector<pair<int, int>>ans;
	if (m1 % 2 == 0) {
		for (int i = 0; i < m1 / 2; i++) {
			ans.push_back({ c[2 * i], c[2 * i + 1] });
		}
		for (int i = 0; i < m2 / 2; i++) {
			ans.push_back({ d[2 * i], d[2 * i + 1] });
		}
	}
	else {
		for (int i = 0; i < m1 / 2; i++) {
			ans.push_back({ c[2 * i], c[2 * i + 1] });
		}
		for (int i = 0; i < m2 / 2; i++) {
			ans.push_back({ d[2 * i], d[2 * i + 1] });
		}
		ans.push_back({ c[m1 - 1], c[m1 - 1] });
		ans.push_back({ d[m2 - 1], c[m1 - 1] });
		
	}
	cout << (int)ans.size() << '\n';
	for (auto u : ans) {
		cout << u.first + 1 << " " << u.second + 1 << '\n';
	}
	return 0;
}