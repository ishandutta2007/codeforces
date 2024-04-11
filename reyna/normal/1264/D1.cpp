
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

const int N = (int) 1e6 + 6, mod = (int) 998244353;
int pw(int a, int b) {
	if (b == 0) return 1;
	return (LL) pw((LL) a * a % mod, b >> 1) * (b & 1 ? a : 1) % mod;
}
int f[N], inv[N];
int comb(int n, int r) {
	if (n == r) return 1;
	if (n < 0 || r < 0 || n - r < 0) return 0;
	return f[n] * (LL) inv[r] % mod * inv[n - r] % mod;
}
int sum[N], sumo[N], sumc[N];
int main() {
	ios_base::sync_with_stdio(0);
	f[0] = inv[0] = 1;
	for (int j = 1; j < N; ++j)
		f[j] = (LL) f[j - 1] * j % mod, inv[j] = pw(f[j], mod - 2);
	string s;
	cin >> s;
	int n = (int) s.size(), res = 0;
	for (int j = 0; j < n; ++j) {
		sumo[j + 1] = (sumo[j] + (s[j] == '('));
		sumc[j + 1] = sumc[j] + (s[j] == ')');
		sum[j + 1] = (sum[j] + (s[j] == '?'));
	}
	for (int pos = 0; pos < n - 1; ++pos) {
		int x = sum[pos + 1], y = sum[n] - sum[pos + 1];
		int k = sumc[n] - sumc[pos + 1] - sumo[pos + 1];
		int mx = max(sumc[n] - sumc[pos + 1], sumo[pos + 1]);
		//cout << " hello " << mx << endl;
		//cout << " before " << pos << ' ' << res << endl;
		if (k > 0) {
			res = (res + comb(x + y, k + y) * (LL) mx) % mod;
			res = (res + comb(y, 1) * ((LL) comb(x + y - 1, k + y) + mod)) % mod;
		} else {
			res = (res + comb(x + y, k + y) * (LL) mx) % mod;
			res = (res + comb(x, 1) * ((LL) comb(x + y - 1, -k + x) + mod)) % mod;
		}
		//cout << " after " << pos << ' ' << res << endl;
	}
	cout << res << endl;
}