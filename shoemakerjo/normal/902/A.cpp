#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int a[n], b[n];
	bool reach[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
		reach[i] = false;
	}
	reach[0] = false;
	if (a[0] == 0) reach[0] = true;
	bool done = false;
	for (int i = 0; i < n; i++) {
		if (!reach[i]) continue;
		for (int j = i+1; j < n; j++) {
			if (b[i] >= a[j]) {
				reach[j] = true;
			}
		}
		if (a[i] <= m &&  b[i] >= m) done = true;
	}
	string ans = done ? "YES" : "NO";
	cout << ans << endl;
	cin >> n;
}