#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int cur;
	int ans = 0;
	const int mil = 1000000;
	while (n--) {
		cin >> cur;
		ans = max(ans, min(mil-cur, cur-1));
	}
	cout << ans << endl;
	cin >> n;
}