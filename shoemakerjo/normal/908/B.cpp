#include <bits/stdc++.h>

using namespace std;

int n, m;
int sx, sy, ex, ey;
char grid[60][60];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	string cur;
	for (int i = 0; i < n; i++) {
		cin >> cur;
		for (int j = 0; j < m; j++) {
			grid[i][j] = cur[j];
			if (cur[j] == 'S') {
				sx = i;
				sy = j;
			}
			if (cur[j] == 'E') {
				ex = i;
				ey = j;
			}
		}
	}
	// cout << "starts   " << sx << " " << sy << " " << ex << "  " << ey << endl;
	string s;
	cin >> s;
	vector<int> dig;
	dig.push_back(1);
	dig.push_back(2);
	dig.push_back(3);
	dig.push_back(4);
	int ans = 0;
	while (1) {
		// cout << dig[0] << " " << dig[1] << " " << dig[2] << " " << dig[3] << endl;
		map<int, int> mp;
		for (int i = 0; i < 4; i++) {
			mp[i] = dig[i];
		}
		// vector<int> ops;
		int cx, cy;
		cx = sx;
		cy = sy;
		bool ok = true;
		bool done = false;
		for (int i = 0; i < s.length(); i++) {
			int op = mp[s[i]-'0'];
			if (op == 1) {
				cx++;
			}
			if (op == 2) {
				cy++;
			}
			if (op == 3) {
				cx--;
			}
			if (op == 4) {
				cy--;
			}
			if (cx < 0 || cy < 0 || cx >= n || cy >= m) {
				ok = false;
				break;
			}
			if (grid[cx][cy] == '#') {
				ok = false;
				break;
			}
			if (grid[cx][cy] == 'E') {
				done = true;
				break;
			}
		}
		
		if (done) ans++;
		if (!next_permutation(dig.begin(), dig.end())) break;
	}
	cout << ans << endl;
	cin >> ans;
}