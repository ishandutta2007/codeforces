#include <iostream>
#include <vector>
using namespace std;
const int N=2002;

int n,m;
char s[N][N];
int par[N],deg[N],vis[N];
vector<int> g[N];

int find(int x){
    return par[x]==x?x:par[x]=find(par[x]);
}

int len[N];
void dfs(int u){
    vis[u]=1; len[u]=1;
    for(auto v: g[u]){
        if(v==u) {
            printf("No\n"); exit(0);
        }
        if(vis[v]==1) {
            printf("No\n"); exit(0); return;
        } else
        if(vis[v]==2) {
            len[u]=max(len[u], len[v]+1);
        } else {
            dfs(v);
            len[u]=max(len[u], len[v]+1);
        }
    }
    vis[u]=2;
}
int main(){
    for(int i=1;i<N;i++)par[i]=i;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%s", s[i]+1);

    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
        if(s[i][j]=='=') par[find(i)]=find(n+j);

    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
        if(s[i][j]=='>') g[find(i)].push_back(find(n+j)), deg[find(n+j)]++;
        else if(s[i][j]=='<') g[find(n+j)].push_back(find(i)), deg[find(i)]++;
    }

    for(int i=1;i<=n+m;i++){
        if(deg[i]==0) {
            dfs(i);
        }
    }
    for(int i=1;i<=n+m;i++){
        if(vis[i]!=2)return !printf("No\n");
    }
    printf("Yes\n");
    for(int i=1;i<=n;i++) printf("%d ", len[find(i)]); printf("\n");
    for(int i=1;i<=m;i++) printf("%d ", len[find(n+i)]); printf("\n");
}