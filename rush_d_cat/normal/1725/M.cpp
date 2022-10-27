#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 7;

long long dis[N];
typedef pair<int,int> pii;
typedef pair<long long, int > pij;
vector<pii> p[N], g[N];

int main(){
    int n, m, u, v, w;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++){
        scanf("%d%d%d", &u, &v, &w);
        p[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    dis[1] = 0;
    for (int i = 2; i <= n; i++){
        dis[i] = 1e18;
    }
    priority_queue<pij, vector<pij>, greater<pij>  > Q;
    Q.push({0, 1});
    while (!Q.empty()){
        pij now = Q.top(); Q.pop();
        int u = now.second;
        if (dis[u] < now.first) continue;
        for (auto x : p[u]){
            int v = x.first;
            if (dis[v] > dis[u] + x.second){
                dis[v] = dis[u] + x.second;
                Q.push({dis[v], v});
            }
        }
    }
    
    for (int i = 1; i <= n; i++){
        if (dis[i] < 1e18){
            Q.push({dis[i], i});
        }
    }
    
    while (!Q.empty()){
        pij now = Q.top(); Q.pop();
        int u = now.second;
        if (dis[u] < now.first) continue;
        for (auto x : g[u]){
            int v = x.first;
            if (dis[v] > dis[u] + x.second){
                dis[v] = dis[u] + x.second;
                Q.push({dis[v], v});
            }
        }
    }

    for (int i = 2; i <= n; i++){
        if (dis[i] < 1e18){
            cout << dis[i] << " ";
        } else{
            cout << "-1 ";
        }
    }
    return 0;
}