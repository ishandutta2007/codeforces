#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
const int N=110000;
int c[N];
int head[N],np[N<<1],p[N<<1],tot;
int n;
int fa[N];
int q[N];
bool check(int rt){
    memset(fa,0,sizeof fa);
    q[q[0]=1]=rt;
    rep(i,1,q[0]){
        int x=q[i];
        for(int u=head[x];u;u=np[u])if(p[u]^fa[x]){
            fa[p[u]]=x;q[++q[0]]=p[u];
        }
    }
    rep(i,2,q[0])if(fa[q[i]]!=rt)if(c[q[i]]!=c[fa[q[i]]])return 0;
    return 1;
}
int main(){
    scanf("%d",&n);
    rep(i,1,n-1){
        int a,b;scanf("%d%d",&a,&b);
        ++tot;p[tot]=b;np[tot]=head[a];head[a]=tot;
        ++tot;p[tot]=a;np[tot]=head[b];head[b]=tot;
    }
    rep(i,1,n)scanf("%d",&c[i]);
    rep(i,1,n)for(int u=head[i];u;u=np[u])if(c[p[u]]!=c[i]){
        if(check(p[u])){
            printf("YES\n%d\n",p[u]);
            return 0;
        }
        if(check(i)){
            printf("YES\n%d\n",i);
            return 0;
        }
        printf("NO\n");
        return 0;
    }
    printf("YES\n1\n");
    return 0;
}