#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
string s, u[2]; bool vis[33]; int px[33], py[33];
bool solve() {
	for (int i = 0; i < 27; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 13; k++) {
				if (s[i] == u[j][k]) px[i] = j, py[i] = k;
			}
		}
	}
	for (int i = 1; i < 27; i++) {
		if (s[i - 1] == s[i]) return false;
		if (abs(px[i] - px[i - 1]) >= 2 || abs(py[i] - py[i - 1]) >= 2) return false;
	}
	return true;
}
int main() {
	cin >> s;
	string t;
	for (int i = 0; i < 27; i++) {
		if (!vis[s[i] - 65]) vis[s[i] - 65] = true, t += s[i];
	}
	bool f = false;
	for (int i = 0; i < 26; i++) {
		u[0] = t.substr(0, 13);
		u[1] = t.substr(13);
		reverse(u[1].begin(), u[1].end());
		if (solve()) {
			cout << u[0] << endl << u[1] << endl;
			f = true;
			break;
		}
		t = t[25] + t.substr(0, 25);
	}
	if (!f) cout << "Impossible" << endl;
	return 0;
}