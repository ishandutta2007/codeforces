#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <bitset>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 210;
int n, m, k;
string s;
int d[maxN][maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n >> m >> k;
	int dir = 1;
	{
		string s1, s2;
		cin >> s1 >> s2;
		if (s2 == "head") {
			dir = -1;
		}
	}
	cin >> s;

	d[0][m] = 1;
	int res = 0;
	for (int i = 0; i < s.size(); ++i) {
		int oldk = k;
		k += dir;
		if (k == 0) {
			k = 2;
			dir = -dir;
		}
		if (k == n + 1) {
			k = n - 1;
			dir = -dir;
		}
		for (int j = 1; j <= n; ++j) {
			if (d[i][j] == 0) {
				continue;
			}
			if (j == oldk) {
				continue;
			}
			if (s[i] == '0') {
				if (j - 1 >= 1) {
					if (j - 1 != oldk) {
						d[i + 1][j - 1] = 1;
					} else {
						res = max(res, i + 1);
					}
				}
				if (j != oldk) {
					d[i + 1][j] = 1;
				} else {
					res = max(res, i + 1);
				}
				if (j + 1 <= n) {
					if (j + 1 != oldk) {
						d[i + 1][j + 1] = 1;
					} else {
						res = max(res, i + 1);
					}
				}
			} else {
				for (int p = 1; p <= n; ++p) {
					d[i + 1][p] = 1;
				}
			}
		}
	}

	for (int i = 1; i <= s.size(); ++i) {
		for (int j = 1; j <= n; ++j) {
			if (d[i][j] == 1) {
				res = max(res, i);
			}
			if (d[i][j] == 1 && i == s.size() && k != j) {
				res = -1;
				cout << "Stowaway" << endl; 
				return 0;
			}
		}
	}
	if (res == -1) {
		cout << "Stowaway" << endl; 
	} else {
		cout << "Controller " << res << endl;
	}

	return 0;
}