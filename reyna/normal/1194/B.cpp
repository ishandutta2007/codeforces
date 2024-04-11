
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

const int N = (int) 1e6 + 6, mod = (int) 0;
int row[N], col[N];
string s[N];
int main() {
	ios_base::sync_with_stdio(0);
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < max(n, m); ++i) row[i] = col[i] = 0;
		for (int i = 0; i < n; ++i) {
			cin >> s[i];
			for (int j = 0; j < m; ++j) {
				row[i] += (s[i][j] == '.');
				col[j] += (s[i][j] == '.');
			}
		}
		int res = n + m - 1;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				res = min(res, row[i] + col[j] - (s[i][j] == '.'));
		cout << res << '\n';
	}
}