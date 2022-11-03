/*
ID: Sfiction
OJ: CF
PROB: 101A
*/
#include <cstdio>
const int MAXN=100+10;
const int INF=1<<30;

char map[MAXN][MAXN];
int price[MAXN];
int n,m;

void Init(){
    int i,u,v;
    scanf("%d%d",&n,&m);
    for (i=1;i<=n;++i)
        scanf("%d",&price[i]);
    for (i=1;i<=m;++i){
        scanf("%d%d",&u,&v);
        map[u][v]=map[v][u]=1;
    }
}
int main(){
    int i,j,k;
    int ans=INF;
    Init();
    for (i=1;i<=n;++i)
        for (j=i+1;j<=n;++j)
            for (k=j+1;k<=n;++k)
                if (map[i][j]&&map[i][k]&&map[j][k]){
                    if (ans>price[i]+price[j]+price[k])
                        ans=price[i]+price[j]+price[k];
                }
    printf("%d",ans==INF?-1:ans);
    return 0;
}