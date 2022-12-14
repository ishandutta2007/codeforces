
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

const int N = (int) 3e5 + 5, L = 20, mod = (int) 0;
int go[N], width[N], mn[N][L], mx[N][L], a[N];
int get_mn(int l, int r) {
	int w = width[r - l];
	return min(mn[l][w], mn[r - (1 << w)][w]);
}
int main() {
	int n;
	cin >> n;
	for (int j = 2; j < N; ++j) width[j] = width[j >> 1] + 1;
	for (int j = 0; j < n; ++j) cin >> a[j];
	for (int j = n; j < 3 * n; ++j) a[j] = a[j - n];
	a[3 * n] = -1;
	for (int j = 0; j <= 3 * n; ++j) {
		mx[j][0] = mn[j][0] = a[j];
	}
	for (int b = 1; b < L; ++b) {
		for (int j = 0; j + (1 << b) <= 3 * n + 1; ++j) {
			mx[j][b] = max(mx[j][b - 1], mx[j + (1 << b - 1)][b - 1]);
			mn[j][b] = min(mn[j][b - 1], mn[j + (1 << b - 1)][b - 1]);
		}
	}
	for (int j = 0; j < 3 * n; ++j) {
		int bl = j + 1, br = 3 * n + 1;
		while (bl < br - 1) {
			int bm = bl + br >> 1;
			if (get_mn(j, bm) * 2 < a[j]) {
				br = bm;	
			} else {
				bl = bm;
			}
		}
		go[j] = br;	
	}
	int mx0 = 0, mn0 = 1e9;
	for (int j = 0; j < n; ++j) mx0 = max(mx0, a[j]), mn0 = min(mn0, a[j]);
	if (mn0 + mn0 >= mx0) {
		for (int j = 0; j < n; ++j)
			cout << -1 << ' ';
		return 0;
	}
	for (int j = 3 * n - 2; j >= 0; --j)
		go[j] = min(go[j], go[j + 1]);
	for (int j = 0; j < n; ++j)
		cout << go[j] - j - 1 << ' ';
}