#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const int N = 1005, INF = (int)1e9;

int n, m;
int vis[N];
vi G[N];
vi vs;
int dis[N];

void dfs(int v, int c) {
    vis[v] = c;
    vs.push_back(v);
    for(int nxt : G[v]) {
        if(vis[nxt] == -1) {
            dfs(nxt, !c);
        } else if(vis[nxt] != !c) {
            cout << -1 << '\n';
            exit(0);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(vis, -1, sizeof(vis));
    cin >> n >> m;
    rep(i, 0, m) {
        int a, b; cin >> a >> b; a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    int res = 0;
    rep(i, 0, n) {
        if(vis[i] != -1) continue;
        vs.clear();
        dfs(i, 0);
        int cres = 0;
        for(int st : vs) {
            for(int u : vs) dis[u] = INF;
            dis[st] = 0;
            queue<int> que;
            que.push(st);
            while(!que.empty()) {
                int v = que.front(); que.pop();
                for(int nxt : G[v]) {
                    if(dis[nxt] == INF) {
                        dis[nxt] = dis[v] + 1;
                        que.push(nxt);
                    }
                }
            }
            for(int u : vs) cres = max(cres, dis[u]);
        }
        res += cres;
    }
    cout << res << '\n';

}