#include <bits/stdc++.h>
using namespace std;

#define MAXN 200050

int n,m;
int a,b;
set<int> unvisited;
int cc = 0;
set<int> G[MAXN];
vector<int> comps;

void dfs(int v){
    unvisited.erase(v);
    comps[cc-1]++;
    int cur = -1;
    while(true){
        auto next = unvisited.upper_bound(cur);
        if(next == unvisited.end()) break;
        cur = *next;
        if(G[v].count(*next)) continue;
        dfs(*next);
    }
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) unvisited.insert(i);
    for(int i = 0; i < m; i++){
        scanf("%d%d", &a, &b);
        a--, b--;
        G[a].insert(b);
        G[b].insert(a);
    }

    for(int i = 0; i < n; i++){
        if(unvisited.count(i)){
            cc++;
            comps.push_back(0);
            dfs(i);
        }
    }
    sort(comps.begin(), comps.end());
    printf("%d\n", comps.size());
    for(int i = 0; i < cc; i++) printf("%d ", comps[i]);
}