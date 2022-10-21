#include <bits/stdc++.h>
using namespace std;

int n,m,a,b,s;
vector<int> G[200500];
stack<int> S,cS;
bool vis[200500];
int cyc[200500];

int good(int k){
    return k >= n ? k - n + 1: k + 1;
}

bool dfs(int v){
    vis[v] = true;
    S.push(v);
    if(G[v].size() == 0 && v >= n){
        return true;
    }
    for(int nxt : G[v]){
        if(!vis[nxt] && dfs(nxt)) return true;
    }
    S.pop();
    return false;
}

bool cdfs(int v){
    cyc[v] = -1;
    for(int nxt : G[v]){
        if(cyc[nxt] == -1)
            return true;
        if(cyc[nxt] == 0)
            if(cdfs(nxt)) return true;
    }

    cyc[v] = 1;
    return false;
}


int main(){
    fill(vis, vis+200500, false);
    fill(cyc, cyc+200500, 0);
    scanf("%d%d", &n, &m);
    for(int i = 0; i  < n; i++){
        scanf("%d", &a);
        for(int j = 0; j < a; j++){
            scanf("%d", &b);
            b--;
            G[i].push_back(b+n);
            G[i+n].push_back(b);
        }
    }
    scanf("%d", &s);
    s--;
    if(dfs(s)){
        printf("Win\n");
        vector<int> V;
        while(!S.empty()){
            V.push_back(S.top());
            S.pop();
        }
        for(int i = V.size()-1; i >= 0; i--) printf("%d ", good(V[i]));
    }
    else if(cdfs(s)){
        printf("Draw\n");
    }
    else{
        printf("Lose");
    }

}