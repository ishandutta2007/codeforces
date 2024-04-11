#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pll pair<ll, ll>

ll numthree(ll val) {
	ll ans = 0LL;
	while (val%3 == 0LL) {
		ans += 1LL;
		val/=3LL;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<ll> nums;
	vector<pll> stuff;
	ll cur;
	for (int i = 0; i < n; i++) {
		cin >> cur;
		nums.push_back(cur);
		stuff.push_back(pll(0LL-numthree(cur), cur));
	}
	sort(stuff.begin(), stuff.end());
	for (auto v : stuff) {
		cout << v.second << " ";
	}
	cout << endl;
	cin >> n;

}