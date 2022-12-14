
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

const int N = (int) 5e5 + 6, M = 300, mod = (int) 0;
int res[M][M], a[N];
int main() {
	ios_base::sync_with_stdio(0);
	int q; cin >> q;
	while (q--) {
		int t, x, y;
		cin >> t >> x >> y;
		if (t == 1) {
			a[x] += y;
			for (int j = 1; j < M; ++j)
				res[j][x % j] += y;
		} else {
			if (x >= M) {
				int res = 0;
				for (int j = y; j <= N - 6; j += x)
					res += a[j];
				cout << res << '\n';
			} else {
				cout << res[x][y] << '\n';
		
			}
		}
	}
}