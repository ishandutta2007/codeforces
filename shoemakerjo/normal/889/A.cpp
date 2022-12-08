#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	bool paired[n+1];
	int ans = 1;
	for (int i = 0; i <= n; i++) {
		paired[i] = false;
	}
	int val = 0;
	for (int i = 1; i <= n; i++) {
		cin >> val;
		if (paired[val]) ans++;
		else paired[val] = true;
	}
	cout << ans << endl;
	// cin >> n;
}