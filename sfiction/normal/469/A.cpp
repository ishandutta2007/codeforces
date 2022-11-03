/*
ID: Sfiction
OJ: CF
PROB: 469A
*/
#include <cstdio>
#include <cstring>

const int MAXN=100+10;

int n;
bool vis[MAXN];

int main(){
    int na,nb;
    memset(vis,false,sizeof(vis));
    
    scanf("%d",&n);
    scanf("%d",&na);
    for (int i=0;i<na;++i){
        int t;
        scanf("%d",&t);
        vis[t]=true;
    }
    scanf("%d",&nb);
    for (int i=0;i<nb;++i){
        int t;
        scanf("%d",&t);
        vis[t]=true;
    }
    bool flag=true;
    for (int i=1;i<=n;++i)
        flag&=vis[i];
    if (flag)
        printf("I become the guy.");
    else
        printf("Oh, my keyboard!");
    return 0;
}