#include <string>
#include <vector>
#include <iostream>
using namespace std;
const int mod = 1000000007;
vector<int> fact, inv, factinv;
int calc(string s, string t) {
	// anagram of s, less than t
	int n = s.size();
	vector<int> c(26);
	for (int i = 0; i < n; ++i) ++c[s[i] - 'a'];
	int way = 0;
	for (int i = 0; i < n; ++i) {
		int mul = fact[n - i - 1];
		for (int j = 0; j < 26; ++j) mul = 1LL * mul * factinv[c[j]] % mod;
		for (int j = 0; j < t[i] - 'a'; ++j) {
			if (c[j] == 0) continue;
			way = (way + 1LL * mul * c[j]) % mod;
		}
		if (c[t[i] - 'a'] == 0) break;
		--c[t[i] - 'a'];
	}
	return way;
}
int main() {
	string s, t;
	cin >> s >> t;
	int n = s.size();
	fact.resize(n + 1); fact[0] = 1;
	for (int i = 1; i <= n; ++i) fact[i] = 1LL * fact[i - 1] * i % mod;
	inv.resize(n + 1); inv[1] = 1;
	for (int i = 2; i <= n; ++i) inv[i] = 1LL * inv[mod % i] * (mod - mod / i) % mod;
	factinv.resize(n + 1); factinv[0] = 1;
	for (int i = 1; i <= n; ++i) factinv[i] = 1LL * factinv[i - 1] * inv[i] % mod;
	if (s >= t) cout << "0\n";
	else {
		string u = s;
		for (int i = n - 1; i >= 0; --i) {
			if (u[i] != 'z') {
				++u[i];
				break;
			}
			else u[i] = 'a';
		}
		int lans = calc(s, u);
		int rans = calc(s, t);
		cout << (rans - lans + mod) % mod << '\n';
	}
	return 0;
}