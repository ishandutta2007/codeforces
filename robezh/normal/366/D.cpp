#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;
const int N = (int)1e3 + 50, M = (int)3e3 + 50, INF = (int)1e9 + 50;

struct edge {
    int to, l, ri;
};

int n, m;
vector<edge> G[N];
vector<int> rs;
int dp[M][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v, l, r;
        cin >> u >> v >> l >> r; u--, v--;
        G[u].push_back({v, l, r});
        G[v].push_back({u, l, r});
        rs.push_back(r);
    }
    if(m == 0) return cout << "Nice work, Dima!" << endl, 0;
    sort(rs.begin(), rs.end());
    rs.resize(unique(rs.begin(), rs.end()) - rs.begin());
    for(int i = 0; i < n; i++) {
        for(auto &e : G[i]) e.ri = (int)(lower_bound(rs.begin(), rs.end(), e.ri) - rs.begin());
    }

    memset(dp, 0x3f, sizeof(dp));
    dp[(int)rs.size() - 1][0] = 0;
    int res = -1;
    for(int k = (int)rs.size() - 1; k >= 0; k--) {
        priority_queue<P, vector<P>, greater<> > pque;
        for(int i = 0; i < n; i++) if(dp[k][i] < INF) pque.push({dp[k][i], i});
        while(!pque.empty()) {
            P p = pque.top(); pque.pop();
            int v = p.second, l = p.first, ri = k;
            for(auto e : G[v]) {
                int nl = max(l, e.l), nri = min(ri, e.ri);
                if(nl < dp[nri][e.to]) {
                    dp[nri][e.to] = nl;
                    if(nri == k) pque.push({nl, e.to});
                }
            }
        }
        res = max(res, rs[k] - dp[k][n-1] + 1);
    }
    if(res <= 0) cout << "Nice work, Dima!" << endl;
    else cout << res << endl;
}