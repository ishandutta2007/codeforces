#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
typedef pair<int, int> P;


struct edge{
    int to;
    int cost;
    edge(int _to, int _cost){
        to = _to, cost = _cost;
    }
};

int n,m,s,t,a,b;
int smincost[1050];
int tmincost[1050];
int adj[1050][1050];
priority_queue<P, vector<P>, greater<P> > pque;
vector<int> G[1050];

void get_smin(){
    pque.push(P(0,s));
    smincost[s] = 0;
    while(!pque.empty()){
        P p = pque.top(); pque.pop();
        if(p.first > smincost[p.second]) continue;
        for(int nxt : G[p.second]){
            if(smincost[p.second] + 1 < smincost[nxt]){
                smincost[nxt] = smincost[p.second] + 1;
                pque.push(P(smincost[nxt], nxt));
            }
        }
    }
}

void get_tmin(){
    pque.push(P(0,t));
    tmincost[t] = 0;
    while(!pque.empty()){
        P p = pque.top(); pque.pop();
        if(p.first > tmincost[p.second]) continue;
        for(int nxt : G[p.second]){
            if(tmincost[p.second] + 1 < tmincost[nxt]){
                tmincost[nxt] = tmincost[p.second] + 1;
                pque.push(P(tmincost[nxt], nxt));
            }
        }
    }
}

int main(){
    scanf("%d%d%d%d", &n, &m, &s, &t);
    s--, t--;
    fill(smincost, smincost+1050, INF);
    fill(tmincost, tmincost+1050, INF);
    for(int i = 0; i < 1050; i++){
        fill(adj[i], adj[i]+1050, 0);
    }
    for(int i = 0; i < m; i++){
        scanf("%d%d", &a, &b);
        a--,b--;
        adj[a][b] = 1;
        adj[b][a] = 1;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    get_smin();
    get_tmin();
    int least = smincost[t];
    //cout << "least: " << least << endl;
    int res = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(adj[i][j]) continue;
            if(min(smincost[i] + 1 + tmincost[j], tmincost[i] + 1 + smincost[j]) >= least) res ++;
        }
    }
    cout << res;
}