
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

const int N = (int) 2005, mod = (int) 0;
int sum[N][N], a[N][N];
void add_sq(int xl, int xr, int yl, int yr) {
	xl = max(xl, 0);
	yl = max(yl, 0);
	sum[xl][yl]++;
	sum[xl][yr]--;
	sum[xr][yl]--;
	sum[xr][yr]++;
}
int main() {
	int n, k;
	cin >> n >> k;
	for (int x = 0; x < n; ++x) {
		string s;
		cin >> s;
		for (int y = 0; y < n; ++y) {
			a[x][y] = (s[y] == 'B');	
		}
	}
	int add = 0;
	for (int row = 0; row < n; ++row) {
		int mn = n, mx = -1;	
		for (int col = 0; col < n; ++col) if (a[row][col]) mx = col;
		for (int col = n - 1; col >= 0; --col) if (a[row][col]) mn = col;
		if (mx == -1) { 
			++add;
			continue;
		}
		int sz = k - (mx - mn);
		if (sz <= 0) continue;
		add_sq(row - k + 1, row + 1, mn - sz + 1, mn + 1);
	}
	for (int col = 0; col < n; ++col) {
		int mn = n, mx = -1;
		for (int row = 0; row < n; ++row) if (a[row][col]) mx = row;
		for (int row = n - 1; row >= 0; --row) if (a[row][col]) mn = row;
		if (mx == -1) {
			++add;
			continue;
		}
		int sz = k - (mx - mn);
		if (sz <= 0) continue;
		add_sq(mn - sz + 1, mn + 1, col - k + 1, col + 1);
	}
	for (int x = 0; x < n; ++x)
		for (int y = 0; y < n; ++y) {
			if (x) sum[x][y] += sum[x - 1][y];
			if (y) sum[x][y] += sum[x][y - 1];
			if (x && y) sum[x][y] -= sum[x - 1][y - 1];
		}
	int res = add;
	for (int x = 0; x < n; ++x)
		for (int y = 0; y < n; ++y) {
			res = max(res, sum[x][y] + add);
		}
	cout << res << endl;
}