#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int k;
	cin >> k;
	if (k > 36) {
		cout << -1 << endl;
	}
	else {
		for (int i = 0; i < k/2; i++) {
			cout << 8;
		}
		if (k & 1) cout << 6;
		cout << endl;
	}
	cin >> k;
}