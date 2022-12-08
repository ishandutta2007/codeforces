#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> rem(2510);
int xc[2510];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	
	for (int i = 0; i <= 2500; i++) {
		xc[i] = 0;
	}
	
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		// cout << "1:   " << ans << endl; 
		for (int j = 1; j <= i; j++) {
			int cur = i^j;
			if (cur <= n) xc[cur]++;
			if (i+j <= n) rem[i+j].push_back(cur);
		}
		// cout << "2:    " << ans << endl;
		for (int j = 0; j < rem[i].size(); j++) {
			int k = rem[i][j];
			xc[k]--;
		}
		// cout << "i:   " << i << "   " << xc[i] <<  "   " << ans ;
		ans += xc[i];
		// cout << ":   " << ans << endl;
	}
	cout << ans << endl;
	cin >> ans;
}