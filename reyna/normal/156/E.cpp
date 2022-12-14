//In the name of God

#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin(P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax(P &a, Q b) { if (a < b) a = b; return a; }

const int N = 2e5 + 4, SZ = 1e7 + 7;
int dp[SZ][5];
#define int long long
#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; ++i)
int primes[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
// 2 * 3 * 5 * 7 * 11 * 13 * 17 * 19 * 23 = 223092870
// 29 * 31 * 37 * 41 * 43 = 58642669
// 47 * 53 * 59 * 61 * 67 = 600662303
// 71 * 73 * 79 = 409457
// 83 * 89 * 97 = 716539
int pr[] = {
	223092870,
	58642669,
	600662303,
	409457,
	716539
};
int used[20], a[N], digit[50], power[50][50];
map<char, int> num;
inline int read() { int x; cin >> x; return x; }
inline int read(int &x) { cin >> x; return x; }


int32_t main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	for (char c = '0'; c <= '9'; ++c)
		num[c] = c - '0';
	for (char c = 'A'; c <= 'F'; ++c)
		num[c] = c - 'A' + 10;
	rep(i, 50) {
		power[i][0] = 1;
		for (int j = 1; j < 50; ++j)
			power[i][j] = power[i][j - 1] * i;
	}
	num['?'] = 16;
	int n;
	read(n);
	rep(i, N) a[i] = 1;
	rep(i, n) read(a[i]);
	rep(pid, 5) {
		memset(used, 0, sizeof used);
		int mod = pr[pid];
		for (int d = 2; d <= 16; ++d) {
			int dig = 0, pw0 = 1, pw1 = 1;
			while (pw0 < n)
				dig++, pw0 *= d, pw1 *= d + 1;
			used[d + 1] = used[d] + pw1;
			rep(i, dig)
				digit[i] = 0;
			rep(i, pw1) {
				int x = i;
//				rep(j, dig) {
//					digit[dig - j - 1] = x % (d + 1);
//					x /= d + 1;
//				}
				int dpos = dig;
				rep(j, dig) if (digit[j] == d) {
					dpos = j;
				}
				if (dpos == dig) {
					x = 0;
					rep(j, dig)
						x *= d, x += digit[j];
					dp[i + used[d]][pid] = a[x] % mod;
				} else {
//					int dpow = 1;
//					rep(j, dig - dpos - 1)
//						dpow *= d + 1;
					dp[i + used[d]][pid] = 1;
					rep(j, d)
						dp[i + used[d]][pid] = dp[i + used[d]][pid] * 1LL * dp[i + used[d] - (d - j) * power[d + 1][dig - dpos - 1]][pid] % mod;
				}
				int pt = dig - 1;
				digit[dig - 1]++;
				while (pt != 0 && digit[pt] == d + 1)
					digit[pt] = 0, digit[pt - 1]++, pt--; 
			}
		}
	}
	int q;
	read(q);
	while (q--) {
		int di = read();
		string s;
		cin >> s;
		int c = read();
		bool ok = 1;
		int foo = 0;
		bool flag = 0;
		rep(i, (int) s.size()) {
			foo *= di;
			if (s[i] != '?')
				foo += num[s[i]];
			if (foo >= n) {
				flag = 1;
				break;
			}
		}
		for (int iter = 0; iter < 25; ++iter) {
			int p = primes[iter];
			int div = 0;
			for (int i = 0; i < 5; ++i)
				if (pr[i] % p == 0)
					div = i;
			int bar = 0;
			int dig = 0, pw0 = 1;
			while (pw0 < n)
				dig++, pw0 *= di;
			int pro = 1;
			if (!flag) {
				for (int i = max(0LL, (int) s.size() - dig); i < (int) s.size(); ++i) {
					bar *= di + 1;
					if (s[i] != '?')
						bar += num[s[i]];
					else
						bar += di;
				}
				pro = dp[used[di] + bar][div];
			}
			if ((c + pro) % p == 0) {
				cout << p << '\n';
				ok = 0;
				break;
			}
		}
		if (ok)
			cout << -1 << '\n';
	}
}