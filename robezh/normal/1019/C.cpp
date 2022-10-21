#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e6 + 500;

int n,m,a,b;
vector<int> G[N];
bool in[N];
bool vis[N];
vector<int> pt, res;

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++){
        scanf("%d%d", &a, &b);
        a--, b--;
        G[a].push_back(b);
    }
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            vis[i] = true;
            pt.push_back(i);
            for(int nxt : G[i]) vis[nxt] = true;
        }
    }
    while(!pt.empty()){
        int cur = pt.back(); pt.pop_back();
        if(!in[cur]){
            res.push_back(cur);
            for(int nxt : G[cur]) in[nxt] = true;
        }
    }
    printf("%d\n", res.size());
    for(int x : res) printf("%d ", x+1);
}