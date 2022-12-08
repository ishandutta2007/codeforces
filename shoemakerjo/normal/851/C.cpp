#include <bits/stdc++.h>

#define PI 3.14159265
#define maxn 1000
#define ld long double
using namespace std;
int nums[maxn][5];

int getdist(int a, int b) {
	int ans = 0;
	for (int i = 0; i < 5; i++) {
		ans += (nums[b][i]-nums[a][i])*(nums[b][i]-nums[a][i]);
	}
	// cout << "ans:   " << ans << "   " << a << " " << b << " " << c <<  endl;
	return ans;

}

int main() {

	int n;
	cin >> n;
	// int nums[n][5];
	for (int i = 0; i < n; i++) {
		cin >> nums[i][0] >> nums[i][1] >> nums[i][2] >> nums[i][3] >> nums[i][4];

	}
	// int good = -1;
	bool found = false;
	bool poss[n];
	for (int i = 0; i < n; i++) {
		poss[i] = true;
	}
	ld between;
	ld x;
	ld y;
	ld angle;
	vector<int> good;
	for (int i = 0; i < n; i++) {
		if (!poss[i]) continue;
		for (int j = i+1; j < n; j++) {
			if (!poss[i]) break;
			for (int k = j+1; k < n; k++) {
				between = getdist(j, k);
				x = getdist(i, j);
				y = getdist(i, k);
				// angle = acos(between/(x*y)) * 180.0 / PI;
				// cout << i << " " << j << " " << k << " " << angle << endl;
				if (x+y > between) {
					poss[i] = false;
					// cout << i << " " << j << " " << k << endl;
					break;
				}
				else {
					// cout << i << " " << j << " " << k << endl;
					poss[j] = false;
					poss[k] = false;
				}

			}
		}
		if (poss[i]) {
			found = true;
			good.push_back(i+1);
		}
	}
	
	if (found) {
		// cout << good << endl;
		vector<int> g2;
		for (int q = 0; q < good.size(); q++) {
			found = true;
			for (int i = 0; i < n; i++) {
				if (i == good[q]-1) continue;
				for (int j = i+1; j < n; j++) {
					if (j == good[q]-1) continue;
					between = getdist(i, j);
					x = getdist(good[q]-1, j);
					y = getdist(good[q]-1, i);
					// angle = acos(between/(x*y)) * 180.0 / PI;
					// cout << i << " " << j << " " << k << " " << angle << endl;
					if (x+y > between) {
						// poss[i] = false;
						found = false;
						break;
					}
				}
				
			}
			if (found) g2.push_back(good[q]);
		}
		good = g2;
		sort(good.begin(), good.end());
	}
	if (n == 2) {
		cout << 2 << endl << 1 << endl << 2 << endl;
	}
	else if (good.size() > 0) cout << 1 << endl << good[0] << endl;
	else cout << 0 << endl;
	// cin >> x;
}