#include <bits/stdc++.h>

using namespace std;

bool state[205][205][205]; //a little more just in case
#define tii tuple<int, int, int>


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int gc = 0, bc = 0, rc = 0;
	string s;
	cin >> s;
	for (int i = 0; i <= 204; i++) {
		for (int j = 0; j <= 204; j++) {
			for (int k = 0; k <= 204; k++) {
				state[i][j][k] = false;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (s[i] == 'R') rc++;
		if (s[i] == 'G') gc++;
		if (s[i] == 'B') bc++;
	}
	state[rc][gc][bc] = true;
	
	queue<tii> sc; 
	sc.push(tii(rc, gc, bc));
	int x, y, z;
	while (!sc.empty()) {
		tii cur = sc.front(); sc.pop();
		x = get<0>(cur);
		y = get<1>(cur);
		z = get<2>(cur);
		if (x >= 2 && !state[x-1][y][z]) {
			state[x-1][y][z] = true;
			sc.push(tii(x-1, y, z));
		}
		if (y >= 2 && !state[x][y-1][z]) {
			state[x][y-1][z] = true;
			sc.push(tii(x, y-1, z));
		}
		if (z >= 2 && !state[x][y][z-1]) {
			state[x][y][z-1] = true;
			sc.push(tii(x, y, z-1));
		}
		if (x >= 1 && y >= 1 && !state[x-1][y-1][z+1]) {
			state[x-1][y-1][z+1] = true;
			sc.push(tii(x-1, y-1, z+1));
		}
		if (y >= 1 && z >= 1 && !state[x+1][y-1][z-1]) {
			state[x+1][y-1][z-1] = true;
			sc.push(tii(x+1, y-1, z-1));
		}
		if (x >= 1 && z >= 1 && !state[x-1][y+1][z-1]) {
			state[x-1][y+1][z-1] = true;
			sc.push(tii(x-1, y+1, z-1));
		}
	}

	if (state[0][0][1]) cout << "B";
	if (state[0][1][0]) cout << "G";
	if (state[1][0][0]) cout << "R";
	
	
	cout << endl;
	cin >> n;
}