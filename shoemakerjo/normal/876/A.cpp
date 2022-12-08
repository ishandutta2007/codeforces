#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	int a, b, c;
	cin >> a >> b >> c;
	if (n == 1) {
		cout << 0 << endl;
	}
	else if (n == 2) {
		cout << min(a, b) << endl;
	}
	else {
		int ans = a+(n-2)*(min(a, c));
		ans = min(ans, b+(n-2)*(min(b, c)));
		cout << ans << endl;
	}
	// cin >> n;

}