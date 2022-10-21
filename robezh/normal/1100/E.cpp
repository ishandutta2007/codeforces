#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 500;

struct edge {
    int to, cost, id, pos;
};

struct eg{
    int a, b, w;
};

int n, m;
vector<edge> G[N];
eg E[N];
int top[N], top_cnt = 0;
int in_deg[N];
vector<int> num;
int vis[N];
int ans[N];
vector<int> res;

bool dfs(int v, int thres) {
    vis[v] = -1;
    for(auto e : G[v]) {
        if(e.cost <= thres || !e.pos) continue;
        if(vis[e.to] == -1) return false;
        if(vis[e.to] == 0 && !dfs(e.to, thres)) return false;
    }
    vis[v] = 1;
    return true;
}

bool check(int thres) {
    fill(vis, vis + n, 0);
    for(int i = 0; i < n; i++) {
        if(vis[i] == 0) if(!dfs(i, thres)) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w; a--, b--;
        G[a].push_back({b, w, i, 1});
        G[b].push_back({a, w, i, 0});
        E[i].a = a, E[i].b = b, E[i].w = w;
        num.push_back(w);
    }
    num.push_back(0);
    sort(num.begin(), num.end());
    num.resize(unique(num.begin(), num.end()) - num.begin());
    int l = -1, r = num.size() - 1, mid;
    while(l + 1 < r) {
        mid = (l + r) / 2;
        if(check(num[mid])) r = mid;
        else l = mid;
    }
    fill(ans, ans + n, -1);
    int thres = num[r];
    for(int i = 0; i < m; i++) {
        if(E[i].w > thres){
            in_deg[E[i].b] ++;
        }
    }
    queue<int> que;
    for(int i = 0; i < n; i++){
        if(in_deg[i] == 0) que.push(i);
    }
    while(!que.empty()) {
        int v = que.front(); que.pop();
        top[v] = top_cnt++;
        for(auto e : G[v]) {
            if(e.cost <= thres || !e.pos) continue;
            in_deg[e.to] --;
            if(in_deg[e.to] == 0) que.push(e.to);
        }
    }
    for(int i = 0; i < m; i++){
        if(top[E[i].a] > top[E[i].b]) res.push_back(i);
    }
    cout << thres << " " << res.size() << endl;
    for(int x : res) cout << x + 1 << " ";
    cout << endl;
}