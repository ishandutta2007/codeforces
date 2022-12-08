#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	string line;
	int o1[4];
	int o2[4]; //cost of doing each type

	int ans = 1000000000;
	//loop through all pairs of being in o1

	for (int ind = 0; ind < 4; ind++) {
		o1[ind] = o2[ind] = 0;
		for (int i = 0; i < n; i++) {
			cin >> line;
			for (int j = 0; j < n; j++) {
				if (line[j] == '1') {
					if ((i+j)%2 == 1) {
						o1[ind]++;
					}
					else {
						o2[ind]++;
					}
				}
				else {
					if ((i+j)%2 == 1) {
						o2[ind]++;
					}
					else {
						o1[ind]++;
					}
				}
			}
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = i+1; j < 4; j++) {
			int cans = o1[i]+o1[j];
			for (int k = 0; k < 4; k++) {
				if (k == i || k == j) continue;
				cans += o2[k];
			}
			ans = min(ans, cans);
		}
	}
	cout << ans << endl;
	cin >> n;

}