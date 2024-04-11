#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
const int N=210000;
int a[N],n;
int head[N],np[N*22],p[N*22],tot;
inline void add(int a,int b){
    ++tot;p[tot]=b;np[tot]=head[a];head[a]=tot;
}
int seg[N<<2];
int ma[N<<2];
int mi[N<<2];
int cov[N<<2];
LL sum[N<<2];
int lst[N];
int cnt[N];
inline void down(int me,int l,int r){
    if(!cov[me])return;
    int mid=(l+r)>>1;
    cov[me<<1]=cov[me<<1|1]=cov[me];
    sum[me<<1]=cov[me]*1ll*(mid-l+1);
    sum[me<<1|1]=cov[me]*1ll*(r-mid);
    ma[me<<1]=ma[me<<1|1]=mi[me<<1]=mi[me<<1|1]=cov[me];
    cov[me]=0;
}
void Cov(int me,int l,int r,int x,int y,int w){
    if(x>y)return;
    if(mi[me]>=w)return;
    if(l^r)down(me,l,r);
    if(x<=l&&r<=y&&ma[me]<=w){
        cov[me]=w;
        ma[me]=mi[me]=w;
        sum[me]=(r-l+1)*1ll*w;
        return;
    }
    int mid=(l+r)>>1;
    if(x<=mid)Cov(me<<1,l,mid,x,y,w);
    if(y>mid)Cov(me<<1|1,mid+1,r,x,y,w);
    ma[me]=max(ma[me<<1],ma[me<<1|1]);
    mi[me]=min(mi[me<<1],mi[me<<1|1]);
    sum[me]=sum[me<<1]+sum[me<<1|1];
}
LL getsum(int me,int l,int r,int x,int y){
    if(x>y)return 0;
    if(x<=l&&r<=y)return sum[me];
    if(l^r)down(me,l,r);
    LL ans=0;
    int mid=(l+r)>>1;
    if(x<=mid)ans+=getsum(me<<1,l,mid,x,y);
    if(y>mid)ans+=getsum(me<<1|1,mid+1,r,x,y);
    return ans;
}
int main(){
    scanf("%d",&n);
    rep(i,1,n)scanf("%d",&a[i]);
    rep(i,1,200000)rep(j,1,200000/i)add(i*j,i);
    per(i,n,1){
        if(cnt[a[i]]==2)continue;
        for(int u=head[a[i]];u;u=np[u]){
            int x=p[u];
            ++cnt[x];
            if(cnt[x]>2)continue;
            if(cnt[x]==2){
                Cov(1,1,n+1,1,i,x);
            }
            if(cnt[x]==1)lst[x]=i;
        }
    }
    memset(cnt,0,sizeof cnt);
    LL ans=getsum(1,1,n+1,2,n+1);
    rep(i,1,n){
        for(int u=head[a[i]];u;u=np[u]){
            int x=p[u];
            ++cnt[x];
            if(cnt[x]>2)continue;   
            if(cnt[x]==1)if(lst[x]){
                Cov(1,1,n+1,1,lst[x],x);
            }
            if(cnt[x]==2){
                Cov(1,1,n+1,1,n+1,x);
            }
        }
        if(i+2<=n+1)ans+=getsum(1,1,n+1,i+2,n+1);
    }
    printf("%I64d\n",ans);
    return 0;
}