#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 500;
typedef pair<int, int> P;

int n,m,s,k,a,b;
int kind[N], res[N];
int dis[N][105];
bool vis[N];
vector<int> G[N];

void bfs(int t){
    fill(vis, vis+n, false);
    queue<P> que;
    for(int i = 0; i < n; i++){
        if(kind[i] == t){
            vis[i] = true;
            que.push(P(i,0));
            dis[i][t] = 0;
        }
    }
    while(!que.empty()){
        P p = que.front(); que.pop();
        int i = p.first, dist = p.second;
        for(int nxt : G[i]){
            if(!vis[nxt]){
                vis[nxt] = true;
                dis[nxt][t] = dist+1;
                que.push(P(nxt, dist+1));
            }
        }
    }
}

int main(){
    scanf("%d%d%d%d", &n, &m, &k, &s);
    for(int i = 0; i < n; i++) scanf("%d", &kind[i]);
    for(int i = 0; i < m; i++){
        scanf("%d%d", &a, &b); a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i = 1; i <= k; i++) bfs(i);
    for(int i = 0; i < n; i++) sort(dis[i]+1, dis[i]+k+1);
    for(int i = 0; i < n; i++){
        for(int j = 1; j <= s; j++){
            res[i] += dis[i][j];
        }
    }
    for(int i = 0; i < n; i++) printf("%d ", res[i]);

}