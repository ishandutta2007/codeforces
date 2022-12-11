#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

string s, t;
int n, m;
int f[1010][1010], g[1010][1010];
int nxts[1010], nxtt[1010];

int main() {
	cin >> s >> t;
	n = s.size(), m = t.size();
	for (int i = 0; i < n; i++) {
		nxts[i] = i + 1;
		while (nxts[i] < n && s[nxts[i]] != s[nxts[i] - 1]) nxts[i]++;
	}
	for (int i = 0; i < m; i++) {
		nxtt[i] = i + 1;
		while (nxtt[i] < m && t[nxtt[i]] != t[nxtt[i] - 1]) nxtt[i]++;
	}
	for (int i = n; i >= 0; i--) {
		for (int j = m; j >= 0; j--) {
			if (i) {
				f[i][j] = (i < n && s[i] != s[i - 1] ? f[i + 1][j] : 0)
						+ (j < m && t[j] != s[i - 1] ? g[i][j + 1] : 0);
				f[i][j]++;
				if (f[i][j] >= mod) f[i][j] -= mod;
			}
			if (j) {
				g[i][j] = (i < n && s[i] != t[j - 1] ? f[i + 1][j] : 0)
						+ (j < m && t[j] != t[j - 1] ? g[i][j + 1] : 0);
				g[i][j]++;
				if (g[i][j] >= mod) g[i][j] -= mod;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ans = ans + f[i + 1][j];
			if (ans >= mod) ans -= mod;
			ans = ans + g[i][j + 1];
			if (ans >= mod) ans -= mod;
			ans = ans + mod - (nxts[i] - i + nxtt[j] - j);
			if (ans >= mod) ans -= mod;
		}
	}
	printf("%d\n", ans);
	return 0;
}