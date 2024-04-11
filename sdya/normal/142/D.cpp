#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110;
int n, m, k;
string s[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n >> m >> k;
	int x = 0, y = 0;
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
		int r = count(s[i].begin(), s[i].end(), 'R');
		int g = count(s[i].begin(), s[i].end(), 'G');
		if (g == 0 && r > 0 && r < m) {
			++x;
		}
		if (r == 0 && g > 0 && g < m) {
			++y;
		}
	}
	if (x > 0 && y > 0) {
		cout << "Draw" << endl;
		return 0;
	}
	if (x > 0) {
		cout << "Second" << endl;
		return 0;
	}
	if (y > 0) {
		cout << "First" << endl;
		return 0;
	}

	vector < int > cnt(30);
	for (int i = 0; i < n; ++i) {
		int r = -1;
		int g = -1;
		for (int j = 0; j < m; ++j) {
			if (s[i][j] == 'R') {
				r = j;
			}
			
			if (s[i][j] == 'G') {
				g = j;
			}
		}
		if (r == -1 || g == -1) {
			continue;
		}
		int x = abs(r - g) - 1;
		for (int j = 0; j < 20; ++j) {
			if (x & (1 << j)) {
				++cnt[j];
			}
		}
	}

	int s = 0;
	for (int j = 0; j < 20; ++j) {
		s += (cnt[j] % (k + 1));
	}

	if (s != 0) {
		cout << "First" << endl;
	} else {
		cout << "Second" << endl;
	}

	return 0;
}