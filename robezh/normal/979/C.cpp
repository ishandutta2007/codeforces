#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)3e5 + 500;

int n,x,y,a,b;
bool vis[N], hav[N];
vector<int> G[N];

bool dfs(int v){
    vis[v] = true;
    for(int nxt : G[v]){
        if(nxt == y){hav[v] = true; return true;}
        if(!vis[nxt]){
            if(dfs(nxt)){
                hav[v] = true;
                return true;
            }
        }
    }
    return false;
}

ll dfs2(int v){
    vis[v] = true;
    ll res = 0;
    for(int nxt : G[v]){
        if(!vis[nxt]) res += dfs2(nxt);
    }
    return res+1;
}

int main() {
    scanf("%d%d%d", &n, &x, &y);
    x--, y--;
    for(int i = 0; i < n-1; i++){
        scanf("%d%d", &a, &b);
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(x);
    hav[y] = true;
    for(int i = 0; i < n; i++) vis[i] = hav[i];
    //for(int i = 0; i < n; i++) if(vis[i]) cout << i << " ";
    //cout << endl;

    ll ans = 1LL * n * (n-1) - dfs2(x) * dfs2(y);

    cout << ans;

}