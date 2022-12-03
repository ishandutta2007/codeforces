#include <bits/stdc++.h>
using namespace std;

#define rep(i, N) for (int i = 0; i < (N); i++)
#define all(a) (a).begin(), (a).end()
#define pb push_back

using ll = long long;
using i_i = tuple<int, int>;

const int INF = INT_MAX / 2;

vector<int> bfs(int N, vector<vector<int> >& G, int s) {
	vector<int> d(N, INF); d[s] = 0;
	queue<int> q; q.push(s);
	while (q.size()) {
		int u = q.front(); q.pop();
		for (int v: G[u])
			if (d[v] > d[u] + 1) {
				d[v] = d[u] + 1;
				q.push(v);
			}
	}
	return d;
}

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> a(K);
    rep(k, K) scanf("%d", &a[k]), a[k]--;
    vector<vector<int>> G(N);
    while (M--) {
        int x, y; scanf("%d%d", &x, &y);
        x--; y--;
        G[x].pb(y);
        G[y].pb(x);
    }
    vector<int> d = bfs(N, G, 0);
    vector<int> e = bfs(N, G, N - 1);
    vector<i_i> des;
    for (int u: a) des.pb(i_i(d[u], e[u]));
    sort(all(des));
    int ans = 0, mad = -1;
    for (i_i de: des) {
        int d, e; tie(d, e) = de;
        if (mad >= 0) ans = max(ans, mad + 1 + e);
        mad = max(mad, d);
    }
    ans = min(ans, (int)d[N - 1]);
    cout << ans << endl;
}