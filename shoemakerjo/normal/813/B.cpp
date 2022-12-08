#include <iostream>
#include <cmath>
#include <vector>
#include <stdio.h>
#include <algorithm>

#define ll long long
using namespace std;

int main() {

	ll x = 0;
	ll y = 0;
	ll l = 0;
	ll r = 0;
	cin >> x >> y >> l >> r;
	vector<ll> xs;

	ll cur = 1;

	while (cur <= r) {
//		cout << cur << " ";
		xs.push_back(cur);
		if (cur > r/x) break;
		cur = cur*x;
		if (cur < 0) break;
		if (x==0 || x ==1 ) break;
	}


	vector<ll> ys;

	cur = 1;
	while (cur <= r) {
		ys.push_back(cur);
		if (cur > r/y) break;
		cur = cur*y;
//		cout << cur << " ";

		if (cur < 0 )  break;
		if (y==0 || y==1) break;
	}

	vector<ll> nums;
	for (int i = 0; i < xs.size(); ++i) {
		for (int j = 0; j < ys.size(); ++j) {
			cur = xs[i]+ys[j];
			if (l <= cur && cur <= r) {
				nums.push_back(cur);
			}
		}
	}
	ll ma = 0;
	nums.push_back(l-1);
	nums.push_back(r+1);
	sort(nums.begin(), nums.end());

	for (int i = 0; i < nums.size()-1; ++i) {
		ll cur = nums[i+1]-nums[i]-1;
		ma = max(ma, cur);
	}
	cout << ma << '\n';
//	cout << x << endl << y << endl << l << endl << r << endl;
	return 0;
}