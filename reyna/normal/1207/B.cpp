
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

const int N = (int) 55, mod = (int) 0;
int a[N][N], b[N][N];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> a[i][j];
	vector<pair<int, int>> res;
	for (int i = 0; i < n - 1; ++i)
		for (int j = 0; j < m - 1; ++j) {
			if (a[i][j] && a[i + 1][j] && a[i][j + 1] && a[i + 1][j + 1]) {
				b[i][j] = b[i + 1][j] = b[i][j + 1] = b[i + 1][j + 1] = 1;	
				res.pb(mp(i, j));
			}
	
		}
	int flag = 1;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			flag &= a[i][j] ^ b[i][j] ^ 1;
	if (!flag) {
		cout << -1 << endl;
		return 0;
	}
	cout << (int) res.size() << '\n';
	for (auto x : res)
		cout << x.first + 1 << ' ' << x.second + 1 << '\n';
}