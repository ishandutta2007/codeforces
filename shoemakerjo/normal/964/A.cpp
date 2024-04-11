#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	if (n == 1) {
		cout << 1 << endl;
	}
	else {
		int ans = n/2 + 1;
		cout << ans << endl;
	}
	cin >> n;
}