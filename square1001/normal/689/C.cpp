#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <functional>
#pragma warning(disable : 4996)
using namespace std;
typedef long long ll;
ll solve(ll x) {
	ll ret = 0;
	for (int i = 2; 1LL * i * i * i <= x; i++) {
		ret += x / (1LL * i * i * i);
	}
	return ret;
}
ll n;
int main() {
	cin >> n;
	ll l = 0, r = 1LL << 55;
	while (r - l > 1) {
		ll m = (l + r) >> 1;
		if (solve(m) >= n) r = m;
		else l = m;
	}
	if(solve(r) == n) cout << r << endl;
	else cout << -1 << endl;
	return 0;
}