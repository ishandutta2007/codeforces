#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
bool solve(vector<string> v) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int dy = -1; dy <= 1; dy++) {
				for (int dx = -1; dx <= 1; dx++) {
					if (dy == 0 && dx == 0) continue;
					int ty = i, tx = j, tc = 0;
					vector<pair<int, int> > w;
					while (tc < 3 && 0 <= tx && tx <= 3 && 0 <= ty && ty <= 3) {
						w.push_back(make_pair(tx, ty)); tc++;
						tx += dx, ty += dy;
					}
					if (tc != 3) continue;
					bool flag = true;
					for (pair<int, int> k : w) {
						if (v[k.second][k.first] != 'x') flag = false;
					}
					if (flag) return true;
				}
			}
		}
	}
	return false;
}
int main() {
	vector<string> s(4);
	for (int i = 0; i < 4; i++) cin >> s[i];
	bool flag = false;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (s[i][j] != '.') continue;
			vector<string> t = s; t[i][j] = 'x';
			if (solve(t)) flag = true;
		}
	}
	cout << (flag ? "YES" : "NO") << endl;
	return 0;
}