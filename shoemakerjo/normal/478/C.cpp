#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	int r, g, b;
	cin >> r >> g >> b;
	vector<ll> nums;
	nums.push_back(r);
	nums.push_back(g);
	nums.push_back(b);
	ll ans = 0;
	sort(nums.begin(), nums.end());
	ll n1 = nums[0];
	ll n2=  nums[1];
	ll n3 = nums[2];
		
	ll sub1 = n3-n2;
	ll sub2 = n2-n1;
	// cout << sub1 << " - " << sub2 << endl;
	if (sub1 < sub2) {
		ll num = n2 - sub1;
		ans += sub1;
		ll ct = (num-n1)/3;
		ll temp = num - ct*3;
		ans += 2*ct;
		if (temp == n1) {
			ans += temp;
		}
		else if (temp == n1+1) {
			ans += n1;
		}
		else {
			ans += n1 + 1;
		}
	}
	else {
		// cout << "here\n";
		ll num = n3 - sub2*2;
		ans += sub2;
		if (n1*4 <= num) {
			ans += n1*2;
		}
		else {
			ll x = (num-n1)/3;
			// cout << "x:  " << x << endl;
			ans += 2*x + (n1-x);
		}
	}
	cout << ans << endl;
	cin >> r;
}