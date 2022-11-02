#include<cstdio>

#define N 200020
#define mo 1000000000

using namespace std;

struct lhy{
    int sum0,sum1,lazy,l;
}tree[N<<2],ans;

int n,m,l,r,v,opt;
int sum[N],f[N],a[N];

lhy operator +(const lhy &a,const lhy &b)
{
    lhy c;
    c.sum0=c.sum1=c.lazy=0;
    c.sum0=1ll*b.sum0*f[a.l-1]%mo+1ll*b.sum1*f[a.l]%mo;
    if(c.sum0>=mo)c.sum0-=mo;
    c.sum0+=a.sum0;
    if(c.sum0>=mo)c.sum0-=mo;
    c.sum1=1ll*b.sum0*f[a.l]%mo+1ll*b.sum1*f[a.l+1]%mo;
    if(c.sum1>=mo)c.sum1-=mo;
    c.sum1+=a.sum1;
    if(c.sum1>=mo)c.sum1-=mo;
    c.l=a.l+b.l;
    return c;
}

void build(int k,int l,int r)
{
    if(l==r)
    {
        tree[k].sum0=tree[k].sum1=a[l];
        tree[k].l=1;
        return;
    }
    int mid=(l+r)>>1;
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
    tree[k]=tree[k<<1]+tree[k<<1|1];
}

inline void plus(lhy &a,int v)
{
    a.sum0+=1ll*v*sum[a.l]%mo;
    if(a.sum0>=mo)a.sum0-=mo;
    a.sum1+=1ll*v*(sum[a.l+1]-sum[1])%mo;
    if(a.sum1>=mo)a.sum1-=mo;
    if(a.sum1<0)a.sum1+=mo;
    a.lazy+=v;
    if(a.lazy>=mo)a.lazy-=mo;
}

inline void down(int k)
{
    if(!tree[k].lazy)return;
    plus(tree[k<<1],tree[k].lazy);
    plus(tree[k<<1|1],tree[k].lazy);
    tree[k].lazy=0;
}

void change(int k,int l,int r,int ll)
{
    if(l==r)
    {
        tree[k].sum0=tree[k].sum1=v;
        return;
    }
    down(k);
    int mid=(l+r)>>1;
    if(mid>=ll)change(k<<1,l,mid,ll);
    else change(k<<1|1,mid+1,r,ll);
    tree[k]=tree[k<<1]+tree[k<<1|1];
}

void ask(int k,int l,int r,int ll,int rr)
{
    if(ll<=l&&r<=rr)
    {
        if(!ans.l)ans=tree[k];
        else ans=ans+tree[k];
        return;
    }
    down(k);
    int mid=(l+r)>>1;
    if(mid>=ll)ask(k<<1,l,mid,ll,rr);
    if(mid<rr)ask(k<<1|1,mid+1,r,ll,rr);
}

void modify(int k,int l,int r,int ll,int rr)
{
    if(ll<=l&&r<=rr)
    {
        plus(tree[k],v);
        return;
    }
    down(k);
    int mid=(l+r)>>1;
    if(mid>=ll)modify(k<<1,l,mid,ll,rr);
    if(mid<rr)modify(k<<1|1,mid+1,r,ll,rr);
    tree[k]=tree[k<<1]+tree[k<<1|1];
}

int main()
{
    scanf("%d%d",&n,&m);
    f[1]=f[2]=1;
    for(int i=3;i<=n+2;i++)
    {
        f[i]=f[i-1]+f[i-2];
        if(f[i]>=mo)f[i]-=mo;
    }
    for(int i=1;i<=n+2;i++)
    {
        sum[i]=f[i]+sum[i-1];
        if(sum[i]>=mo)sum[i]-=mo;
    }
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    build(1,1,n);
    while(m--)
    {
        scanf("%d",&opt);
        if(opt==1)
        {
            scanf("%d%d",&l,&v);
            change(1,1,n,l);
        }
        if(opt==2)
        {
            scanf("%d%d",&l,&r);
            ans.sum0=ans.sum1=ans.l=0;
            ask(1,1,n,l,r);
            printf("%d\n",ans.sum0);
        }
        if(opt==3)
        {
            scanf("%d%d%d",&l,&r,&v);
            modify(1,1,n,l,r);
        }
    }
}