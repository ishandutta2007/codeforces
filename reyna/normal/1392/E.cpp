
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

const int N = (int) 51, mod = (int) 0;
long long comb[N][N], ways[N][N], mx_sum[N][N], mn_sum[N][N];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j <= i; ++j)
			comb[i][j] = (i == j || j == 0) ? 1 : comb[i-1][j-1] + comb[i-1][j];
	/*
	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < n; ++y) {
			int mx = x + 1, my = y;
			ways[x][y] = 0;
			if (mx >= 0 && mx < n && my >= 0 && my < n) {
				ways[x][y] = comb[2 * n - 2 - mx - my][n - 1 - my];
			}
			cout << ways[x][y] << ' ';
		}
		cout << endl;
	}
	*/
	for (int x = n - 1; x >= 0; --x)
		for (int y = n - 1; y >= 0; --y) {
			for (int i = n - 1; i >= 0; --i)
				for (int j = n - 1; j >= 0; --j) {
					mx_sum[i][j] = ways[i][j] + max(mx_sum[i+1][j], mx_sum[i][j+1]);
					mn_sum[i][j] = ways[i][j] + min(mn_sum[i+1][j], mn_sum[i][j+1]);
				}
			if (x <= n - 2 && y <= n - 2) {
				ways[x][y+1] = mx_sum[x+1][y] - mn_sum[x][y+1] + 1;	
			}
		}
	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < n; ++y)
			cout << ways[x][y] << ' ';
		cout << endl;
	}
			for (int i = n - 1; i >= 0; --i)
				for (int j = n - 1; j >= 0; --j) {
					mx_sum[i][j] = ways[i][j] + max(mx_sum[i+1][j], mx_sum[i][j+1]);
					mn_sum[i][j] = ways[i][j] + min(mn_sum[i+1][j], mn_sum[i][j+1]);
				}
	/*
	for (int x = 0; x < n + 2; ++x) {
		for (int y = 0; y < n + 2; ++y) {
			int mx = x - 1, my = y + 1;
			ways[x][y] = 0;
			if (mx >= 0 && mx < n && my >= 0 && my < n) {
				ways[x][y] = comb[2 * n - 2 - mx - my][n - 1 - my];
			}
		}
	}
	*/
	int q;
	cin >> q;
	while (q--) {
		long long k;
		cin >> k;
		int px = 0, py = 0;
		cout << 1 << ' ' << 1 << endl;
		for (int i = 0; i < 2 * n - 2; ++i) {
			if (px == n - 1) {
				py++;
			} else if (py == n - 1) { 
				px++;
			} else {
			if (k >= mn_sum[px][py+1]) {
				py++;
				k -= ways[px][py];
			} else {
				px++;
				k -= ways[px][py];
			}
			}
			cout << px + 1 << ' ' << py + 1 << endl;
		}
	}
}