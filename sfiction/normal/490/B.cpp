/*
ID: Sfiction
OJ: CF
PROB: 490B
*/
#include <cstdio>
#include <cstring>

const int MAXN=1000000+100;

int n;
int pre[MAXN],nex[MAXN];

int main(){
    int u,v;
    scanf("%d",&n);
    memset(pre,-1,sizeof(pre));
    memset(nex,-1,sizeof(nex));
    for (int i=0;i<n;++i){
        scanf("%d%d",&u,&v);
        nex[u]=v;
        pre[v]=u;
    }
    for (int i=0;i<MAXN;++i)
        if (nex[i]!=-1 && pre[i]==-1){
            v=i;
            break;
        }
    printf("%d",v);
    v=nex[v];
    u=nex[0];
    for (int i;u>0 || v>0;++i){
        if (u>0){
            printf(" %d",u);
            u=nex[u];
        }
        if (v>0){
            printf(" %d",v);
            v=nex[v];
        }
    }
    return 0;
}