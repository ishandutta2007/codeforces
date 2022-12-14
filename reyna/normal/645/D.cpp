//In the name of God

#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin(P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax(P &a, Q b) { if (a < b) a = b; return a; }

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)

const int N = 1e6 + 6;

int read() { int x; cin >> x; return x; }

int deg[N], h, dp[N], t, q[N];
vector<pair<int, int>> in[N];
vector<int> out[N];

int32_t main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n = read(), m = read();
	rep(i, m) {
		int u = read() - 1, v = read() - 1;
		in[v].push_back({u, i});
		out[u].push_back(v);
		deg[v]++;
	}
	rep(i, n) if (deg[i] == 0)
		q[t++] = i;
	int last = -1;
	int res = 0;
	if (t - h > 1) {
		cout << -1;
		return 0;
	}
	while (h != t) {
		int v = q[h++];
		for (int u : out[v])
			if ((--deg[u]) == 0)
				q[t++] = u;
		if (t - h > 1) {
			cout << -1;
			return 0;
		}
		for (auto x : in[v]) if (x.first == last)
			res = max(res, x.second + 1);
		last = v;		
	}
	if (t != n) {
		cout << -1;
		return 0;
	}
	cout << res << endl;
}