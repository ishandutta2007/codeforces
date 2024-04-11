#include <bits/stdc++.h>

using namespace std;
#define ll long long

int aplay[3][3];
int bplay[3][3];
int cyc = 0;
int aga = 0;
int bga = 0;
int ag, bg;

void rec(int a, int b) {
	cyc++;
	if (a == 2 && b == 1 || a == 1 && b == 0 || a == 0 && b == 2) aga+=1LL;
	else if (a != b) bga += 1LL;
	if (a == ag && b == bg) return;
	rec(aplay[a][b], bplay[a][b]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll k;
	int a, b;
	cin >> k >> a >> b;
	a--; b--;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> aplay[i][j];
			aplay[i][j]--;
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> bplay[i][j];
			bplay[i][j]--;
		}
	}
	bool seen[3][3];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			seen[i][j] = false;
		}
	}
	ll ct = 1LL;
	ll awin = 0LL;
	ll bwin = 0LL;
	if (a == 2 && b == 1 || a == 1 && b == 0 || a == 0 && b == 2) awin+=1LL;
	else if (a != b) bwin += 1LL;
	while (ct < k) {
		ct += 1LL;
		int ac = a;
		int bc = b;
		a = aplay[ac][bc];
		b = bplay[ac][bc];
		if (a == 2 && b == 1 || a == 1 && b == 0 || a == 0 && b == 2) awin+=1LL;
		else if (a != b) bwin += 1LL;
		if (seen[a][b]) {
			// cout << "wins  " << awin << " - " << bwin << endl;
			ag = a;
			bg = b;
			rec(aplay[a][b], bplay[a][b]);
			ll mov = (k-ct)/(cyc+0LL);
			ct += cyc*1LL*mov;
			awin += aga*1LL*mov;
			bwin += bga*1LL*mov;
			// cout << "cyc  " << cyc << "  " << a <<
			//  "," << b << "  " << ag << "," << bg << endl;
			// cout << aga << " - " << bga << endl;

			break;
		}
		seen[a][b] = true;
	}
	while (ct < k) {
		ct += 1LL;
		int ac = a;
		int bc = b;
		a = aplay[ac][bc];
		b = bplay[ac][bc];
		if (a == 2 && b == 1 || a == 1 && b == 0 || a == 0 && b == 2) awin+=1LL;
		else if (a != b) bwin += 1LL;
		
	}
	cout << awin << " " << bwin << endl;
	cin >> ct;
}