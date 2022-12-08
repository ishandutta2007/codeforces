#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int co1[4][2];
	int co2[4][2];
	int sx = 1234567890, sy = 1234567890;
	int lx = -1234567890, ly = -1234567890;
	for (int i = 0; i  < 4; i++) {
		cin >> co1[i][0] >> co1[i][1];
		sx = min(sx, co1[i][0]);
		lx = max(lx, co1[i][0]);
		sy = min(sy, co1[i][1]);
		ly = max(ly, co1[i][1]);

	}
	for (int i = 0; i < 4; i++) {
		cin >> co2[i][0] >> co2[i][1];
	}
	bool ans = false;
	//above does intersection of sides
	for (int i = 0; i < 4; i++) {
		for (int  j = i+1; j < 4; j++) {
			if (j - i == 2) continue;
			int slope = (co2[j][1] - co2[i][1]) / (co2[j][0] - co2[i][0]);
			int b = co2[i][1] - slope*co2[i][0];
			int cx = co2[i][0];
			int cy = co2[i][1];
			while (cx <= co2[j][0]) {
				if (cx >= sx && cx <= lx && cy >= sy && cy <= ly) ans = true;
				cx++;
				cy += slope;
			}
			cx = co2[j][0];
			cy = co2[j][1];
			while (cx <= co2[i][0]) {
				if (cx >= sx && cx <= lx && cy >= sy && cy <= ly) ans = true;
				cx++;
				cy += slope;
			}
		}
	}
	int mx = 0;
	int my = 0;
	for (int i = 0; i < 4; i++) {
		mx += co2[i][0];
		my += co2[i][1];
	}
	mx /= 4;
	my /= 4;
	int d1 = abs(co2[0][0] - mx) + abs(co2[0][1] - my);
	int d2 = abs(sx - mx) + abs(sy - my);
	if (d2 <= d1) ans = true;


	if (ans) cout << "Yes" << endl;
	else cout << "No" << endl;
	cin >> ans;
}