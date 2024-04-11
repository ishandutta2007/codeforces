#include<bits/stdc++.h>
#define N 500005
using namespace std;
int n,q,x,a[N],g[N<<2];
void build(int k,int l,int r)
{
    if(l==r)g[k]=a[l];
    else
    {
        int mid=l+r>>1;
        build(k<<1,l,mid),build(k<<1|1,mid+1,r);
        g[k]=__gcd(g[k<<1],g[k<<1|1]);
    }
}
void mdf(int k,int l,int r,int pos)
{
    if(l==r){g[k]=a[l];return;}
    int mid=l+r>>1;
    if(pos<=mid)mdf(k<<1,l,mid,pos);
    else mdf(k<<1|1,mid+1,r,pos);
    g[k]=__gcd(g[k<<1],g[k<<1|1]);
}
int qry(int k,int l,int r,int ll,int rr)
{
    if(!(g[k]%x))return 0;
    if(l==r)return 1;
    int mid=l+r>>1,tp;
    if(rr<=mid)return qry(k<<1,l,mid,ll,rr);
    if(ll>mid)return qry(k<<1|1,mid+1,r,ll,rr);
    if(l==ll&&r==rr)
    {
        if(g[k<<1]%x&&g[k<<1|1]%x)return 2;
        if(g[k<<1]%x)return qry(k<<1,l,mid,ll,mid);
        return qry(k<<1|1,mid+1,r,mid+1,rr);
    }
    return qry(k<<1,l,mid,ll,mid)+qry(k<<1|1,mid+1,r,mid+1,rr);
}
int op,l,r;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
    scanf("%d",a+i);
    build(1,1,n);
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d%d%d",&op,&l,&r);
        if(op&1)
        {
            scanf("%d",&x);
            puts(qry(1,1,n,l,r)>1?"NO":"YES");
        }
        else
        a[l]=r,mdf(1,1,n,l);
    }
}