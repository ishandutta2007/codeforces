#include <bits/stdc++.h>

using namespace std;
// #define endl '\n'
int g[1000010];
int pref[1000010][10];

void precomp() {
	for (int i = 1; i <= 9; i++) {
		g[i] = i;
	}
	g[0] = 0;
	for (int i = 10; i <= 1000000; i++) {
		int prod = 1;
		int cur= i;
		while (cur > 0) {
			if (cur%10 != 0) prod *= (cur%10);
			cur /= 10;
		}
		// if (prod > i) cout << "BAD" << endl;
		g[i] = g[prod];
	}
	for (int i = 0; i <= 9; i++) {
		pref[0][i] = 0;
	}
	for (int i = 1; i <= 1000000; i++) {
		for (int j = 0; j <= 9; j++) {
			pref[i][j] = pref[i-1][j];
		}
		pref[i][g[i]]++;
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int Q;
	cin >> Q;
	int l, r, k;
	precomp();
	while (Q--) {
		cin >> l >> r >> k;
		cout << pref[r][k]-pref[l-1][k] << endl;
	}
	cin >> Q;

}