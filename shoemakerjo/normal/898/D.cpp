#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	int cur;
	int mil = 1000000;
	bool ring[mil];
	for (int i = 0; i <= mil; i++) {
		ring[i] = false;
	}
	for (int i = 0; i < n; i++) {
		cin >> cur;
		ring[cur] = true;
	}
	int ans = 0;
	deque<int> inplay;
	for (int i = 1; i <= m-1; i++) {
		if (ring[i]) {
			inplay.push_back(i);
		}
	}
	for (int i = m; i <= mil; i++) {
		if (ring[i]) {
			inplay.push_back(i);
		}
		
		if (inplay.size() != 0 && i-m == inplay.front()) {
			inplay.pop_front();
		}
		
		while (inplay.size() >= k) {
			// cout << "sz  " << inplay.size() << "  " << k << endl;
			inplay.pop_back();
			ans++;
		} 
	}
	cout << ans << endl;
	cin >> ans;
}