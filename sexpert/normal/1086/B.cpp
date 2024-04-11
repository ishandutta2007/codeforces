#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
int mxd, mxv, dist[MAXN], pre[MAXN], deg[MAXN];
vector<int> adj[MAXN];

/*void dfs(int s, int p = 0) {
    dist[s] = (p == 0 ? 0 : dist[p] + 1);
    pre[s] = p;
    if(dist[s] > mxd) {
        mxd = dist[s];
        mxv = s;
    }
    for(auto v : adj[s]) {
        if(v == p)
            continue;
        dfs(v, s);
    }
}

pair<int, int> center() {
    mxd = -1;
    dfs(1);
    int v = mxv;
    mxd = - 1;
    dfs(v);
    int diam = mxd;
    v = mxv;
    for(int i = 0; i < diam/2; i++)
        v = pre[v];
    if(diam % 2)
        return {v, pre[v]};
    else
        return {v, -1};
}*/

int main() {
    int n;
    double w, l = 0;
    cin >> n >> w;
    for(int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        //adj[x].push_back(y);
        //adj[y].push_back(x);
        deg[x]++;
        deg[y]++;
    }
    for(int i = 1; i <= n; i++) {
        if(deg[i] == 1)
            l += 1.0;
    }
    cout << fixed << setprecision(15) << 2.0*w/l << endl;
    //pair<int, int> c = center();
    /*cout << c.first << " " << c.second << endl;
    if(c.second == -1)
        num = adj[c.first].size();
    else
        num = adj[c.first].size() + adj[c.second].size() - 2;
    cout << fixed << setprecision(15) << 2.0*w/num << endl;*/
}