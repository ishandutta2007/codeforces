/*************************************************************************
    > File Name: C.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-10 11:56:46
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000009
#define C1 276601605
#define C2 691504013
#define C3 308495997
#define INV1 691504012 
#define INV2 308495997
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,a[MAXN];
int add(int x,int y){x=x+y; return x>=MOD?x-MOD:x;}
int p[2][MAXN];
int inv[2]={691504013,308495997};
int mult[2]={691504013,308495997};
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
    int val[4*MAXN],lazy[2][4*MAXN];
    void Lazy(int k,int l,int r)
    {
        int mid=(l+r)/2;
        int len[2];
        len[0]=mid-l+1,len[1]=r-mid;
        for(int now=0;now<=1;now++)
        {
            if(!lazy[now][k]) continue;
            for(int i=k*2;i<=k*2+1;i++)
            {
                int s=(i&1)?1LL*p[now][len[0]]*lazy[now][k]%MOD:lazy[now][k];
                lazy[now][i]=add(lazy[now][i],s);
                int sum=1LL*s*(p[now][len[i&1]]-1)%MOD*inv[now]%MOD;
                if(now==0) val[i]=add(val[i],sum); else {val[i]=val[i]-sum; if(val[i]<0) val[i]+=MOD;}
            }
            lazy[now][k]=0;
        }
    }
    void build(int k,int l,int r)
    {
        lazy[0][k]=lazy[1][k]=0;
        if(l==r) {val[k]=a[l]; return;}
        int mid=(l+r)/2;
        build(k*2,l,mid);build(k*2+1,mid+1,r);
        val[k]=add(val[k*2],val[k*2+1]);
    }
    void update(int k,int l,int r,int x,int y)
    {
        if(x>r||y<l) return;
        if(l>=x&&r<=y)
        {
            for(int now=0;now<=1;now++)
            {
                int s=1LL*C1*p[now][l-x+1]%MOD;
                lazy[now][k]=add(lazy[now][k],s);
                int len=r-l+1;
                int sum=1LL*s*(p[now][len]-1)%MOD*inv[now]%MOD;
                if(now==0) val[k]=add(val[k],sum);
                else {val[k]=val[k]-sum; if(val[k]<0) val[k]+=MOD;}
            }
            return;
        }
        Lazy(k,l,r);
        int mid=(l+r)/2;
        update(k*2,l,mid,x,y);update(k*2+1,mid+1,r,x,y);
        val[k]=add(val[k*2],val[k*2+1]);
    }
    int query(int k,int l,int r,int x,int y)
    {
        if(x>r||y<l) return 0;
        if(l>=x&&r<=y) return val[k];
        Lazy(k,l,r);
        int mid=(l+r)/2;
        return add(query(k*2,l,mid,x,y),query(k*2+1,mid+1,r,x,y));
    }
}seg;
int main()
{
    p[0][0]=p[1][0]=1;
    for(int i=1;i<=300001;i++) 
    {
        p[0][i]=1LL*p[0][i-1]*C2%MOD;
        p[1][i]=1LL*p[1][i-1]*C3%MOD;
    }
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    seg.build(1,1,n);
    for(int i=0;i<m;i++)
    {
        int x,l,r;
        scanf("%d%d%d",&x,&l,&r);
        if(x==1) seg.update(1,1,n,l,r);
        else printf("%d\n",seg.query(1,1,n,l,r));
    }
    return 0;
}