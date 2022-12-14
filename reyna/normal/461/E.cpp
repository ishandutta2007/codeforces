//In the name of God

// manam comment bezaram? : ))

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin(P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax(P &a, Q b) { if (a < b) a = b; return a; }

const int N = 1e5 + 5, K = 4, lgN = 60;

int read() { int x; cin >> x; return x; }

int mark[12][1 << 22], a[N];
ll adj[K][K];

ll mat[lgN][K][K], c[K][K], cur[K][K];

void mul(ll a[K][K], ll b[K][K]) {
	for (int i = 0; i < K; ++i)
		for (int j = 0; j < K; ++j)
			for (int k = 0; k < K; ++k)
				c[i][j] = min(c[i][j], a[i][k] + b[k][j]);
}

ll getmin(ll a[K][K]) {
	ll mn = 9e18;
	for (int i = 0; i < K; ++i)
		for (int j = 0; j < K; ++j)
			smin(mn, a[i][j]);
	return mn;	
}

void pr(ll a[K][K]) {
	for (int i = 0; i < K; ++i) {
		for (int j = 0; j < K; ++j) {
			cout << i << ' ' << j << ' ' << a[i][j] << endl;
		}
	}
}

int32_t main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll n; cin >> n; n--;
	string s; cin >> s;
	int m = (int) s.size();
	for (int i = 0; i < m; ++i)
		a[i] = s[i] - 'A';
	for (int len = 1; len <= 11; ++len)
		for (int i = 0; i + len - 1 < m; ++i) {
			int h = 0;
			for (int j = i; j < i + len; ++j)
				h <<= 2, h += a[j];
			mark[len][h] = 1;
		}
	memset(adj, 63, sizeof adj);
	memset(cur, 63, sizeof cur);
	for (int len = 1; len <= 11; ++len) {
		for (int mask = 0; mask < (1 << (len * 2)); ++mask) if (!mark[len][mask]) {
			smin(adj[mask & 3][mask >> (len * 2 - 2)], len - 1);
		}
	}
	for (int i = 0; i < K; ++i)
		cur[i][i] = 0;
	memcpy(mat[0], adj, sizeof adj);
//	pr(mat[0]);
//	pr(adj);
	for (int i = 1; i < lgN; ++i) {
		memset(c, 63, sizeof c);
		mul(mat[i - 1], mat[i - 1]);
		memcpy(mat[i], c, sizeof c);
	}
	ll res = 1;
	for (int i = lgN - 1; i >= 0; --i) {
		memset(c, 63, sizeof c);
		mul(mat[i], cur);
		if (getmin(c) <= n) {
			memcpy(cur, c, sizeof c);
			res += 1LL << i;
		}
	}
	cout << res << endl;
}