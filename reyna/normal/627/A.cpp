//In the name of God

#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin(P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax(P &a, Q b) { if (a < b) a = b; return a; }

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define int long long
const int N = 65;

int read() { int x; cin >> x; return x; }
ll sum, xo;

int dp[N][2];

int32_t main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> sum >> xo;
	dp[0][0] = 1;
	for (int i = 1; i <= 60; ++i) {
		for (int r = 0; r < 2; ++r) {
			int j = i - 1;
			for (int a = 0; a <= 1; ++a)
				for (int b = 0; b <= 1; ++b) {
					for (int lr = 0; lr <= 1; ++lr) {
						if ((a ^ b) == (xo >> (i - 1) & 1) && ((a + b + lr) & 1) == (sum >> (i - 1) & 1) && ((a + b + lr) >> 1 & 1) == r) {
							dp[i][r] += dp[i - 1][lr];
						}
					}
				}
		}
	}
	if (sum == xo) {
		dp[60][0] -= 2;
	}
	cout << dp[60][0];
	
}