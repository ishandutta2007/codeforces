#include <bits/stdc++.h>
using namespace std;

const int N = (int)2e5 + 500;

int n,a,b;
vector<int> G[N];
int seq[N], dis[N];
int ord[N], cnt[N];
bool vis[N];

void bfs(){
    fill(vis, vis + N, 0);
    dis[1] = 0;
    vis[1] = true;
    queue<int> que;
    que.push(1);
    while(!que.empty()){
        int i = que.front(); que.pop();
        for(int nxt : G[i]){
            if(!vis[nxt]){
                vis[nxt] = true;
                dis[nxt] = dis[i] + 1;
                que.push(nxt);
            }
        }
    }

}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n-1; i++){
        scanf("%d%d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    bfs();
    for(int i = 0; i < n; i++) scanf("%d", &seq[i]);
    for(int i = 1; i < n; i++) if(dis[seq[i]] < dis[seq[i-1]]) return !printf("No");

    fill(cnt, cnt+N, 0);
    fill(vis, vis+N, false);
    vis[1] = true;
    for(int i = 0; i < n; i++){
        if(i != 0 && dis[seq[i]] == dis[seq[i-1]] && ord[seq[i]] < ord[seq[i-1]]) return !printf("No");
        int cur = cnt[dis[seq[i]]]++;
        for(int nxt : G[seq[i]]){

            if(!vis[nxt]){
                vis[nxt] = true;
                ord[nxt] = cur;
            }
        }
    }
    //for(int i = 0; i < n; i++) cout << ord[i] << " ";
    return !printf("Yes");
}