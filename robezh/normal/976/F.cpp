#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

const int N = 4050, INF = (int)1e9;

struct edge{
    int to, cap, rev, id;
    edge(int _to, int _cap, int _rev, int _id){
        to = _to, cap = _cap, rev = _rev, id = _id;
    }
};

vector<edge> G[N];
bool used[N];

void add_edge(int from, int to, int cap, int id){
    G[from].push_back(edge(to, cap, G[to].size(), id));
    G[to].push_back(edge(from, 0, G[from].size() - 1, id));
}

int dfs(int v, int t, int f){
    if(v == t) return f;
    used[v] = true;

    for(int i = 0; i < G[v].size(); i++){
        edge &e = G[v][i];
        if(!used[e.to] && e.cap > 0){
            int d = dfs(e.to, t, min(e.cap, f));
            if(d > 0){
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int max_flow(int s, int t){
    int f = 0;
    for(;;){
        fill(used, used + N, false);
        int d = dfs(s, t, INF);
        if(d == 0) return f;
        f += d;
    }
}

int n1, n2, m;
int cnt1[N], cnt2[N];
int mind;
vector<int> res[N];

int main(){
    scanf("%d%d%d", &n1, &n2, &m);
    int s = n1 + n2, t = n1 + n2 + 1;

    for(int i = 0; i < m; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        a--, b--;
        add_edge(a, b + n1, 1, i);
        cnt1[a] ++, cnt2[b] ++;
    }
    mind = INF;
    for(int i = 0; i < n1; i++) mind = min(mind, cnt1[i]);
    for(int i = 0; i < n2; i++) mind = min(mind, cnt2[i]);

    for(int i = 0; i < n1; i++) add_edge(s, i, cnt1[i] - mind, -1);
    for(int i = 0; i < n2; i++) add_edge(i + n1, t, cnt2[i] - mind, -1);

    for(int i = mind; i >= 0; i--){
        max_flow(s, t);
        for(int j = 0; j < n1; j++){
            for(auto p : G[j]) if(p.id >= 0 && p.cap > 0) res[i].push_back(p.id);
        }
        for(auto &p : G[s]) p.cap ++;
        for(auto &p : G[t]) G[p.to][p.rev].cap ++;
    }
    for(int i = 0; i <= mind; i++){
        printf("%d ", res[i].size());
        for(int x : res[i]) printf("%d ", x + 1);
        printf("\n");
    }

}