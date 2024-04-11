//In the name of God

#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin(P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax(P &a, Q b) { if (a < b) a = b; return a; }

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)

const int N = 1e6 + 6, mod = 1e9 + 7;

int read() { int x; cin >> x; return x; }

int dp[N];
int last[N];

int32_t main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n = read(), k = read();
	string s; cin >> s;
	int m = (int) s.size();
	memset(last, -1, sizeof last);
	rep(i, m) 
		s[i] -= 'a';
	rep(i, m) {
		int sum = 0;
		rep(j, k) {
			sum += dp[j];
			sum %= mod;
		}
		last[s[i]] = i;
		dp[s[i]] = (sum + 1) % mod;
	}
	rep(i, n) {
		int ch = 0;
		rep(j, k)
			if (last[j] < last[ch])
				ch = j;
		int sum = 0;
		rep(j, k) {
			sum += dp[j];
			sum %= mod;
		}
		last[ch] = i + m;
		dp[ch] = (sum + 1) % mod;
	}
	int sum = 0;
	rep(i, k)
		sum += dp[i], sum %= mod;
	cout << (1 + sum) % mod << endl;
}