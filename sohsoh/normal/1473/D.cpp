#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;
const ll LOG = 22;

int Log[MAXN], st[MAXN][LOG], st2[MAXN][LOG], n, m, ps[MAXN];

inline int Min(int L, int R) {
	if (R < L) return 1e9;
	int j = Log[R - L + 1];
       	return min(st[L][j], st[R - (1 << j) + 1][j]);	
}

inline int Max(int L, int R) {
	if (R < L) return -1e9;
	int j = Log[R - L + 1];
       	return max(st2[L][j], st2[R - (1 << j) + 1][j]);	
}

inline int solve() {
	fill(ps, ps + n + 10, 0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		char c;
		cin >> c;
		if (c == '+') ps[i] = ps[i - 1] + 1;
		else ps[i] = ps[i - 1] - 1;
		st[i][0] = st2[i][0] = ps[i];
	}

	for (int j = 1; j < LOG; j++) {
		for (int i = 0; i + (1 << j) <= n + 1; i++) {
			st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);	
			st2[i][j] = max(st2[i][j - 1], st2[i + (1 << (j - 1))][j - 1]);	
		}
	}

	while (m--) {
		int L, R;
		cin >> L >> R;
		int t = ps[R] - ps[L - 1];
		cout << 1 + max(Max(0, L - 1), Max(R + 1, n) - t) - min(Min(0, L - 1), Min(R + 1, n) - t) << endl;
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	Log[1] = 0;
	for (int i = 2; i < MAXN; i++) Log[i] = Log[i / 2] + 1;
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}