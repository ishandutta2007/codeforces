#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 500;

int n,a,b;
vector<int> G[N];
bool vis[N];
int ans = 0;

int dfs(int v){
    vis[v] = true;
    int res = 1;
    for(int nxt : G[v]){
        if(!vis[nxt]){
            res += dfs(nxt);
        }
    }
    if(res % 2 == 0){ans++;}
    return res;
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n-1; i++){
        scanf("%d%d", &a, &b);
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    if(n % 2 == 1) return !printf("-1");
    dfs(0);
    printf("%d", ans-1);

}