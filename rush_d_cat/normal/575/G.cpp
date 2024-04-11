#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 10;

vector< pair<int,int> > g[N];
int n, m, dis[N];
pair<int, int> pre[N];
bool vis[N];

int dis0[N], pre0[N];
void bfs() {
    for (int i = 0; i <= n; i ++) dis0[i] = 1e9, pre0[i] = -1;
    queue<int> q; q.push(n - 1); dis0[n-1] = 0;

    vector<int> tmp;
    while (q.size()) {
        int u = q.front(); q.pop();
        //g[n-1].push_back( make_pair(u, 0) );
        tmp.push_back(u);
        for (auto e: g[u]) {
            int v = e.first;
            if (e.second == 0) {
                if (dis0[v] == 1e9) {
                    //printf("%d -> %d\n", u, v);
                    dis0[v] = dis0[u] + 1; q.push(v);
                    pre0[v] = u;
                }
            }
        }
    }
}

int main() {
   // freopen("in.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i ++) {
        int u, v, w; scanf("%d%d%d",&u,&v,&w);
        g[u].push_back(make_pair(v, w));
        g[v].push_back(make_pair(u, w));
    }
    bfs();
    queue<int> q;
    for (int i = 0; i < n; i ++) dis[i] = 1e9;
    q.push(0); dis[0] = 0;
    while (q.size()) {
        int u = q.front(); q.pop();
        //printf("%d %d\n", u, dis[u]);
        for (auto e: g[u]) {
            int v = e.first;
            if (dis[v] == 1e9) {
                dis[v] = dis[u] + 1; q.push(v);
            }
        }
    }
    int mn = 1e9, dd = 1e9;
    for (int i = 0; i < n; i ++) {
        if (dis0[i] < 1e9) {
            vis[i] = true; //printf("%d\n", i);
            if (dis[i] < mn) {
                mn = dis[i];
            }
        }
    }
    for (int i = 0; i < n ; i++) {
        if (dis[i] == mn && dis0[i] < 1e9) {
            q.push(i);
        }
    }
    while (q.size()) {
        int mn = 10;
        vector<int> tmp;
        while (q.size()) {
            int u = q.front(); tmp.push_back(u);
            q.pop();
            for (auto e: g[u]) {
                int v = e.first;
                if (dis[v] + 1 == dis[u]) {
                    mn = min(mn, e.second);
                }
            }
        }
        //printf("^*^");
        for (auto u: tmp) {
             for (auto e: g[u]) {
                int v = e.first;
                if (dis[v] + 1 == dis[u] && e.second == mn) {
                    // printf("%d -> %d\n", u, v);
                    q.push(v);
                    //pre[u] = make_pair(v, mn);
                    //printf("%d %d\n", u, v);
                    if (!pre[v].first || dis0[u] < dis0[v]){
                        pre[v] = {u, mn};
                        dis0[v] = dis0[u];
                    }
                }
            }
        }
    }
    /*for (int i = 0; i < n; i++){
        printf("%d %d\n", pre[i].first, vis[i]);
    }*/
    //return 0;
    int now = 0;
    vector<int > path, num;
    while (!vis[now]){
        path.push_back(now);
        num.push_back(pre[now].second);
        now = pre[now].first;
    }
    //return 0;
    while (now != n - 1){
        path.push_back(now);
        now = pre0[now];
    }
    path.push_back(n - 1);
    reverse(num.begin(), num.end());
    if (num.size() == 0) printf("0\n");
    else {
        for (int v : num) printf("%d", v); printf("\n");
    }
    printf("%d\n", path.size());
    for (int v : path) printf("%d ", v);
}