#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define pb push_back
#define rep(i,j,k) for(i=(j);i<=(k);i++)
#define per(i,j,k) for(i=(j);i>=(k);i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
typedef long long LL;
typedef double db;
#define MAXN 110000
LL go[MAXN];LL len[MAXN];int n,g,r,q,i,j,k;
int tot=1;int v[MAXN*100];
int cl[MAXN*100],cr[MAXN*100];
void cov(int now,int L,int R,int x,int w){
    if(L==R){
        v[now]=w;
        return;
    }
    v[now]=w;
    int mid=(L+R)>>1;
    if(x<=mid){
        if(!cl[now])cl[now]=++tot;
        cov(cl[now],L,mid,x,w);
    }
    else
    {
        if(!cr[now])cr[now]=++tot;
        cov(cr[now],mid+1,R,x,w);
    }
}
int ask(int now,int L,int R,int x,int y){
    if(!now)return n+2;
    if(x<=L&&R<=y)return v[now];
    int res=n+2;int mid=(L+R)>>1;
    if(x<=mid)res=min(res,ask(cl[now],L,mid,x,y));
    if(y>mid)res=min(res,ask(cr[now],mid+1,R,x,y));
    return res;
}
int main(){
    scanf("%d%d%d",&n,&g,&r);
    rep(i,1,n+1){scanf("%I64d",&len[i]);len[i]+=len[i-1];}
    go[n+1]=0;
    per(i,n,1)
    {
        int u=(g+r)-(len[i]%(g+r));
        int c=n+2;
        if(u<=g)c=min(c,ask(1,0,g+r-1,g-u,g+r-u-1));
        else
        {
            c=min(c,ask(1,0,g+r-1,0,g+r-u-1));
            c=min(c,ask(1,0,g+r-1,(2*g+r-u)%(g+r),g+r-1));
        }
        if(c==n+2)go[i]=len[n+1]-len[i];
        else
        {
            go[i]=len[c]-len[i];
            go[i]+=1ll*(g+r)-1ll*(go[i]%(g+r));
            go[i]+=go[c];
         }
        cov(1,0,g+r-1,len[i]%(g+r),i);
    }
    scanf("%d",&q);
    while(q--){
        int t;scanf("%d",&t);int u=t%(g+r);
        int c=n+2;
        if(u<=g)c=min(c,ask(1,0,g+r-1,g-u,g+r-u-1));
        else
        {
            c=min(c,ask(1,0,g+r-1,0,g+r-u-1));
            c=min(c,ask(1,0,g+r-1,(2*g+r-u)%(g+r),g+r-1));
        }
        //printf("%d\n",c);
        if(c==n+2){
            printf("%I64d\n",len[n+1]+t);
            continue;
        }
        LL ans=len[c]+t;
        ans+=1ll*(g+r)-1ll*(ans%(g+r));
        ans+=go[c];
        printf("%I64d\n",ans);
    }
    return 0;
}