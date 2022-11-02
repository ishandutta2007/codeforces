#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <set>
#include <queue>
#include <deque>
#include <unordered_set>
#include <map>
#include<unordered_map>
#include <bitset>
#include <random>
#include <ctime>
using namespace std;
mt19937 rnd(time(NULL));
//#define int long long
signed main() {
	int w, h;
	cin >> h >> w;
	int c = 0;
	vector<vector<int>>a(h, vector<int>(w));
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			char tmp;
			cin >>tmp;
			if (tmp == '*') {
				a[i][j] = 1;
				c++;
			}
		}
	}
	
	for (int i = 1; i < h - 1; i++) {
		for (int j = 1; j < w - 1; j++) {
			int cnt = 0;
			if (a[i][j] == 1 && a[i - 1][j] == 1 && a[i + 1][j] == 1 && a[i][j - 1] == 1 && a[i][j + 1] == 1) {
				int x = i;
				while (x > -1 && a[x][j] == 1) {
					cnt++;
					x--;
				}
				x = i;
				while (x <h && a[x][j] == 1) {
					cnt++;
					x++;
				}
				int y = j;
				while (y > -1 && a[i][y] == 1) {
					cnt++;
					y--;
				}
				y = j;
				while (y < w && a[i][y] == 1) {
					cnt++;
					y++;
				}
				if (cnt - 3 == c) {
					cout << "YES";
					return 0;
				}
			}

		}
	}
	cout << "NO";


	return 0;
}