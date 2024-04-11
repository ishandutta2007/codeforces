#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int nums[n+1];
	for (int i = 1; i <= n; i++) {
		cin >> nums[i];
	}
	string stuff;
	cin >> stuff;
	stuff = "0" + stuff;
	int pref[n+1];
	pref[0] = 0;
	for (int i = 1; i <= n; i++) {
		pref[i] = pref[i-1];
		if (stuff[i] == '1') pref[i]++;
	}
	bool ok = true;
	for (int i = 1; i <= n; i++) {
		int mi = min(nums[i], i);
		int ma = max(nums[i], i);
		if (pref[ma-1]-pref[mi-1] != ma-mi) ok = false;
	}

	if (ok) cout << "YES" << endl;
	else cout << "NO" << endl;
	cin >> n;
}