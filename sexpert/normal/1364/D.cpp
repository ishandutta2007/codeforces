#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 10;
int dis[MAXN], ptr[MAXN], sz, par[MAXN], prv[MAXN], vis[MAXN];
vector<int> adj[MAXN], comp;

vector<int> trace(int src, int dst) {
    queue<int> q({src});
    vis[src] = 1;
    while(q.size()) {
        int u = q.front(); q.pop();
        for(auto v : adj[u]) {
            if(vis[v] || dis[v] == -1)
                continue;
            prv[v] = u;
            vis[v] = 1;
            q.push(v);
        }
    }
    vector<int> res;
    int u = dst;
    while(u != src) {
        res.push_back(u);
        u = prv[u];
    }
    res.push_back(src);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    memset(dis, -1, sizeof dis);
    queue<int> q({1});
    dis[1] = 0;
    sz = 1;
    comp.push_back(1);
    while(sz < k) {
        int u = q.front();
        for(int &i = ptr[u]; i < adj[u].size(); i++) {
            int v = adj[u][i];
            if(v == par[u])
                continue;
            //cout << u << " === " << v << endl;
            par[v] = u;
            for(auto w : adj[v]) {
                if(w == u)
                    continue;
                if(dis[w] != -1) {
                    cout << "2\n";
                    //cout << u << " path to " << w << endl;
                    vector<int> pth = trace(u, w);
                    pth.push_back(v);
                    cout << pth.size() << '\n';
                    for(auto x : pth)
                        cout << x << " ";
                    cout << '\n';
                    return 0;
                }
            }
            //cout << "added " << v << " to component " << endl;
            sz++;
            dis[v] = dis[u] + 1;
            q.push(v);
            comp.push_back(v);
            if(sz == k)
                break;
        }
        if(ptr[u] == adj[u].size())
            q.pop();
    }
    cout << "1\n";
    int req = (k + 1)/2;
    vector<int> ans[2];
    for(auto x : comp)
        ans[dis[x] % 2].push_back(x);
    if(ans[0].size() >= req) {
        for(int i = 0; i < req; i++)
            cout << ans[0][i] << " ";
        cout << '\n';
        return 0;
    }
    for(int i = 0; i < req; i++)
        cout << ans[1][i] << " ";
    cout << '\n';
}