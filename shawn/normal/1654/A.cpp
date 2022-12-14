#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	int _, n;
	cin >> _;
	while (_ --) {
		cin >> n;
		int mx1 = 0, mx2 = 0;
		for (int x, i = 1; i <= n; i ++) {
			cin >> x;
			if (x > mx1) mx2 = mx1, mx1 = x;
			else if (x > mx2) mx2 = x;
		}
		cout << mx1 + mx2 << "\n";
	}
	return 0;	
}