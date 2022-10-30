#include<bits/stdc++.h>
using namespace std;
#define N 111
int n;
int a[N], b[N];
vector<int > v[N];
int vis[N];
int flag[N];
bool fg;
void dfs(int u, int C) {
    vis[u] = C;
    int sz = v[u].size();
    for(int i = 0; i <sz; i ++) {
        int ii = v[u][i];
        if(!vis[ii]) dfs(ii, C);
    }
}

int main(){
   // freopen("B.in","r",stdin);
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    for(int i= 1; i <= n; i ++) scanf("%d", &b[i]);
    for(int i = 1; i <= n; i ++) {
        for(int j = i + 1; j <= n; j ++) {
            if(j - i == b[i] || j - i == b[j]){
                v[i].push_back(j);
                v[j].push_back(i);
            }
        }
    }
    int c = 0;
    fg = 1;
    for(int i = 1; i <= n; i ++) if(!vis[i]) {
        c ++;
        dfs(i, c);
        memset(flag, 0, sizeof(flag));
        for(int j = 1; j <= n; j ++) if(vis[j] == c) flag[j] = 1;
        for(int j = 1; j <= n; j++)
            if(vis[j] == c && !flag[a[j]]){ fg = 0; break;}
        if(!fg) break;
    }
    if(!fg) puts("NO");
    else puts("YES");
    return 0;
}