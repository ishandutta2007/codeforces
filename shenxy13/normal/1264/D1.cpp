#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
const long long mod = 998244353;
string s;
long long psum[2001], dptable[2000][2000];
long long mp(long long b, long long e) {
	if (e == 0) return 1;
	long long a = mp(b, e >> 1);
	a = a * a % mod;
	if (e & 1) a = a * b % mod;
	return a;
}
long long dp(int l, int r) {
	if (l >= r) return 0;
	if (dptable[l][r] != -1) return dptable[l][r];
	dptable[l][r] = 0;
	if (s[l] != '(') dptable[l][r] = (dptable[l][r] + dp(l + 1, r)) % mod;
	if (s[r] != ')') dptable[l][r] = (dptable[l][r] + dp(l, r - 1)) % mod;
	if (s[l] != '(' && s[r] != ')') dptable[l][r] = (dptable[l][r] - dp(l + 1, r - 1) + mod) % mod;
	if (s[l] != ')' && s[r] != '(') dptable[l][r] = ((dptable[l][r] + dp(l + 1, r - 1)) % mod + mp(2, psum[r] - psum[l + 1])) % mod;
	return dptable[l][r];
}
void solve() {
	memset(dptable, -1, sizeof dptable);
	cin >> s;
	psum[0] = 0;
	for (int i = 0; i < s.size(); ++i) psum[i + 1] = psum[i] + (s[i] == '?');
	printf("%lld", dp(0, s.size() - 1));
}
int main() {
	solve();
	return 0;
}