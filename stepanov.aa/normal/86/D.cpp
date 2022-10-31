#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;


bool comp(pair<pair<int, int>, pair<int, int>> a, pair<pair<int, int>, pair<int, int>> b) {
	if (a.first.second != b.first.second) {
		return a.first.second < b.first.second;
	}
	else {
		return a.second.first < b.second.first;
	}
}


int main() {
	int n, t;
	cin >> n >> t;
	int s = ceil(sqrt(((double)(n))));
	vector<pair<long long, int>> a(n);
	int c = 0;
	int block = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i].first;
		a[i].second = block;
		++c;
		if (c == s) {
			c = 0;
			++block;
		}
	}
	vector<pair<pair<int, int>, pair<int, int>>> asks(t);

	for (int i = 0; i < t; ++i) {
		int l, r;
		cin >> l >> r;
		--l;
		--r;
		asks[i].first.first = l;
		asks[i].first.second = a[l].second;
		asks[i].second.first = r;
		asks[i].second.second = i;
	}

	sort(asks.begin(), asks.end(), comp);

	vector<int> numbers_count(1e6 + 10, 0);
	vector<long long> results(t);
	long long res = 0;
	int l = asks[0].first.first;
	int r = asks[0].second.first;
	for (int i = l; i <= r; ++i) {
		res += ((long long)(numbers_count[a[i].first]) * 2 + 1) * a[i].first;
		++numbers_count[a[i].first];
	}
	results[asks[0].second.second] = res;

	for (int i = 1; i < t; ++i) {
		int new_l = asks[i].first.first;
		int new_r = asks[i].second.first;
		if (l <= new_l) {
			while (l < new_l) {
				res -= ((long long)(numbers_count[a[l].first]) * 2 - 1) * a[l].first;
				--numbers_count[a[l].first];
				++l;
			}
		}
		else {
			while (l > new_l) {
				--l;
				res += ((long long)(numbers_count[a[l].first]) * 2 + 1) * a[l].first;
				++numbers_count[a[l].first];
			}
		}
		if (r <= new_r) {
			while (r < new_r) {
				++r;
				res += ((long long)(numbers_count[a[r].first]) * 2 + 1) * a[r].first;
				++numbers_count[a[r].first];
			}
		}
		else {
			while (r > new_r) {
				res -= ((long long)(numbers_count[a[r].first]) * 2 - 1) * a[r].first;
				--numbers_count[a[r].first];
				--r;
			}
		}
		results[asks[i].second.second] = res;
	}
	for (auto x : results) {
		cout << x << endl;
	}
	return 0;
}

/*
20 8
1 2 1 2 1 2 1 2 1 2 1 2 1 2 1 2 1 2 1 2
4 15
1 2
2 20
7 7
13 18
7 7
3 19
3 8


108
3
277
21
39
21
209
27
*/