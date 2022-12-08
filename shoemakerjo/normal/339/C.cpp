#include <bits/stdc++.h>

#define pii pair<int, int>

using namespace std;

int main() {
	vector<int> weights;
	string line;
	cin >> line;
	for (int i = 0; i < line.length(); i++) {
		if (line[i] == '1') {
			weights.push_back(i+1);
		}
	}
	int m; cin >> m;
	int sz = weights.size();
	bool diff[m+1][sz][11];
	pii prev[m+1][sz][11];
	for (int i = 0; i < sz; i++) {
	
		for (int j = 0; j <= 10; j++) {
			diff[1][i][j] = false;
			prev[1][i][j] = pii(-1, -1);
		}
		diff[1][i][weights[i]] = true;
		
	}
	for (int i = 2; i <= m; i++) {
		for (int j = 0; j < sz; j++) {
			diff[i][j][0] = false;
			prev[i][j][0] = pii(-1, -1);
			for (int q = 1; q <= 10; q++) {
				diff[i][j][q] = false;
				prev[i][j][q] = pii(-1, -1);
				int des = weights[j] - q;
				if (des > 10 || des < 0) continue;
				for (int k = 0; k < sz; k++) {
					if (k == j) continue;
					if (!diff[i-1][k][des]) continue;
					diff[i][j][q] = true;
					prev[i][j][q] = pii(k, des);
				}
				// if (diff[i][j][q]) {
				// 	cout << i << " " << j << " " << q << " " << prev[i][j][q].first
				// 	<< " " << prev[i][j][q].second <<  endl;
				// }
			}

			
			// cout << i << " " << j << " " << prev[i][j] << endl;
		}

	}
	int cs = -1;
	int spot = m;
	int we = -1;
	for (int i = 0; i < sz; i++) {
		for (int j = 0; j <= 10; j++) {
			if (diff[m][i][j]) {
				cs = i;
				we = j;
			}
		}
		
	}
	if (cs == -1) {
		cout << "NO\n";
	}
	else {
		cout << "YES\n";
		vector<int> ans;
		
		while (spot != 0) {
			// cout << spot << " " << weights[cs] << endl;
			ans.push_back(weights[cs]);
			pii tempo = prev[spot][cs][we];
			cs = tempo.first;
			we = tempo.second;
			spot--;
		}
		reverse(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++) {
			if (i > 0) cout << " ";
			cout << ans[i];
		}
	}
	// cin >> m;
}