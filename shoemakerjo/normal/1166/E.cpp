#include <bits/stdc++.h>

using namespace std;

int m, n;

vector<int> stuff[52];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> m >> n;
	//every day must share with another day
	int s, cur;
	for (int i = 1; i <= m; i++) {
		cin >> s;
		while (s--) {
			cin >> cur;
			stuff[i].push_back(cur);
		}
		sort(stuff[i].begin(), stuff[i].end());
	}
	bool res = true;
	for (int i = 1; i <= m; i++) {
		for (int j = i+1; j <= m; j++) {
			bool cok = false;

			int i1 = 0, i2 = 0;

			while (i1 < stuff[i].size() && i2 < stuff[j].size()) {
				if (stuff[i][i1] == stuff[j][i2]) {
					cok = true;
					break;
				}
				if (stuff[i][i1] < stuff[j][i2]) i1++;
				else i2++;
			}

			if (!cok) {
				res = false;
				break;
			}
		}
	}
	if (res) {
		cout << "possible" << endl;
	}
	else cout << "impossible" << endl;
}