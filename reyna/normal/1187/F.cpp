
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

const int N = (int) 1e6 + 6, mod = (int) 1e9 + 7;
int pw(int a, int b) { return b == 0 ? 1 : (LL) pw((LL) a * a % mod, b >> 1) * (b & 1 ? a : 1) % mod; }
int p[N], q[N], xl[N], xr[N];
int main() {
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int j = 0; j < n; ++j) cin >> xl[j], --xl[j];
	for (int j = 0; j < n; ++j) cin >> xr[j];
	int sum = 1;
	for (int j = 0; j < n - 1; ++j) {
		int num = max(0, min(xr[j], xr[j + 1]) - max(xl[j], xl[j + 1]));
		int denum = (LL) (xr[j] - xl[j]) * (xr[j + 1] - xl[j + 1]) % mod;
		denum = pw(denum, mod - 2);
		p[j] = (LL) num * denum % mod;
		q[j] = (1 - p[j] + mod) % mod;
		sum = (sum + q[j]) % mod;
	}
	int res = (LL) sum * sum % mod;
	for (int j = 0; j < n - 1; ++j)
		res = (res - (LL) q[j] * q[j] % mod + mod) % mod, res = (res + q[j]) % mod;
	for (int j = 0; j < n - 2; ++j) {
		res = (res - (2 * (LL) q[j] * q[j + 1]) % mod + mod) % mod;
		int num = max(0, min(xr[j], min(xr[j + 1], xr[j + 2])) - max(xl[j], max(xl[j + 1], xl[j + 2])));
		int denum = (LL) (xr[j] - xl[j]) * (xr[j + 1] - xl[j + 1]) % mod * (xr[j + 2] - xl[j + 2]) % mod;
		denum = pw(denum, mod - 2);
		int ways = ((p[j] + (LL) p[j + 1]) % mod - (LL) num * denum % mod + mod) % mod;
		res = (res + (2 * (1 - ways + mod) % mod)) % mod;
	}
	// 1 + 2/3 + 1/2 = 13/6 = 169 / 36
	// 169 / 36 - 1 - 4/9 - 1/4
	// 3
	cout << res << '\n';
}