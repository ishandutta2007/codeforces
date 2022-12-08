#include <bits/stdc++.h>

using namespace std;

double prob[1001][1001][2]; //0 is for princess, 1 is for dragon
bool vis[1001][1001][2];

double recurse(int w, int b, int pers) {
	if (w < 0 || b < 0) return 0.0;
	if (vis[w][b][pers]) {
		return prob[w][b][pers];
	}
	vis[w][b][pers] = true;
	if (w == 0) {
		prob[w][b][pers] = 0;
		return 0.0;
	}
	if (pers == 0) {
		if (b == 0) {
			prob[w][b][pers] = 1.0;
			return 1.0;
		}
		double pwin = w/(w+b+0.0);
		// cout << "pwin: " << pwin << endl;
		pwin += (1.0-pwin)*(recurse(w, b-1, 1));
		prob[w][b][pers] = pwin;
		return pwin;
	}
	else { //dragon
		if (w+b <= 2) {
			prob[w][b][pers] = 0.0;
			return 0.0;
		}
		double pwin = 0.0;
		double notdone = (b/(w+b+0.0));
		// cout << "nd " << notdone << endl;
		pwin += notdone*(w/(w+b-1.0))*recurse(w-1, b-1, 0);
		pwin += notdone*((b-1.0)/(w+b-1.0))*recurse(w, b-2, 0);
		// cout << "pw: " << pwin << endl;
		prob[w][b][pers] = pwin;
		return pwin;
	}
}

int main() {
	int w, b;
	cin >> w >> b;
	
	for (int i = 0; i <= w; i++) {
		for (int j = 0; j <= b; j++) {
			vis[i][j][0] = vis[i][j][1] = false;
		}
	}
	double ans = recurse(w, b, 0);
	cout << fixed << setprecision(15);
	cout << ans << endl;
	// cin >> ans;

}