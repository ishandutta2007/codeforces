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

int n, r;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n >> r;
	int res = 1000000000;
	string s;
	for (int i = 1; i <= r; ++i) {
		int x = r, y = i;
		string current;
		int needed = 0;

		{
			int sx = x, sy = y;
			while (true) {
				if (sx == 0 || sy == 0) {
					break;
				}
				if (sx > sy) {
					needed += (sx / sy);
					sx %= sy;
				} else if (sy > sx) {
					needed += (sy / sx);
					sy %= sx;
				} else {
					++needed;
					sx = 0;
					break;
				}
			}
			if (sx + sy != 1 || needed != n) {
				continue;
			}
		}

		while (true) {
			while (x > y) {
				current += 'T';
				x -= y;
			}
			while (y > x) {
				current += 'B';
				y -= x;
			}

			if (x == y) {
				break;
			}
		}
		reverse(current.begin(), current.end());
		{
			string u = "";
			u += 'T';
			u += current;
			int coef = 0;
			for (int j = 1; j < u.size(); ++j) {
				if (u[j] == u[j - 1]) {
					++coef;
				}
			}
			if (coef < res) {
				res = coef;
				s = u;
			}
		}
		{
			string u = "";
			u += 'B';
			u += current;
			for (int j = 0; j < u.size(); ++j) {
				u[j] = (u[j] == 'B' ? 'T' : 'B');
			}
			int coef = 0;
			for (int j = 1; j < u.size(); ++j) {
				if (u[j] == u[j - 1]) {
					++coef;
				}
			}
			if (coef < res) {
				res = coef;
				s = u;
			}
		}
	}

	if (res == 1000000000) {
		cout << "IMPOSSIBLE" << endl;
	} else {
		printf("%d\n", res);
		puts(s.c_str());
	}

	return 0;
}