#include <bits/stdc++.h>
using namespace std;

const int N = (int)2e5 + 500;

int n;
int c[N], nxt[N];
vector<int> G[N], rG[N], vs;
bool used[N];
int cmp[N];
vector<int> Gn[N];
int cn[N];

void add_edge(int from, int to){
    G[from].push_back(to);
    rG[to].push_back(from);
}

void dfs(int v){
    used[v] = true;
    for(int nxt : G[v]){
        if(!used[nxt]) dfs(nxt);
    }
    vs.push_back(v);
}

void rdfs(int v, int k){
    used[v] = true;
    cmp[v] = k;
    for(int nxt : rG[v]){
        if(!used[nxt]) rdfs(nxt, k);
    }
}

void dfsn(int v){
    used[v] = true;
    for(int nxt : Gn[v]){
        if(!used[nxt]) dfsn(nxt);
    }
}


int scc(){
    memset(used, 0, sizeof(used));
    vs.clear();
    for(int v = 0; v < n; v++){
        if(!used[v]) dfs(v);
    }
    memset(used, 0, sizeof(used));
    int k = 0;
    reverse(vs.begin(), vs.end());
    for(int v : vs){
        if(!used[v]) rdfs(v, k++);
    }
    return k;
}


int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &c[i]);
    for(int i = 0; i < n; i++){
        scanf("%d", &nxt[i]);
        nxt[i]--;
        add_edge(i, nxt[i]);
    }
    fill(cn, cn+N, N);
    int sc = scc();
    for(int i = 0; i < n; i++){
        Gn[cmp[nxt[i]]].push_back(cmp[i]);
        cn[cmp[i]] = min(cn[cmp[i]], c[i]);
    }
    int res = 0;
    fill(used, used + sc, false);
    for(int i = sc-1; i >= 0; i--){
        if(!used[i]){
            dfsn(i);
            res += cn[i];
        }
    }
    cout << res << endl;
}