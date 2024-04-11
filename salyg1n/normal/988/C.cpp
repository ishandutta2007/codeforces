#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<vector<ll>> a(n);
	for (auto& i : a) {
		int m;
		cin >> m;
		i.resize(m);
		for (auto& j : i)
			cin >> j;
	}
	vector<pair<ll, pair<ll, ll>>> b;
	for (int i = 0; i < n; ++i) {
		ll sum = 0;
		for (auto j : a[i]) {
			sum += j;
		}
		for (int j = 0; j < a[i].size(); ++j) {
			b.push_back({ sum - a[i][j], {i, j} });
		}
	}
	sort(b.begin(), b.end());
	for (auto i : b) {
		pair<ll, pair<ll, ll>> tmp1, tmp2;
		int l = -1, r = b.size();
		while (r - l > 1) {
			int m = (r + l) / 2;
			pair<ll, ll> tmp3 = { b[m].first, b[m].second.first }, tmp4 = { i.first, i.second.first };
			if (tmp3 >= tmp4)
				r = m;
			else
				l = m;
		}
		if (l == -1)
			tmp1.first = 1e18;
		else
			tmp1 = b[l];
		l = -1, r = b.size();
		while (r - l > 1) {
			int m = (r + l) / 2;
			pair<ll, ll> tmp3 = { b[m].first, b[m].second.first }, tmp4 = { i.first, i.second.first };
			if (tmp3 > tmp4)
				r = m;
			else
				l = m;
		}
		if (r == b.size())
			tmp2.first = 1e18;
		else
			tmp2 = b[r];
		if (tmp1.first == i.first) {
			cout << "YES\n" << tmp1.second.first + 1 << " " << tmp1.second.second + 1 << "\n" << i.second.first + 1 << " " << i.second.second + 1;
			return 0;
		}
		if (tmp2.first == i.first) {
			cout << "YES\n" << tmp2.second.first + 1 << " " << tmp2.second.second + 1 << "\n" << i.second.first + 1 << " " << i.second.second + 1;
			return 0;
		}
	}
	cout << "NO";
}