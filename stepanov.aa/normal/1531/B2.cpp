#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <set>


using namespace std;


#define ll long long
#define all(a) a.begin(), a.end()
#define pb push_back


int n;
vector<pair<int, int>> a;
map<int, ll> cnt1;
map<pair<int, int>, ll> cnt2;


int32_t main() {
	cin >> n;
	ll res = 0;
	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		if (x > y) {
			swap(x, y);
		}
		pair<int, int> k(x, y);
		if (x == y) {
			cnt1[x] += 1;
		}
		else {
			cnt1[x] += 1;
			cnt1[y] += 1;
			cnt2[k] += 1;
		}
	}
	for (auto& p : cnt1) {
		res += p.second * (p.second - 1) / 2;
	}
	for (auto& p : cnt2) {
		res -= p.second * (p.second - 1) / 2;
	}
	cout << res << "\n";
	return 0;
}