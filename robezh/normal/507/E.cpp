#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;
const int MAXN = (int)1e5 + 500;

int n,m,a,b,z, cnt[2];
int dis[2][MAXN];
int pre[MAXN], dp[MAXN], mind;
bool vis[MAXN];
queue<P> que;
map<P, int> mp;
vector<P> G[MAXN];

void bfs(int t, int now){
    fill(vis, vis+n, 0);
    que.push(P(now,0)); vis[now] = 1;
    dis[t][now] = 0;
    while(!que.empty()){
        P p = que.front(); que.pop();
        int i = p.first, d = p.second;
        for(P nxtp : G[i]){
            int nxti = nxtp.first;
            if(!vis[nxti]){
                dis[t][nxti] = d + 1;
                vis[nxti] = 1;
                que.push(P(nxti, d+1));
            }
        }
    }
}

int dfs(int v){
    if(dp[v] != -1) return dp[v];

    if(v == n-1) return dp[n-1] = 0;

    for(P nxtp : G[v]){
        int nxti = nxtp.first;
        if(dis[0][nxti] + dis[1][nxti] != mind || dis[0][nxti] != dis[0][v]+1) continue;
        int nxtdp = dfs(nxti);
        if(nxtdp + (nxtp.second == 1) > dp[v]){
            dp[v] = nxtdp + (nxtp.second == 1);
            pre[v] = nxti;
        }
    }
    return dp[v];
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++){
        scanf("%d%d%d", &a, &b, &z);
        a--, b--; cnt[z] ++;
        G[a].push_back(P(b,z));
        G[b].push_back(P(a,z));
        mp[P(min(a,b),max(a,b))] = z;
    }
    bfs(0,0), bfs(1,n-1);
    mind = dis[0][n-1];

    fill(dp, dp+n, -1);
    dfs(0);
    //cout << dp[0] << endl;
    printf("%d\n", cnt[1] + mind - 2 * dp[0]);

    int v = 0;
    while(v != n-1){
        int a = v, b = pre[v];
        P p = P(min(a,b), max(a,b));
        if(mp.count(p)){
            if(mp[p] == 0) printf("%d %d %d\n", a+1, b+1, 1);
            mp.erase(p);
        }
        v = pre[v];
    }
    for(auto p : mp){
        if(p.second == 1){
            printf("%d %d %d\n", p.first.first + 1, p.first.second + 1, 0);
        }
    }
}