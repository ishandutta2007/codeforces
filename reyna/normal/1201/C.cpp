
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
#define int long long
const int N = (int) 1e6 + 6, mod = (int) 0;
int a[N];
int32_t main() {
	int n, k;
	cin >> n >> k;
	for (int j = 0; j < n; ++j) cin >> a[j];
	sort(a, a + n);
	int bl = 0, br = 2e9 + 5;
	while (bl < br - 1) {
		int res = 0, bm = bl + br >> 1;
		for (int j = n / 2; j < n; ++j) {
			res += max(0LL, bm - a[j]);
		}
		if (res <= k) {
			bl = bm;	
		} else {
			br = bm;
		}
	}
	cout << bl << endl;
}