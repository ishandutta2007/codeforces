#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e6 + 50, mod = (int)1e9 + 7;
typedef long long ll;
typedef pair<int, int> P;

struct edge {
    int to, c;
};

int n, tn, m;
vector<edge> G[N];
ll res[N];
vector<P> que[N];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    tn = n;
    for(int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        int x = i;
        int last[2] = {v, u};
        while(true) {
            if(x < 10) {
                G[u].push_back({last[0], x});
                G[v].push_back({last[1], x});
                break;
            }
            int cur = n++;
            G[cur].push_back({last[0], x % 10});
            last[0] = cur;

            cur = n++;
            G[cur].push_back({last[1], x % 10});
            last[1] = cur;

            x /= 10;
        }
    }
    memset(res, -1, sizeof(res));
    res[0] = 0;
    que[0].push_back({0, 0});
    for(int d = 0; d < n; d++) {
        int r = 0;
        int tim = 0;
        for(int i = 0; i < que[d].size(); i = r) {
            while(r < que[d].size() && que[d][r].second == que[d][i].second) r++;
            vector<P> vs[10];
            for(int j = i; j < r; j++) {
                int v = que[d][j].first;
                for(auto e : G[v]) vs[e.c].push_back({v, e.to});
            }
            for(int x = 0; x < 10; x++) {
                for(P p : vs[x]) {
                    if(res[p.second] == -1) {
                        res[p.second] = (res[p.first] * 10 + x) % mod;
                        que[d+1].push_back({p.second, tim});
                    }
                }
                tim++;
            }
        }
    }
    for(int i = 1; i < tn; i++) cout << res[i] << '\n';


}