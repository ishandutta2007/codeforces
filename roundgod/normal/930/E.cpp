#include<bits/stdc++.h>
#define MAXN 100005
#define MAXM 400005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int k,n,m;
int la[MAXN],ra[MAXN],lb[MAXN],rb[MAXN];
int lasta[MAXM],lastb[MAXM];
vector<int> dis;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int pow_mod(int a,int i)
{
    int s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
struct segtree
{
    int sum[4*MAXM],lazy[4*MAXM];
    void pushup(int k)
    {
        sum[k]=sum[k*2];
        add(sum[k],sum[k*2+1]);
    }
    void st(int k,int l,int r,int v)
    {
        sum[k]=1LL*(r-l+1)*v%MOD;
        lazy[k]=v;
    }
    void pushdown(int k,int l,int r)
    {
        if(lazy[k]==-1) return;
        int v=lazy[k],mid=(l+r)/2;
        st(k*2,l,mid,v); st(k*2+1,mid+1,r,v);
        lazy[k]=-1;
    }
    void build(int k,int l,int r)
    {
        lazy[k]=-1;
        if(l==r) return;
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
    }
    void update(int k,int l,int r,int x,int y,int v)
    {
        if(l>y||x>r) return;
        if(l>=x&&r<=y)
        {
            st(k,l,r,v);
            return;
        }
        pushdown(k,l,r);
        int mid=(l+r)/2;
        update(k*2,l,mid,x,y,v); update(k*2+1,mid+1,r,x,y,v);
        pushup(k);
    }
    int query(int k,int l,int r,int x,int y)
    {
        if(l>y||x>r) return 0;
        if(l>=x&&r<=y) return sum[k];
        pushdown(k,l,r);
        int mid=(l+r)/2;
        int ans=query(k*2,l,mid,x,y); add(ans,query(k*2+1,mid+1,r,x,y));
        return ans;
    }
}f,g;
int main()
{
    scanf("%d%d%d",&k,&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&la[i],&ra[i]); la[i]--;
        dis.push_back(la[i]); dis.push_back(ra[i]);
    }
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&lb[i],&rb[i]); lb[i]--;
        dis.push_back(lb[i]); dis.push_back(rb[i]);
    }
    dis.push_back(0); dis.push_back(k);
    sort(dis.begin(),dis.end());
    dis.erase(unique(dis.begin(),dis.end()),dis.end());
    memset(lasta,-1,sizeof(lasta)); memset(lastb,-1,sizeof(lastb));
    for(int i=0;i<n;i++)
    {
        la[i]=lower_bound(dis.begin(),dis.end(),la[i])-dis.begin();
        ra[i]=lower_bound(dis.begin(),dis.end(),ra[i])-dis.begin();
        lasta[ra[i]]=max(lasta[ra[i]],la[i]);
    }
    for(int i=0;i<m;i++)
    {
        lb[i]=lower_bound(dis.begin(),dis.end(),lb[i])-dis.begin();
        rb[i]=lower_bound(dis.begin(),dis.end(),rb[i])-dis.begin();
        lastb[rb[i]]=max(lastb[rb[i]],lb[i]);
    }
    int sz=(int)dis.size();
    f.build(1,1,sz); g.build(1,1,sz); f.update(1,1,sz,1,1,1);
    for(int i=1;i<sz;i++)
    {
        int len=dis[i]-dis[i-1];
        int res=pow_mod(2,len-1);
        int sum1=f.query(1,1,sz,1,sz);
        int sum2=g.query(1,1,sz,1,sz);
        g.update(1,1,sz,i+1,i+1,1LL*(res-1)*(sum1+sum2)%MOD); f.update(1,1,sz,i+1,i+1,1LL*(res-1)*(sum1+sum2)%MOD);
        int tmp=f.query(1,1,sz,i,i); add(tmp,sum2); f.update(1,1,sz,i,i,tmp);
        tmp=g.query(1,1,sz,i,i); add(tmp,sum1); g.update(1,1,sz,i,i,tmp);
        if(lasta[i]!=-1) f.update(1,1,sz,1,lasta[i]+1,0);
        if(lastb[i]!=-1) g.update(1,1,sz,1,lastb[i]+1,0);
    }
    int ans=0;
    add(ans,f.query(1,1,sz,1,sz)); add(ans,g.query(1,1,sz,1,sz));
    printf("%d\n",ans);
    return 0;
}