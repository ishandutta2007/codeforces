/*
ID: Sfiction
OJ: CF
PROB: 442C
*/
#include <cstdio>
#include <cstring>

const int MAXK=1005,MAXN=11;

char level[MAXK][MAXN][MAXN];
int map[MAXK][MAXK];
int n,m,k,w;

int dis[MAXK];
int from[MAXK];
char vis[MAXK];
int ans[MAXK][2];

void Init(){
    int i,j,l,t,t1;
    scanf("%d%d%d%d",&n,&m,&k,&w);
    for (l=1;l<=k;++l){
        map[0][l]=map[l][0]=n*m;
        for (i=0;i<n;++i)
            scanf("%s",&level[l][i][0]);
        for (t=1;t<l;++t){
            t1=0;
            for (i=0;i<n;++i)
                for (j=0;j<m;++j)
                    if (level[l][i][j]!=level[t][i][j])
                        ++t1;
            map[l][t]=map[t][l]=t1*w;
        }
    }
    return;
}
void Prim(){
    int i,j,t;
    int sum;
    sum=0;
    memset(vis,0,sizeof(vis));
    vis[0]=1;
    for (i=1;i<=k;++i){
        dis[i]=map[0][1];
        from[i]=0;
    }
    for (i=0;i<k;++i){
        for (t=0;vis[t];++t);
        for (j=t+1;j<=k;++j)
            if (vis[j]==0&&dis[j]<dis[t])
                t=j;
        vis[t]=1;
        sum+=dis[t];
        ans[i][0]=t;
        ans[i][1]=from[t];
        for (j=0;j<=k;++j)
            if (vis[j]==0&&dis[j]>map[t][j]){
                dis[j]=map[t][j];
                from[j]=t;
            }
    }
    printf("%d",sum);
    for (i=0;i<k;++i)
        printf("\n%d %d",ans[i][0],ans[i][1]);
}
int main(){
    Init();
    Prim();
    return 0;
}