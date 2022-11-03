/*
ID: Sfiction
OJ: CF
PROB: 103B
*/
#include <cstdio>
#include <cstring>

const int MAXN=101;

char map[MAXN][MAXN];
char vis[MAXN];
int n,m,sum;

void DFS(int now){
    vis[now]=1;
    sum+=1;
    for (int i=1;i<=n;++i)
        if (map[now][i]&&vis[i]==0)
            DFS(i);
}
int main(){
    scanf("%d%d",&n,&m);
    if (n!=m){
        printf("NO");
        return 0;
    }
    for (int u,v,i=0;i<m;++i){
        scanf("%d%d",&u,&v);
        map[u][v]=map[v][u]=1;
    }
    memset(vis,0,sizeof(vis));
    DFS(1);
    if (sum==n)
        printf("FHTAGN!");
    else
        printf("NO");
    return 0;
}