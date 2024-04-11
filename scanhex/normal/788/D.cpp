#include <iostream>
#include <random>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using nagai = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int mx = 100000000;
	int cnt = 10000;
	int step = 2 * mx / cnt;
	vector<pair<int,int>> dst;
	int mxd = 0, mxi = -1, mxj = -1;
	mt19937 rnd(239);
	for(int it = 0; it < cnt; ++it) { 
		int i = -mx + rnd() % (2 * mx);
		int j = -mx + rnd() % (2 * mx);
//	for(int i = -mx; i < mx; i += step) {
		cout << 0 << ' ' << i << ' ' << j << '\n';
		cout.flush();
		int d;
		cin >> d;
		if (d == -1) return 0;
		dst.emplace_back(d, i);
		if (d > mxd) mxd = d, mxi = i, mxj = j;
	}
	vector<int> rx, ry;
	int cur = -mx;
	int step1 = 2 * mx / 50000;
	vector<pair<int, int>> bounds;
	while (cur < mx) {
		cur += step1;
		if (cur > mx) break;
		cout << 0 << ' ' << cur << ' ' << mxj << '\n';
		cout.flush();
		int d; 
		cin >> d;
		if (d == -1) return 0;
		bounds.emplace_back(cur - d + 1, cur + d - 1);
	}
	sort(bounds.begin(), bounds.end());
	cur = -mx;
	while(cur <= mx) {
		cout << 0 << ' ' << cur << ' ' << mxj << '\n';
		cout.flush();
		int d;
		cin >> d;
		if (d == -1) return 0;
		if (d == 0) rx.push_back(cur);
		if (cur == mx) break;
		cur += max(1, min(d, mx - cur));
		while (true) {
			int rofl = lower_bound(bounds.begin(), bounds.end(), make_pair(cur, mx + 1)) - bounds.begin() -  1;
			if (rofl >= 0 && bounds[rofl].second >= cur) 
				cur = bounds[rofl].second + 1;
			else
				break;
		}
	}
	cur = -mx;
	bounds.clear();
	while (cur < mx) {
		cur += step1;
		if (cur > mx) break;
		cout << 0 << ' ' << mxi << ' ' << cur << '\n';
		cout.flush();
		int d; 
		cin >> d;
		if (d == -1) return 0;
		bounds.emplace_back(cur - d + 1, cur + d - 1);
	}
	sort(bounds.begin(), bounds.end());
	cur = -mx;
	while(cur <= mx) {
		cout << 0 << ' ' << mxi << ' ' << cur << '\n';
		cout.flush();
		int d;
		cin >> d;
		if (d == -1) return 0;
		if (d == 0) ry.push_back(cur);
		if (cur == mx) break;
		cur += max(1, min(d, mx - cur));
		while (true) {
			int rofl = lower_bound(bounds.begin(), bounds.end(), make_pair(cur, mx + 1)) - bounds.begin() -  1;
			if (rofl >= 0 && bounds[rofl].second >= cur) 
				cur = bounds[rofl].second + 1;
			else
				break;
		}
	}
	cout << 1 << ' ' << rx.size() << ' ' << ry.size() << '\n';
	for(auto x : rx) cout << x << ' ';
	cout << '\n';
	for(auto x : ry) cout << x << ' ';
	cout << '\n';
}