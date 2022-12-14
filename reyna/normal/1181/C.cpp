
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <complex>

using namespace std;

#define mp make_pair
#define x first
#define y second
#define pb push_back
#define ALL(x) (x).begin(), (x).end()

typedef long long LL;

const int N = (int) 1005, mod = (int) 0;
string s[N];
int lf[N][N], up[N][N];
int main() {
	ios_base::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	for (int j = 0; j < n; ++j) {
		cin >> s[j];
	}
	for (int row = 0; row < n; ++row) {
		for (int col = 0; col < m; ++col) {
			lf[row][col] = 1;
			if (col > 0 && s[row][col] == s[row][col - 1])
				lf[row][col] = lf[row][col - 1] + 1;
			up[row][col] = 1;
			if (row > 0 && s[row][col] == s[row - 1][col])
				up[row][col] = up[row - 1][col] + 1;
				
		}
	}
	long long res = 0;
	for (int row = 0; row < n; ++row) {
		for (int col = 0; col < m; ++col) {
			int sz = up[row][col];
			if (sz * 3 - 1 <= row) {
				if (up[row - sz][col] == sz) {
					if (up[row - 2 * sz][col] >= sz) {
						int mn = 1e9;
						for (int j = row - 3 * sz + 1; j <= row; ++j)
							mn = min(mn, lf[j][col]);
						res += mn;
					}
				}
			}
		}
	}
	cout << res << endl;
}