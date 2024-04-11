#include <bits/stdc++.h>

using namespace std;

int gs[300]; //group size
int gv[300]; //group val

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	fill(gs, gs+300, -1);
	fill(gv, gv+300, -1);
	cin >> n >> k;
	int cur;
	for (int i = 0; i < n; i++) {
		cin >> cur;
		if (gv[cur] != -1) {
			cout << gv[cur] << " ";
			continue;
		}
		for (int j = cur-1; j >= 0; j--) {
			if (gs[j] != -1) {
				if (cur - j + gs[j] <= k) {
					gs[cur] = gs[j] + cur-j;
					for (int l = j; l <= cur; l++) {
						gv[l] = gv[j];
					}
					break;
				}
				else {
					if (cur-j <= k) {
						for (int l = j+1; l <= cur; l++) {
							gv[l] = j+1;
						}
						gs[cur] = cur-j;
					}
					break;
				}
			}
		}
		if (gs[cur] == -1) {
			int pv = max(0, cur-k+1);
			gs[cur] = cur-pv+1;
			for (int j = pv; j <= cur; j++) {
				gv[j] = pv;
			}
		}

		cout << gv[cur] << " ";
	}
	cout << endl;
	cin >> n;

}