#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	int ans = k;
	int cur;
	while (n--) {
		cin >> cur;
		if (k%cur == 0) {
			ans = min(ans, k/cur);
		}
	}
	cout << ans << endl;
	cin >> n;
}