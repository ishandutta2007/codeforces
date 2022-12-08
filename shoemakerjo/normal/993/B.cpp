#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	int v[n][2];
	int o[m][2];
	for (int i = 0; i < n; i++) {
		cin >> v[i][0] >> v[i][1];
	}	
	for (int  i = 0; i < m; i++) {
		cin >> o[i][0] >> o[i][1];
	}
	bool poss[10];
	fill(poss, poss+10, false);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			//if both are same then they are not possible (exactly one must be the same)
			if (v[i][0] == o[j][0] && v[i][1] != o[j][1]) {
				poss[v[i][0]] = true;
			}
			if (v[i][0] == o[j][1] && v[i][1] !=o[j][0]) {
				poss[v[i][0]] = true;
 			}
 			if (v[i][1] == o[j][0] && v[i][0] != o[j][1]) {
 				poss[v[i][1]] = true;
 			}
 			if (v[i][1] == o[j][1] && v[i][0] != o[j][0]) {
 				poss[v[i][1]] = true;
 			}
		}
	}

	int pc = 0;
	int  spot = -1;
	for (int i = 0; i < 10; i++) {
		if(poss[i]) {
			pc++;
			spot = i;
		}
	}
	if (pc == 1) {
		cout << spot << endl;
		cin >> n;
		return 0;
	}
	bool v2 = true;
	for (int i = 0; i < n; i++) {
		bool p1 = false;
		bool p2 = false;
		for (int j = 0; j < m; j++) {
			if (o[j][0] == v[i][0] && o[j][1] == v[i][1]) continue;
			if (o[j][0] == v[i][1] && o[j][1] == v[i][0]) continue;
			if (v[i][0] == o[j][0] || v[i][0] == o[j][1]) p1 = true;
			if (v[i][1] == o[j][0] || v[i][1] == o[j][1]) p2 = true;
		}
		if (p1 && p2) v2 = false;
	}
	for (int i = 0; i < m; i++) {
		bool p1 = false;
		bool p2 = false;
		for (int j = 0; j < n; j++) {
			if (v[j][0] == o[i][0] && v[j][1] == o[i][1]) continue;
			if (v[j][0] == o[i][1] && v[j][1] == o[i][0]) continue;
			if (o[i][0] == v[j][0] || o[i][0] == v[j][1]) p1 = true;
			if (o[i][1] == v[j][0] || o[i][1] == v[j][1]) p2 = true;
		}
		if (p1 && p2) v2 = false;
	}
	if (v2) cout << 0 << endl;
	else cout << -1 << endl;
	cin >> n;
}