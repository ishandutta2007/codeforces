#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e5 + 50, INF = (int)1e9 + 50;

struct edge {
    int to, cost;
};

int n, m;
vector<edge> G[N], nG[N];
vector<int> zero;
int zeros[N], zpv[N];
int dis[N], pv[N];
int opt[N];
int mn_dis = N;

void find_zeros() {
    memset(zeros, 0x3f, sizeof(zeros));
    queue<int> que;
    que.push(n - 1);
    zeros[n - 1] = 0;
    mn_dis = min(mn_dis, dis[n-1]);
    while(!que.empty()) {
        int v = que.front(); que.pop();
        mn_dis = min(mn_dis, dis[v]);
        for(auto e : G[v]) {
            if(e.cost == 0 && zeros[e.to] > zeros[v] + 1) {
                zeros[e.to] = zeros[v] + 1;
                zpv[e.to] = v;
                que.push(e.to);
            }
        }
    }
}

string res;

void find_ans(int v) {
    opt[v] = 1;
    for(auto e : nG[v]) {
        find_ans(e.to);
        pv[e.to] = v;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v, c; cin >> u >> v >> c;
        G[u].push_back({v, c});
        G[v].push_back({u, c});
    }

    memset(dis, 0x3f, sizeof(dis));
    queue<int> que;
    dis[0] = 0;
    que.push(0);
    while(!que.empty()) {
        int v = que.front(); que.pop();
        for(auto e : G[v]) {
            if(dis[e.to] > dis[v] + 1) {
                dis[e.to] = dis[v] + 1;
                que.push(e.to);
            }
        }
    }
    find_zeros();
    for(int i = 0; i < n; i++) if(zeros[i] < INF && dis[i] == mn_dis) zero.push_back(i);
//    for(int z : zero) dfs(z);

    vector<int> cur = zero;
    int best = -1;
    for(int d = mn_dis - 1; d >= 0; d--) {
        vector<int> new_cur;
        int mn = N;
        for(int v : cur) {
            for(auto e : G[v]) {
                if(dis[e.to] < dis[v]) mn = min(mn, e.cost);
            }
        }
        res.push_back((char)(mn + '0'));
        for(int v : cur) {
            for(auto e : G[v]) if(e.cost == mn && dis[e.to] < dis[v]) {
                nG[e.to].push_back({v, e.cost});
                new_cur.push_back(e.to);
            }
        }
        sort(new_cur.begin(), new_cur.end());
        new_cur.resize(unique(new_cur.begin(), new_cur.end()) - new_cur.begin());
        cur = new_cur;
    }
    find_ans(0);
    int best_mid = -1;
    for(int i = 0; i < n; i++) {
        if(opt[i] && dis[i] == mn_dis) {
            if(best_mid == -1 || zeros[i] < zeros[best_mid]) best_mid = i;
        }
    }
    vector<int> path1, pathz;
    int v = best_mid;
    while(v != 0) {
        v = pv[v];
        path1.push_back(v);
    }
    v = best_mid;
    while(v != n - 1) {
        v = zpv[v];
        pathz.push_back(v);
    }
//    for(int x : pathz) cout << x << " ";
    reverse(path1.begin(), path1.end());
    path1.push_back(best_mid);
    path1.insert(path1.end(), pathz.begin(), pathz.end());

    if(res.empty()) res.push_back('0');
    cout << res << endl;
    cout << path1.size() << endl;
    for(int x : path1) cout << x << " ";

}