#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	priority_queue<ll, vector<ll>, greater<ll>> nums;
	ll cur;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> cur;
		nums.push(cur);
	}
	ll ans = 0LL;
	while (nums.size() > 0) {
		if (nums.size() == 1) {
			break;
		}
		if (nums.size() == 2) {
			ll tp = nums.top(); nums.pop();
			tp += nums.top(); nums.pop();
			nums.push(tp);
			ans += tp;
		}
		else {
			if (nums.size() % 2 == 1) {
				ll tp = nums.top(); nums.pop();
				tp += nums.top(); nums.pop();
				tp += nums.top(); nums.pop();
				nums.push(tp);
				ans += tp;
			}
			else {
				nums.push(0);
			}
		}
	}
	cout << ans << endl;
	cin >> ans;

}