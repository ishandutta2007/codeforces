//In the name of God

#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin (P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax (P &a, Q b) { if (a < b) a = b; return a; }


constexpr int N = 5e3 + 3, lgN = 13, mod = 1e9 + 7;

int read() { int x; cin >> x; return x; }

int dp[N][N], sum[N][N];
int n;
bitset<N> lcp[lgN][N];

int get_lcp(int i, int j) {
	int res = 0;
	for (int gap = lgN - 1; gap >= 0; --gap)
		if (i + (1 << gap) <= n && j + (1 << gap) <= n && lcp[gap][i][j]) {
			i += 1 << gap;
			j += 1 << gap;
			res += 1 << gap;
		}
	return res;
}

int32_t main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	n = read();
	string s; cin >> s;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (s[i] == s[j])
				lcp[0][i][j] = 1;
	for (int gap = 1; gap < lgN; ++gap)
		for (int i = 0; i < n - (1 << gap) + 1; ++i)
			for (int j = 0; j < n - (1 << gap) + 1; ++j)
				lcp[gap][i][j] = lcp[gap - 1][i][j] & lcp[gap - 1][i + (1 << gap - 1)][j + (1 << gap - 1)];
	for (int r = 0; r <= n; ++r)
		dp[0][r] = 1;
	for (int r = 0; r <= n; ++r) {
		for (int l = r - 1; l >= 1; --l) {
			if (s[l] != '0') {
				int pos = l - (r - l);
				if (pos < 0)
					pos = 0;
				if (pos == l - (r - l)) {
					dp[l][r] = (dp[l][r] + sum[pos + 1][l]) % mod;
					int slcp = get_lcp(pos, l);
					slcp = min(slcp, r - l);
					if (slcp != (r - l) && s[l + slcp] > s[pos + slcp])
						dp[l][r] = (dp[l][r] + dp[pos][l]) % mod;
				} else
					dp[l][r] = (dp[l][r] + sum[0][l]) % mod;
			}
		}
		for (int l = r - 1; l >= 0; --l)
			sum[l][r] = (sum[l + 1][r] + dp[l][r]) % mod;
			
	}
	cout << sum[0][n] << '\n';
	
}