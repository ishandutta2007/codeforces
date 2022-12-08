#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	int cur;
	int oc = 0;
	int tc = 0;
	for (int i = 0; i < n; i++) {
		cin >> cur;
		if (cur == 1) oc++;
		else tc++;
	}
	int ans = 0;
	int rm = min(tc, oc);
	ans += rm;
	oc -= rm;
	ans += oc/3;
	cout << ans << endl;
	cin >> ans;
}