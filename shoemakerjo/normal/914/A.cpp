#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int ans = -2000000;
	int cur;
	for (int i = 0; i < n; i++) {
		cin >> cur;
		bool issquare = false;
		if (cur < 0) issquare = false;
		else {
			for (int j = 0; j <= 1000; j++) {
				if (j*j == cur) issquare = true;
			}
		}
		if (!issquare) ans = max(ans, cur);
	}
	cout << ans << endl;
	cin >> ans;
}