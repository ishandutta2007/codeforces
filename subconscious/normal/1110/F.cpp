#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define rez(i,n) for(int i=0;i<n;++i)
#define rev(i,n) for(int i=n;i;--i)
#define x0 fxxkcjb0
#define y0 fxxkcjb1
#define x1 fxxkcjb2
#define y1 fxxkcjb3
#define eb emplace_back
#define fr first
#define sc second
using namespace std;
using namespace std::placeholders;
using ll=long long;
using ld=long double;
using pr=pair<int,int>;
const int N=1e6+5,MOD=1e9+7;
const ll inf=1e17;
int p[N],w[N],n,Q;
struct quee{int v,l,r,key;}q[N];
ll ans[N];
vector<int>sn[N];
ll mi[N<<1],hd[N<<1];
void add(int p,int l,int r,int x,int y,ll c){
    if(x<=l&&r<=y){hd[p]+=c;return;}
    int mid=(l+r)>>1;
    if(x<=mid)add(p<<1,l,mid,x,y,c);
    if(mid+1<=y)add(p<<1|1,mid+1,r,x,y,c);

    mi[p]=min(mi[p<<1]+hd[p<<1],mi[p<<1|1]+hd[p<<1|1]);
}
ll que(int p,int l,int r,int x,int y){
    if(x<=l&&r<=y)return mi[p]+hd[p];

    mi[p]+=hd[p];
    hd[p<<1]+=hd[p];
    hd[p<<1|1]+=hd[p];
    hd[p]=0;

    int mid=(l+r)>>1;ll ans=inf;
    if(x<=mid)ans=min(ans,que(p<<1,l,mid,x,y));
    if(mid+1<=y)ans=min(ans,que(p<<1|1,mid+1,r,x,y));
    return ans;
}
ll dep[N];
int la[N];
void init(int x){
    la[x]=x;
    for(int p:sn[x])dep[p]=dep[x]+w[p],init(p),la[x]=max(la[x],la[p]);
    if(sn[x].size()==0)add(1,1,n,x,x,dep[x]);
    else add(1,1,n,x,x,inf);
}
int now=1;
ll wr;
void dfs(int x){
    //printf("%d\n",x);
    add(1,1,n,x,la[x],-2ll*w[x]);wr+=w[x];
    while(now<=Q&&q[now].v==x)ans[q[now].key]=wr+que(1,1,n,q[now].l,q[now].r),++now;
    for(int p:sn[x])dfs(p);
    add(1,1,n,x,la[x],2ll*w[x]);wr-=w[x];
}
bool cmp(const quee&x,const quee&y){return x.v<y.v;}
int main(){
    scanf("%d%d",&n,&Q);
    rep(i,n-1)scanf("%d%d",p+i+1,w+i+1),sn[p[i+1]].eb(i+1);
    rep(i,Q)scanf("%d%d%d",&q[i].v,&q[i].l,&q[i].r),q[i].key=i;
    init(1);
    sort(q+1,q+Q+1,cmp);
    wr=0;dfs(1);
    rep(i,Q)printf("%lld\n",ans[i]);
    return 0;
}