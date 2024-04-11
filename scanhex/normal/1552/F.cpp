#include <bits/stdc++.h>

using namespace std;
using nagai = long long;

const int mod = 998244353;

int mu(int a, int b) {
	 return (nagai) a * b % mod;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<array<nagai, 3>> arr(n);
	for(int i = 0; i < n; ++i) {
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}
	vector<nagai> rofl(n);
	vector<nagai> pref(n + 1);
	nagai res = 0;
	for(int i = 0; i < n; ++i) {
		auto kek = lower_bound(arr.begin(), arr.end(), array<nagai, 3>{arr[i][1], -1, -1}) - arr.begin();
		rofl[i] = arr[i][0] - arr[i][1];
		rofl[i] += pref[i] - pref[kek];
		rofl[i] %= mod;
		if (rofl[i] < 0)
			rofl[i] += mod;
		pref[i + 1] = pref[i] + rofl[i];
		if (arr[i][2]) {
			res += rofl[i];
		}
	}
	cout << (res + arr.back()[0] + 1) % mod << '\n';
  return 0;
}