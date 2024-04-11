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

const int maxN = 110;
const int inf = 1000000000;
int c[maxN][maxN];
string s;
int n, m;

int d[maxN][maxN][maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> s >> m;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string x, y;
		int v;
		cin >> x >> y >> v;
		c[x[0] - 'a'][y[0] - 'a'] = v;
	}

	for (int i = 0; i < maxN; ++i) {
		for (int j = 0; j < maxN; ++j) {
			for (int k = 0; k < maxN; ++k) {
				d[i][j][k] = -inf;
			}
		}
	}

	d[0][0][26] = 0;
	int len = s.size();
	for (int i = 0; i < len; ++i) {
		for (int j = 0; j <= m; ++j) {
			for (int k = 0; k <= 26; ++k) {
				if (d[i][j][k] == -inf) {
					continue;
				}

				for (int l = 0; l < 26; ++l) {
					int nj = j + (l + 'a' == s[i] ? 0 : 1);
					if (nj <= m) {
						d[i + 1][nj][l] = max(d[i + 1][nj][l], d[i][j][k] + c[k][l]);
					}
				}
			}
		}
	}

	int res = -inf;
	for (int i = 0; i <= m; ++i) {
		for (int j = 0; j < 26; ++j) {
			res = max(res, d[len][i][j]);
		}
	}
	cout << res << endl;

	
	return 0;
}