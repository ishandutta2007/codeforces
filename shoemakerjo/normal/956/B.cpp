#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	double ans = -1.0;
	int n, U;
	cin >> n >> U;
	vector<int> energy;
	int cur;
	for (int i = 0; i < n; i++) {
		cin >> cur;
		energy.push_back(cur);
	}

	for (int i = 1; i < n; i++) {
		int ind = upper_bound(energy.begin(), energy.end(), energy[i-1]+U) - energy.begin();
		--ind;
		if (ind <= i) continue;
		ans = max(ans, (energy[ind]-energy[i]-0.0)/(energy[ind]-energy[i-1]-0.0));

	}


	if (ans < 0) {
		cout << -1 << endl;
	}
	else cout << fixed << setprecision(15) << ans << endl;
	cin >> n;
}