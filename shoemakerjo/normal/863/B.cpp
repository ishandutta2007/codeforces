#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	int weights[2*n];
	for (int i = 0; i < 2*n; i++) {
		cin >> weights[i];
	}
	sort(weights, weights+2*n);
	int ans = 2000000000;
	for (int i = 0; i < 2*n; i++) {
		for (int j = i+1; j < 2*n; j++) {
			vector<int> cur;
			for (int k = 0; k < 2*n; k++) {
				if (k == i || k == j) continue;
				cur.push_back(weights[k]);
			}
			sort(cur.begin(), cur.end());
			int temp = 0;
			for (int i = 0; i < 2*n-2; i+=2) {
				temp += cur[i+1]-cur[i];
			}
			ans = min(ans, temp);
			
		}
	}
	cout << ans << endl;
	// cin >> ans;
}