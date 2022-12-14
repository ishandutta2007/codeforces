//In the name of God

#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin(P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax(P &a, Q b) { if (a < b) a = b; return a; }

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)

const int N = 105;

int read() { int x; cin >> x; return x; }

int mark[N], n, m, x, mat[N][N], cap[N][N];

int dfs(int v, int sink, int flow = 2e9) {
	if (v == sink)
		return flow;
	if (mark[v]++)
		return 0;
	rep(u, n) if (cap[v][u]) {
		int x = dfs(u, sink, min(flow, cap[v][u]));
		if (x) {
			cap[v][u] -= x;
			cap[u][v] += x;
			return x;
		}
	}
	return 0;
}

bool check(double lim) {
	rep(u, n)
		rep(v, n) {
			int bl = 0, br = 1e6 + 1;
			while (bl < br - 1) {
				int bm = bl + br >> 1;
				if (bm * lim <= mat[u][v])
					bl = bm;
				else
					br = bm;
			}
			cap[u][v] = bl;
		}
	int res = 0;
	while (true) {
		memset(mark, 0, sizeof mark);
		int x = dfs(0, n - 1);
		res += x;
		if (!x)
			break;
	}
	return res >= x;
}

int32_t main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	n = read(), m = read(), x = read();
	rep(i, m) {
		int u = read() - 1, v = read() - 1, w = read();
		mat[u][v] = w;
	}
	double bl = 0, br = 1e6 + 1;
	for (int i = 0; i < 100; ++i) {
		double bm = (bl + br) / 2;
		if (check(bm))
			bl = bm;
		else
			br = bm;
	}
	cout << setprecision(6) << fixed << (long double) bl * x << endl;
}