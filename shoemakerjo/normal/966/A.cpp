#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, cl, ce, v;
	cin >> n >> m >> cl >> ce >> v;
	vector<int> stairs; //come sorted
	vector<int> elevators; 
	int cur;
	for (int i = 0; i < cl; i++) {
		cin >> cur;
		stairs.push_back(cur);
	}
	for (int i = 0; i < ce; i++) {
		cin >> cur;
		elevators.push_back(cur);
	}
	int q;
	cin >> q;
	int x1, y1, x2, y2;
	while (q--) {
		int ans = 1000000000; //10^9
		cin >> x1 >> y1 >> x2 >> y2;
		int vert = abs(x2-x1);
		int horiz = abs(y1-y2);
		int ymax = max(y1, y2);
		int ymin = min(y1, y2);
		if (vert == 0) {
			ans = min(ans, abs(y2-y1));
		}
		int nx1 = lower_bound(stairs.begin(), stairs.end(), ymax) - stairs.begin();
		int nx2 = lower_bound(stairs.begin(), stairs.end(), ymin) - stairs.begin();
		if (nx1 != nx2) {
			ans = min(ans, horiz + vert);
		}
		else {
			if (nx1 != stairs.size()) {
				ans = min(ans, horiz + vert + 2*(stairs[nx1] - ymax));
			}
			if (nx2 != 0) {
				--nx2;
				ans = min(ans, horiz + vert + 2*(ymin-stairs[nx2]));
			}
		}
		nx1 = lower_bound(elevators.begin(), elevators.end(), ymax) - elevators.begin();
		nx2 = lower_bound(elevators.begin(), elevators.end(), ymin) - elevators.begin();
		int vtime = (vert+v-1)/v;
		if (nx1 != nx2) {
			ans = min(ans, horiz + vtime);
		}
		else {
			if (nx1 != elevators.size()) {
				ans = min(ans, horiz + vtime + 2*(elevators[nx1] - ymax));
			}
			if (nx2 != 0) {
				--nx2;
				ans = min(ans, horiz + vtime + 2*(ymin-elevators[nx2]));
			}
		}
		// cout << "ans: ";
		cout << ans << endl;
	}
	cin >> q;
}