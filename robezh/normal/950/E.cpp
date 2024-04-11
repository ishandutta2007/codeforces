#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100500;

vector<int> G[2*MAXN];
vector<int> rG[2*MAXN];
vector<int> vs;
bool vis[2*MAXN];
int cmp[2*MAXN];
int cnt[2*MAXN];
bool w[2*MAXN];

int n,m,h;
int t[MAXN];
int a,b;

void add_edge(int a, int b){
    G[a].push_back(b);
    rG[b].push_back(a);
}

void dfs(int v){
    vis[v] = true;
    for(int nxt : G[v]){
        if(!vis[nxt]) dfs(nxt);
    }
    vs.push_back(v);
}

void rdfs(int v, int k){
    cmp[v] = k;
    if(v < n) cnt[k] ++;
    //cnt[k]++;
    vis[v] = true;
    for(int nxt: rG[v]){
        if(!vis[nxt]) rdfs(nxt, k);
    }
}

int scc(){
    fill(cnt, cnt + 2*MAXN, 0);
    fill(vis, vis + 2*MAXN, false);
    vs.clear();
    for(int i = 0; i < 2 * n; i++){
        if(!vis[i]) dfs(i);
    }

    int kscc = 0;
    fill(vis,vis + 2*MAXN,false);
    for(int i = vs.size() - 1; i >= 0; i--){
        if(!vis[vs[i]]) rdfs(vs[i],kscc++);
    }
    return kscc;
}


int main(){
    scanf("%d%d%d", &n, &m, &h);
    for(int i = 0; i < n; i++){
        scanf("%d", &t[i]);
    }
    for(int i = 0; i < m; i++){
        scanf("%d%d", &a, &b);
        a--,b--;
        if((t[a]+1)%h == t[b]){
            add_edge(a, b);
            add_edge(b+n, a+n);
        }
        if((t[b]+1)%h == t[a]){
            add_edge(b, a);
            add_edge(a+n, b+n);
        }
        if(t[a] == t[b]){
            add_edge(a, b+n);
            add_edge(a+n, b);
            add_edge(b, a+n);
            add_edge(b+n, a);
        }
    }
    int kscc = scc();
    fill(w, w+2*MAXN, 0);
    for(int i = 0; i < 2 * n; i++){
        for(int j : G[i]){
            if(cmp[j] != cmp[i] || cnt[cmp[i]] == 0) w[cmp[i]] = true;
        }
    }

    int res = -1;
    for(int i = 0; i < kscc; i++){
        if(!w[i] && (cnt[i] != 0 && (res == -1 || cnt[i] < cnt[res]))) res = i;
    }
    cout << cnt[res] << endl;
    for(int i = 0; i < n; i++){
        if(cmp[i] == res) cout << i+1 << " ";
    }

}