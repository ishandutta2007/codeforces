#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, x;
	cin >> n >> x;
	int cur;
	int ans = 0;
	// vector<int> nums
	bool in[101];
	for (int i = 0; i <= 100; i++) {
		in[i] = false;
	}
	for (int i = 0; i < n; i++) {
		cin >> cur;
		in[cur] = true;
	}
	for (int i = 0; i < x; i++) {
		if (!in[i]) ans++;
	}
	if (in[x]) ans++;
	cout << ans << endl;
	// cin >> n;
}