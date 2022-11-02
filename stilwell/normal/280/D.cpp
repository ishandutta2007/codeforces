#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int n,m,i,j,k,l,opt,Ql,Qr,ll,rr,K;
int L[105],R[105],top,ans;

struct node
{
    int sum,tag;
    int Max,Max_l,Max_r;
    int Maxl,Maxl_l;
    int Maxr,Maxr_r;
    int Min,Min_l,Min_r;
    int Minl,Minl_l;
    int Minr,Minr_r;
    void update(const node a,const node b)
    {
        sum=a.sum+b.sum;
        //Max
        if(a.Max>b.Max)Max=a.Max,Max_l=a.Max_l,Max_r=a.Max_r;
        else Max=b.Max,Max_l=b.Max_l,Max_r=b.Max_r;
        if(a.Maxr+b.Maxl>Max)Max=a.Maxr+b.Maxl,Max_l=a.Maxr_r,Max_r=b.Maxl_l;
        Maxl=a.Maxl;Maxl_l=a.Maxl_l;
        if(a.sum+b.Maxl>Maxl)Maxl=a.sum+b.Maxl,Maxl_l=b.Maxl_l;
        Maxr=b.Maxr;Maxr_r=b.Maxr_r;
        if(b.sum+a.Maxr>Maxr)Maxr=b.sum+a.Maxr,Maxr_r=a.Maxr_r;
        //Min
        if(a.Min<b.Min)Min=a.Min,Min_l=a.Min_l,Min_r=a.Min_r;
        else Min=b.Min,Min_l=b.Min_l,Min_r=b.Min_r;
        if(a.Minr+b.Minl<Min)Min=a.Minr+b.Minl,Min_l=a.Minr_r,Min_r=b.Minl_l;
        Minl=a.Minl;Minl_l=a.Minl_l;
        if(a.sum+b.Minl<Minl)Minl=a.sum+b.Minl,Minl_l=b.Minl_l;
        Minr=b.Minr;Minr_r=b.Minr_r;
        if(b.sum+a.Minr<Minr)Minr=b.sum+a.Minr,Minr_r=a.Minr_r;
    }
    void Inv()
    {
        sum=-sum;tag^=1;
        swap(Max,Min);swap(Max_l,Min_l);swap(Max_r,Min_r);
        swap(Maxl,Minl);swap(Maxl_l,Minl_l);
        swap(Maxr,Minr);swap(Maxr_r,Minr_r);
        Max=-Max;Maxl=-Maxl;Maxr=-Maxr;
        Min=-Min;Minl=-Minl;Minr=-Minr;
    }
    void init(int x,int y)
    {
        sum=x;tag=0;
        Max=Maxl=Maxr=Min=Minl=Minr=x;
        Max_l=Max_r=Maxl_l=Maxr_r=Min_l=Min_r=Minl_l=Minr_r=y;
    }
}t[1000005],Qn;

void Q(int p,int l,int r)
{
    if(l>=ll&&r<=rr)
    {
        if(l==ll)Qn=t[p];
        else Qn.update(Qn,t[p]);
        return;
    }
    int mid=l+r>>1;
    if(t[p].tag)
    {
        t[p<<1].Inv();
        t[p<<1|1].Inv();
        t[p].tag=0;
    }
    if(rr<=mid)Q(p<<1,l,mid);
    else if(ll>mid)Q(p<<1|1,mid+1,r);
        else Q(p<<1,l,mid),Q(p<<1|1,mid+1,r);
}

void C(int p,int l,int r)
{
    if(l>=ll&&r<=rr)
    {
        t[p].Inv();
        return;
    }
    int mid=l+r>>1;
    if(t[p].tag)
    {
        t[p<<1].Inv();
        t[p<<1|1].Inv();
        t[p].tag=0;
    }
    if(rr<=mid)C(p<<1,l,mid);
    else if(ll>mid)C(p<<1|1,mid+1,r);
        else C(p<<1,l,mid),C(p<<1|1,mid+1,r);
    t[p].update(t[p<<1],t[p<<1|1]);
}

void M(int p,int l,int r)
{
    if(l==r)
    {
        t[p].init(K,ll);
        return;
    }
    if(t[p].tag)
    {
        t[p<<1].Inv();
        t[p<<1|1].Inv();
        t[p].tag=0;
    }
    int mid=l+r>>1;
    if(ll<=mid)M(p<<1,l,mid);
    else M(p<<1|1,mid+1,r);
    t[p].update(t[p<<1],t[p<<1|1]);
}

int main()
{
    scanf("%d",&n);
    for(l=1;l<n;l*=2);
    for(i=1;i<=n;++i)
    {
        scanf("%d",&k);
        t[l+i-1].init(k,i);
    }
    for(i=l-1;i;--i)t[i].update(t[i<<1],t[i<<1|1]);
    scanf("%d",&m);
    for(;m;--m)
    {
        scanf("%d",&opt);
        if(opt)
        {
            scanf("%d%d%d",&Ql,&Qr,&K);
            ans=0;
            for(;K;--K)
            {
                ll=Ql;rr=Qr;
                Q(1,1,l);
                if(Qn.Max<=0)break;
                ++top;L[top]=Qn.Max_l;R[top]=Qn.Max_r;
                ans+=Qn.Max;
                ll=Qn.Max_l;rr=Qn.Max_r;
                C(1,1,l);
            }
            printf("%d\n",ans);
            for(;top;--top)
            {
                ll=L[top];rr=R[top];
                C(1,1,l);
            }
        }
        else
        {
            scanf("%d%d",&ll,&K);
            M(1,1,l);
        }
    }
}