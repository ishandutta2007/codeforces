#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 500, INF = (int)1e9 + 500;

int n,k;
vector<int> G[N];
bool ini[N], vis[N];
int cnt[N], dis[N];

int main(){
    fill(dis, dis+N, INF);
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n - 1; i++){
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    queue<int> que;
    for(int i = 0; i < n; i++){
        if(G[i].size() == 1){
            ini[i] = true;
            vis[i] = true;
            dis[i] = 0;
            que.push(i);
        }
    }
    while(!que.empty()){
        int i = que.front(); que.pop();
        if(que.empty()){
            if(dis[i] != k || cnt[i] < 3) return !printf("NO");
            return !printf("YES");
        }
//        if(dis[i] == k) return !printf("NO");
        if(!ini[i] && cnt[i] < 3) return !printf("NO");
        bool ok = false;
        for(int nxt : G[i]){
            if(dis[nxt] > dis[i] + 1){
                dis[nxt] = dis[i] + 1;
                cnt[nxt] = 1;
                que.push(nxt);
                ok = true;
            }
            else if(dis[nxt] == dis[i] + 1){
                cnt[nxt] ++;
                ok = true;
            }
        }
        if(!ok) return !printf("NO");
    }
    return !printf("NO");
}