
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
	ios_base::sync_with_stdio(0);
	int tc;
	cin >> tc;
	while (tc--) {
		int d = -1e18, n, k;
		cin >> n >> k;
		for (int j = 0; j < n; ++j)
			cin >> a[j], d = max(d, a[j]);
		--k;
		for (int j = 0; j < n; ++j)
			a[j] = d - a[j];
		if (k & 1) {
			d = 0;
			for (int j = 0; j < n; ++j) d = max(d, a[j]);
			for (int j = 0; j < n; ++j)
				a[j] = d - a[j];
		}
		for (int j = 0; j < n; ++j)
			cout << a[j] << ' ';
		cout << '\n';
	}
}