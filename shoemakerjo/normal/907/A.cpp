#include <bits/stdc++.h>

using namespace std;

int main() {
	int v1, v2, v3, vm;
	cin >> v1 >> v2 >> v3 >> vm;
	int ans = -1;
	for (int i = v3; i <= 2*v3; i++) {
		if (i >= vm && vm*2 >= i) {
			ans = i;
		}
	}
	if (ans == -1 || vm >= v1 || vm >= v2) {
		cout << -1 << endl;
	}
	else {
		cout << 2*v1 << " " << 2*v2 << " " << ans << endl;
	}
	cin >> v1;
}