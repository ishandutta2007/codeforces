#include<bits/stdc++.h>
using namespace std;
struct edge {
    int to,next;
    bool w;
}e[400010];
int head[200010],cnt,dp[200010];
inline void adde(int from,int to,bool w) {//
    e[++cnt]=(edge){to,head[from],w};
    head[from]=cnt;
}
void dfs1(int u,int f) {
    for (int i=head[u];i;i=e[i].next) 
        if (e[i].to!=f) {
            dfs1(e[i].to,u);
            dp[u]+=dp[e[i].to]+e[i].w;
        }
}
void dfs2(int u,int f) {
    for (int i=head[u];i;i=e[i].next)
        if (e[i].to!=f) {
            dp[e[i].to]=dp[u]+(e[i].w?-1:1);
            dfs2(e[i].to,u);
        }
}
int main() {
    int n,a,b;
    while (~scanf("%d",&n)) {
        cnt=0;
        memset(head,0,sizeof(head));
        for (int i=1;i<=n-1;i++) {
            scanf("%d%d",&a,&b);
            adde(a,b,false);adde(b,a,true);//
        }
        memset(dp,0,sizeof(dp));
        dfs1(1,-1);dfs2(1,-1);
        int Min=0x3f3f3f3f;
        for (int i=1;i<=n;i++) if (Min>dp[i]) Min=dp[i];
        printf("%d\n",Min);
        for (int i=1;i<=n;i++) if (Min==dp[i]) printf("%d ",i);
        printf("\n");
    }
}