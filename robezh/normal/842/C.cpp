#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200050;

int gcd(int x, int y){
    return x == 0 ? y : gcd(y%x, x);
}

int n,a,b,now;
vector<int> G[MAXN];
int num[MAXN];
vector<int> di;
int ans[MAXN];
bool vis[MAXN];

void dfs(int v){
    vis[v] = true;
    for(int nxt : G[v]){
        if(!vis[nxt]){
            if(v == 0) ans[nxt] = num[nxt];
            else ans[nxt] = gcd(ans[v], num[nxt]);
            dfs(nxt);
        }
    }
}

void dfs2(int v, int c){
    vis[v] = true;
    for(int nxt : G[v]){
        if(!vis[nxt]){
            if(num[nxt] % now != 0){
                if(c >= 1) continue;
                ans[nxt] = max(ans[nxt], now);
                dfs2(nxt, 1);
            }
            else{
                ans[nxt] = max(ans[nxt], now);
                dfs2(nxt, c);
            }

        }
    }
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){scanf("%d", &num[i]);}
    for(int i = 0; i < n-1; i++){
        scanf("%d%d", &a, &b);
        a--,b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i = 1; i <= num[0]; i++){if(num[0] % i == 0) di.push_back(i);}

    fill(vis, vis+n, 0);
    ans[0] = num[0];
    dfs(0);

    for(int divi : di){
        fill(vis, vis+n, 0);
        now = divi;
        dfs2(0, 0);
    }

    for(int i = 0; i < n; i++){printf("%d ", ans[i]);}
}