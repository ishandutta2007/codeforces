#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
const int N = 200000 + 10;
int gcd(int x, int y) {
	return y == 0 ? x : gcd(y, x % y);
}
int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	int t; cin >> t;
	while (t --) {
		int n; cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i ++) cin >> a[i];
		int mn = *min_element(a.begin(), a.end());
		int mx = *max_element(a.begin(), a.end());
		int s = 0;
		for (auto x: a) s = gcd(s, abs(x));
		if (mn < 0) {
			cout << "No" << endl; continue;
		}
		if (mx == 0 && mn == 0) {
			cout << "Yes" << endl;
			for (auto x: a) cout << x << " "; cout << endl; continue;
		}
		if (mx > 0) {
			cout << "Yes" << endl;
			cout << (mx / s + 1) << endl;
			for (int x = 0; x * s <= mx; x ++) {
				cout << x*s << " "; 
			}
			cout << endl;
			continue;
		}

	}	
}