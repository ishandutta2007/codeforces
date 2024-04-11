/*
ID: Sfiction
OJ: CF
PROB: 442A
*/
#include <cstdio>
#include <cstring>

const int MAXN=2000;

int type[MAXN];
int height[MAXN],mass[MAXN];
char vis[MAXN];
int n,h0;

void Init(){
    int i;
    scanf("%d%d",&n,&h0);
    for (i=0;i<n;++i){
        scanf("%d%d%d",&type[i],&height[i],&mass[i]);
    }
}
int Work(int tp){
    int i,h,sum;
    int maxm,id;
    h=h0;
    memset(vis,0,sizeof(vis));
    for (sum=0;1;++sum,tp=tp^1){
        maxm=-1;
        id=-1;
        for (i=0;i<n;++i)
            if (type[i]==tp&&vis[i]==0&&height[i]<=h&&maxm<mass[i]){
                maxm=mass[i];
                id=i;
            }
        if (id==-1)
            return sum;
        vis[id]=1;
        h+=mass[id];
    }
    return 0;
}
int main(){
    int a,b;
    Init();
    a=Work(0);
    b=Work(1);
    printf("%d",a>b?a:b);
    return 0;
}