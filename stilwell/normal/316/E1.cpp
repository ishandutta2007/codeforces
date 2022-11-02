#include <stdio.h>
#include <stdlib.h>
#define p 1000000000
using namespace std;

int n,m,i,j,k,l,opt,ll,rr,aim,ans,key;
int len[800005],add[800005];

long long t11,t12,t21,t22;
struct node
{
    long long f11,f12,f21,f22;
    void mult(node a)
    {
        t11=(f11*a.f11+f12*a.f21)%p;
        t12=(f11*a.f12+f12*a.f22)%p;
        t21=(f21*a.f11+f22*a.f21)%p;
        t22=(f22*a.f22+f21*a.f12)%p;
        f11=t11;f12=t12;f21=t21;f22=t22;
    }
    void mult_int(int x)
    {
        f11=f11*x%p;f12=f12*x%p;
        f21=f21*x%p;f22=f22*x%p;
    }
    void add(node a)
    {
        f11+=a.f11;if(f11>=p)f11-=p;
        f12+=a.f12;if(f12>=p)f12-=p;
        f21+=a.f21;if(f21>=p)f21-=p;
        f22+=a.f22;if(f22>=p)f22-=p;
    }
    void init(int a,int b,int c,int d){f11=a;f12=b;f21=c;f22=d;}
}t[800005],power[105],sum[105],tmp,tmp2;

void downdata(int x)
{
    if(!add[x])return;
    tmp=sum[len[x]-1];tmp.mult_int(add[x]);
    add[x<<1]+=add[x];if(add[x<<1]>=p)add[x<<1]-=p;
    add[x<<1|1]+=add[x];if(add[x<<1|1]>=p)add[x<<1|1]-=p;
    t[x<<1].add(tmp);t[x<<1|1].add(tmp);
    add[x]=0;
}

void update(int x)
{
    t[x]=t[x<<1];
    tmp=t[x<<1|1];
    tmp.mult(power[len[x]-1]);
    t[x].add(tmp);
}

void C(int x,int l,int r)
{
    if(l>=ll&&r<=rr)
    {
        add[x]+=key;if(add[x]>=p)add[x]-=p;
        tmp=sum[len[x]];tmp.mult_int(key);
        t[x].add(tmp);
        return;
    }
    int mid=l+r>>1;
    downdata(x);
    if(rr<=mid)C(x<<1,l,mid);
    else if(ll>mid)C(x<<1|1,mid+1,r);
        else C(x<<1,l,mid),C(x<<1|1,mid+1,r);
    update(x);
}

void M(int x,int l,int r)
{
    if(l==r)
    {
        add[x]=key;
        t[x]=sum[0];
        t[x].mult_int(key);
        return;
    }
    int mid=l+r>>1;
    downdata(x);
    if(aim<=mid)M(x<<1,l,mid);
    else M(x<<1|1,mid+1,r);
    update(x);
}

void Q(int x,int l,int r)
{
    if(l>=ll&&r<=rr)
    {
        tmp=t[x];tmp.mult(tmp2);
        ans+=tmp.f11;if(ans>=p)ans-=p;
        tmp2.mult(power[len[x]]);
        return;
    }
    int mid=l+r>>1;
    downdata(x);
    if(rr<=mid)Q(x<<1,l,mid);
    else if(ll>mid)Q(x<<1|1,mid+1,r);
        else Q(x<<1,l,mid),Q(x<<1|1,mid+1,r);
}

int main()
{
    scanf("%d%d",&n,&m);
    power[0].init(1,1,1,0);
    for(i=1;i<=30;++i)power[i]=power[i-1],power[i].mult(power[i-1]);
    for(l=1,i=0;l<=n;++i,l*=2)
    {
        tmp.init(1,0,0,1);
        for(j=1<<i;j;--j)
        {
            sum[i].add(tmp);
            tmp.mult(power[0]);
        }
    }
    for(i=l-1;i;--i)len[i]=len[i<<1]+1;
    for(i=1;i<=n;++i)
    {
        scanf("%d",&key);
        ll=rr=i;
        C(1,1,l);
    }
    for(;m;--m)
    {
        scanf("%d",&opt);
        if(opt==1)
        {
            scanf("%d%d",&aim,&key);
            M(1,1,l);
        }
        if(opt==2)
        {
            scanf("%d%d",&ll,&rr);
            ans=0;
            tmp2.init(1,0,0,1);
            Q(1,1,l);
            printf("%d\n",ans);
        }
        if(opt==3)
        {
            scanf("%d%d%d",&ll,&rr,&key);
            C(1,1,l);
        }
    }
}