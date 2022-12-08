#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	if (k == 0 || k == n) {
		cout << 0 << " ";
	}
	else cout << 1 << " ";
	int ans = 0;
	int num3 = min(n/3, k);
	ans = num3*2;
	k -= num3;
	if (n%3 == 1) {
		if (k > 0) k--;
	}
	if (n%3 == 2) {
		if (k > 0) {
			ans++;
			k--;
		}
	}
	ans -= k;
	cout << ans << endl;
	cin >> ans;
}