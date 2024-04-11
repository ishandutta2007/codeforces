//In the name of God



#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, e) for(int i = (s); i < (e); i++)
#define x first
#define y second

typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin (P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax (P &a, Q b) { if (a < b) a = b; return a; }


int pw(int a, int b, int mod) { return (b? pw(1LL * a * a % mod, b >> 1, mod) * 1LL * (b & 1? a : 1) % mod: 1); }


const int maxN = 22;
const int maxSZ = 2e5 + 49;
const int mod = 0;
const int base = 1000 * 1000 + 3;
const int oo = 1e9 + 49;

int read() { int x; cin >> x; return x; }

int nxt[maxSZ][maxN], t[maxN], a[maxN][maxN], dp[1 << maxN], valid;
pii q[maxN];

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n = read(), m = read(), T = read();
	string s; cin >> s;
	s += '1';
	for (int i = 0; i < n; i++)
		s[i] -= 'A', valid |= 1 << s[i];
	for (int i = 0; i < m; i++)
		t[i] = read();
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			a[i][j] = read();
	for (int j = 0; j < m; j++)
		nxt[n][j] = n;
	for (int i = n - 1; ~i; --i) {
		for (int j = 0; j < m; j++) {
			if (s[i + 1] == j) {
				nxt[i][j] = i + 1;
			} else {
				nxt[i][j] = nxt[i + 1][j];
			}
			q[j] = pii(nxt[i][j], j);	
		}
		sort(q, q + m);
		int mask = 0;
		for (int _ = 0; _ < m; _++) {
			int p = q[_].x, ch = q[_].y;
			if (p == n)
				break;
			if (ch == s[i]) {
				int nmask = mask | (1 << ch);
				dp[nmask] -= a[ch][ch];
				dp[mask] += a[ch][ch];
				break;
			} else {
				int nmask = mask | (1 << ch) | (1 << s[i]);
				dp[nmask] += a[s[i]][ch];
				dp[nmask ^ (1 << ch)] -= a[s[i]][ch];
				dp[nmask ^ (1 << s[i])] -= a[s[i]][ch];
				dp[mask] += a[s[i]][ch];
			}
			mask |= 1 << ch;
		}
	}
	int res = 0;
	for (int i = 0; i < m; i++)
		for (int mask = 0; mask < (1 << m); mask ++) if (mask >> i & 1)
			dp[mask] += dp[mask ^ (1 << i)];
	for (int mask = 0; mask < (1 << m); mask++) {
		if ((mask & valid) != mask || mask == valid)
			continue;
		int sum = 0;
		for (int i = 0; i < m; i++) if ((mask >> i & 1))
			sum += t[i];
		sum += dp[mask];
		res += (sum <= T);
	}
	cout << res << '\n';
}