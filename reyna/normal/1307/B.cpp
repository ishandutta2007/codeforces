
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
const int N = (int) 1e5 + 5, mod = (int) 0;
int a[N];
int32_t main() {
	ios_base::sync_with_stdio(0);
	int tc;
	cin >> tc;
	while (tc--) {
		int n, sx, flag = 0;
		cin >> n >> sx;
		for (int j = 0; j < n; ++j) {
			cin >> a[j];
			if (a[j] == sx)
				flag = 1;
		}
		sort(a, a + n);
		int cnt = (sx + a[n-1] - 1) / a[n-1];
		cnt = max(cnt, 2LL);
		if (flag) cnt = 1;
		cout << cnt << '\n';
		
	}
}