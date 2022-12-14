
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

const int N = (int) 0, mod = (int) 0;
int to[10][10][10][10];
int main() {
	memset(to, 63, sizeof to);
	for (int i = 0; i < 10; ++i)
		for (int j = 0; j < 10; ++j)
			for (int x = 0; x < 10; ++x)
				for (int y = 0; y < 10; ++y)
					for (int usei = 0; usei < 20; ++usei)
						for (int usej = 0; usej < 20; ++usej) if (usei + usej > 0)
							if ((i * usei + j * usej + x) % 10 == y)
								to[i][j][x][y] = min(to[i][j][x][y], usei + usej - 1);
	string s;
	cin >> s;
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			int cur = 0;
			int res = 0;
			for (int k = 1; k < (int) s.size(); ++k) {
				cur = s[k - 1] - '0';
				int ch = s[k] - '0';
				if (to[i][j][cur][ch] > 100) {
					res = -1;
					break;
				}
				res += to[i][j][cur][ch];
				cur = ch;
			}
			cout << res << ' ';
		}
		cout << '\n';
	}
}