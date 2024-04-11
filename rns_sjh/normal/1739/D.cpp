
/* author : forever */

#include<bits/stdc++.h>
using namespace std;

#define N 200020

set<int> adj[N];
int n, k, p[N], dp[N], id[N];
bool vis[N];

void dfs(int u, int val){
    dp[u] = val;
    for(int v : adj[u]){
        dfs(v, val + 1);
    }
}

void dfs2(int u){
    vis[u] = 1;
    for(int v : adj[u]){
        if(!vis[v]) dfs2(v);
    }
}

bool cmp(int i, int j){
    return dp[i] > dp[j];
}

void process(){
    int st = 0, en = n - 1;
    dfs(1, 0);
    for(int i = 1;i <= n;i ++) id[i] = i;
    sort(id + 1, id + n + 1, cmp);
    while(en - st > 1){
        int mid = st + en >> 1;
        int temp = k, pos = 1;
        while(temp --){
            while(pos <= n && vis[id[pos]]) {pos ++;continue;}
            if(pos > n) break;
            int u = id[pos];
	    if(dp[u] <= mid) break;
            for(int i = 1;i < mid;i ++){
                u = p[u];
            }
            dfs2(u);
        }
        bool f = 0;
        for(int c = 1;c <= n;c ++){
            int i = id[c];
            if(!vis[i]){
                if(dp[i] > mid) f = 1;
                break;
            }
        }
        if(f) st = mid;
        else en = mid;
        for(int i = 1;i <= n;i ++) vis[i] = 0;
    }
    cout << en << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int tcase;
    for(cin >> tcase;tcase --;){
        cin >> n >> k;
        for(int i = 1;i <= n;i ++) adj[i].clear(), vis[i] = 0;
        for(int i = 2;i <= n;i ++) cin >> p[i], adj[p[i]].insert(i);
        process();

    }
    return 0;
}