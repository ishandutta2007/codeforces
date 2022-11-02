#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int>a(n);
	vector<int>pref(n);
	for (int i = 0; i < n; i++) {
		char tmp;
		cin >> tmp;
		if (tmp == 'R') {
			a[i] = 2;
		}
		else {
			a[i] = 1;
		}
	}
	int cnt1 = 0;
	int cnt2 = 0;
	pref[0] = a[0];
	if (pref[0] == 1) {
		cnt1 = 1;
	}
	else {
		cnt2 = 1;
	}
	for (int i = 1; i < n; i++) {
		if (a[i] == 1) {
			cnt1 += 1;
		}
		else {
			cnt2 += 1;
		}
		pref[i] = pref[i - 1];
		if (cnt1 > cnt2) {
			pref[i] = 1;
		}
		if (cnt2 > cnt1) {
			pref[i] = 2;
		}
	}
	int ans = 0;
	for (int i = 1; i < n; i++) {
		if (pref[i] != pref[i - 1]) {
			ans++;
		}
	}
	cout << ans;
	return 0;
}