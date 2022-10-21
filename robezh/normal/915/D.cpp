#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;

int n,m,a,b;
vector<int> G[505];
vector<P> del;
int cyc[505];

bool cdfs(int v){
    cyc[v] = -1;

    for(int i = 0; i < G[v].size(); i++){
        int nxt = G[v][i];
        if(cyc[nxt] == -1){
            del.push_back(P(v,i));
            return true;
        }
        if(cyc[nxt] == 0 && cdfs(nxt)){
            del.push_back(P(v,i));
            return true;
        }
    }
    cyc[v] = 1;
    return false;
}

bool pdfs(int v){
    cyc[v] = -1;
    for(int nxt : G[v]){
        if(cyc[nxt] == -1) return true;
        if(cyc[nxt] == 0 && pdfs(nxt)) return true;
    }
    cyc[v] = 1;
    return false;
}

bool check_cdfs(){
    for(int i = 0; i < n; i++){
        if(cyc[i] == 0 && cdfs(i)) return true;
    }
    return false;
}

bool check_pdfs(){
    for(int i = 0; i < n; i++){
        if(cyc[i] == 0 && pdfs(i)) return true;
    }
    return false;
}

bool solve(){
    if(!check_cdfs()) return true;

    for(P p : del){
        fill(cyc, cyc+505, 0);
        int nxt = G[p.first][p.second];
        G[p.first][p.second] = n;
        if(!check_pdfs()) return true;
        G[p.first][p.second] = nxt;
    }
    return false;
}

int main(){
    fill(cyc, cyc+505, 0);
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++){
        scanf("%d%d",&a, &b);
        a--, b--;
        G[a].push_back(b);
    }
    if(solve()) return !printf("YES");
    else return !printf("NO");
}