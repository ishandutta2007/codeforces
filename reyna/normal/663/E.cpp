//In the name of God

#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin(P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax(P &a, Q b) { if (a < b) a = b; return a; }

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)

const int N = 20;

int read() { int x; cin >> x; return x; }

int dp[1 << N][1 + N], odp[1 << N][1 + N];
string s[N];

int32_t main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n = read(), m = read();
	rep(i, n) {
		cin >> s[i];
	}
	rep(i, m) {
		int mask = 0;
		rep(j, n)
			mask |= (1 << j) * (s[j][i] == '1');
		dp[mask][0]++;
	}
	rep(i, n) {
		memcpy(odp, dp, sizeof dp);
		memset(dp, 0, sizeof dp);
		rep(mask, 1 << n)
			rep(bit, n + 1) {
				// case 0
				int smask = mask - (mask & (1 << i)), have = mask >> i & 1;
				dp[smask][bit + have] += odp[mask][bit];
				// case 1
				smask = mask | (1 << i);
				have = mask >> i & 1;
				dp[smask][bit + (have ^ 1)] += odp[mask][bit];
			}
	}
	int res = 1e9;
	rep(mask, 1 << n) {
		int sum = 0;
		rep(bit, n + 1) {
			sum += min(bit, n - bit) * dp[mask][bit];
		}
		res = min(res, sum);
	}
	cout << res << endl;
	
}