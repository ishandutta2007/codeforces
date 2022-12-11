// Codeforces - mycopka

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>

using namespace std;

typedef int64_t ll;

int main() {
	ll n;
	cin >> n;
	vector<ll> a(n);
	vector<ll> b(n);
	for (ll i = 0; i < n; ++i) {
		cin >> a[i];
		b[i] = a[i] - i;
	}
	map<ll, ll> dp;
	for (ll i = 0; i < n; ++i) {
		dp[b[i]] += a[i];
	}
	ll result = 0;
	for (auto i : dp) {
		result = max(i.second, result);
	}
	cout << result << endl;
	return 0;
}