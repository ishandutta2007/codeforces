#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int wins[n];
	for (int i = 0; i < n; i++) {
		wins[i] = 0;
	}
	int cur, mw, win;
	for (int i = 0; i < m; ++i) {
		mw = -1;
		win = -1;
		for (int j = 0; j < n; ++j) {
			cin >> cur;
			if (cur > mw) {
				mw = cur;
				win = j;
			}
		}
		wins[win]++;
	}
	mw = -1;
	win = -1;
	for (int i = 0; i < n; i++) {
		if (wins[i] > mw) {
			mw = wins[i];
			win = i;
		}
	}
	cout << win+1 << endl;
	// cin >> n;
}