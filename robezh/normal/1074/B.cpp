#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n;
vector<int> G[N];
int k1,k2;
int ori[N], chen[N];
bool vis[N];
int lab[2][N];

int dfs(int v){
    if(ori[v]) return v;
    vis[v] = true;
    for(int nxt : G[v]){
        if(!vis[nxt]){
            int cur = dfs(nxt);
            if(cur != -1) return cur;
        }
    }
    return -1;
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        fill(ori, ori+N, 0);
        fill(chen, chen+N, 0);
        fill(vis, vis+N, false);
        for(int i = 0; i < N; i++) G[i].clear();
        scanf("%d", &n);
        for(int i = 0; i < n - 1; i++){
            int a, b;
            scanf("%d%d", &a, &b);
            G[a].push_back(b);
            G[b].push_back(a);
        }
        scanf("%d", &k1);
        for(int i = 0; i < k1; i++){
            scanf("%d", &lab[0][i]);
            ori[lab[0][i]] = 1;
        }
        scanf("%d", &k2);
        for(int i = 0; i < k2; i++){
            scanf("%d", &lab[1][i]);
            chen[lab[1][i]] = 1;
        }

        printf("B %d\n", lab[1][0]);
        fflush(stdout);
        int s;
        cin >> s;
        if(ori[s]){
            printf("C %d\n", s);
            fflush(stdout);
            continue;
        }
        else{
            int nxt = dfs(s);
            printf("A %d\n", nxt);
            fflush(stdout);
            int ts;
            cin >> ts;
            if(chen[ts]){
                printf("C %d\n", nxt);
                fflush(stdout);
                continue;
            }
            else{
                printf("C -1\n");
                fflush(stdout);
                continue;
            }
        }
    }
}