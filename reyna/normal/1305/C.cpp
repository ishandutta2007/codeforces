
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

const int N = (int) 1e6 + 6, M = 1005;
int cnt[N], a[N], pw[M][M];
int main() {
	ios_base::sync_with_stdio(0);
	int res = 1;
	int n, mod;
	cin >> n >> mod;
	res %= mod;
	for (int i = 0; i < mod; ++i) {
		pw[i][0] = 1;
		for (int j = 1; j < M; ++j)
			pw[i][j] = pw[i][j - 1] * (LL) i % mod;
	}
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	if (mod < n) {
		cout << 0 << endl;
		return 0;
	}
	if (mod == 1) {
		cout << 0 << endl;
		return 0;
	}
	sort(a, a + n);
	for (int i = 0; i < n; ++i) {
		int cur = a[i];
		for (int j = 0; j < mod; ++j) {
			int val = (cur - j + mod) % mod;
			int p = cnt[j];
			if (val == 0 && p > 0) res = 0;
			p %= (mod - 1);
			res = (LL) res * pw[val][p] % mod;
		}
		cnt[cur % mod] = (cnt[cur % mod] + 1);
	}
	cout << res << '\n';
}