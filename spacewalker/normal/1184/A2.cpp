/*
 * 101
 * 110
 * 011
 *
 * 011010
 * 001101
 *
 * 010111
 */

#include <bits/stdc++.h>

using namespace std;
constexpr int NMAX = 200010;

char str[NMAX];

int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a%b);
}

int main() {
	int n; scanf("%d", &n);
	scanf("%s", str);
	map<int, int> orbitCounts;
	for (int shift = 0; shift < n; ++shift) {
		orbitCounts[gcd(shift, n)]++;
	}
	int ans = 0;
	for (auto pp : orbitCounts) {
		vector<bool> orbitSum(pp.first);
		for (int i = 0; i < n; ++i) {
			if (str[i] == '1') {
				orbitSum[i % pp.first] = !orbitSum[i % pp.first];
			}
		}
		if (!any_of(begin(orbitSum), end(orbitSum), [] (bool b) {return b;})) {
			ans += pp.second;
		}
	}
	printf("%d\n", ans);
	return 0;
}