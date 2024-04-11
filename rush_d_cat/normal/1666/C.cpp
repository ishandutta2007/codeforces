#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);

	vector<int> x(3), y(3);
	vector<int> xx, yy;
	for (int i = 0; i < 3; i ++)
		cin >> x[i] >> y[i];
	
	xx = x, yy = y;

	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	
	vector<vector<int> > ans;
	ans.push_back({x[0],y[1],x[2],y[1]});
	for (int i = 0; i < 3; i ++) {
		if (yy[i] != y[1]) {
			ans.push_back({xx[i],yy[i],xx[i],y[1]});
		}
	}
	cout << ans.size() << "\n";
	for (auto p: ans) {
		for (int i = 0; i < 4; i ++) cout << p[i] << " ";
		cout << "\n";
	}
}