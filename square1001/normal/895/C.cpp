#include <iostream>
#include <algorithm>
using namespace std;
const int mod = 1000000007;
int n, a, c[77], b[77], pw[100009], dp[77][524299]; bool vis[77][524299];
int p[] = { 2, 3, 5, 7, 11, 13, 17, 19,23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67 };
int solve(int pos, int bit) {
	if (pos == 71) return (bit == 0);
	if (vis[pos][bit]) return dp[pos][bit];
	int ret = (1LL * solve(pos + 1, bit) * (c[pos] == 0 ? 1 : pw[c[pos] - 1]) + 1LL * solve(pos + 1, bit ^ b[pos]) * (c[pos] == 0 ? 0 : pw[c[pos] - 1])) % mod;
	vis[pos][bit] = true;
	dp[pos][bit] = ret;
	return ret;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a, c[a]++;
	pw[0] = 1;
	for (int i = 1; i <= n; i++) pw[i] = 2 * pw[i - 1] % mod;
	for (int i = 1; i <= 70; i++) {
		int x = i;
		for (int j = 0; j < 19; j++) {
			while (x % p[j] == 0) x /= p[j], b[i] ^= 1 << j;
		}
	}
	int ret = solve(0, 0);
	cout << (ret + mod - 1) % mod << endl;
	return 0;
}