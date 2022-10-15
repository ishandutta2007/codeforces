/*************************************************************************
    > File Name: D.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-17 22:58:34
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q,a[MAXN],occ[MAXN],fst[MAXN],lst[MAXN],b[MAXN];
struct segtree
{
    int val[4*MAXN],lazy[4*MAXN];
    void Lazy(int k)
    {
        if(!lazy[k]) return;
        val[k*2]=val[k*2+1]=lazy[k];
        lazy[k*2]=lazy[k*2+1]=lazy[k];
        lazy[k]=0;
    }
    void build(int k,int l,int r)
    {
        lazy[k]=0;val[k]=0;
        if(l==r) return;
        int mid=(l+r)/2;
        build(k*2,l,mid);build(k*2+1,mid+1,r);
    }
    void update(int k,int l,int r,int x,int y,int v)
    {
        if(l>y||x>r) return;
        if(l>=x&&r<=y) 
        {
            lazy[k]=v; val[k]=v; return;
        }
        Lazy(k);
        int mid=(l+r)/2;
        update(k*2,l,mid,x,y,v);update(k*2+1,mid+1,r,x,y,v);
    }
    int query(int k,int l,int r,int p)
    {
        if(l==r) return val[k];
        Lazy(k);
        int mid=(l+r)/2;
        if(p<=mid) return query(k*2,l,mid,p); else return query(k*2+1,mid+1,r,p);
    }
}seg;
int main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) 
    {
        if(a[i]==0) continue;
        if(fst[a[i]]==0) fst[a[i]]=i;
        lst[a[i]]=max(lst[a[i]],i);
    }
    seg.build(1,1,n);
    for(int i=1;i<=q;i++)
    {
        if(!fst[i]) continue;
        seg.update(1,1,n,fst[i],lst[i],i);
    }
    for(int i=1;i<=n;i++) b[i]=seg.query(1,1,n,i);
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=0&&b[i]>a[i]) {puts("NO"); return 0;}
        if(a[i]==0) cnt++;
    }
    if(fst[q]==0&&cnt==0) {puts("NO"); return 0;}
    puts("YES");
    if(fst[q]==0)
    {
        for(int i=1;i<=n;i++) 
            if(a[i]==0) {b[i]=q; break;}
    }
    if(cnt==n)
    {
        for(int i=1;i<=n;i++) printf("%d ",q);
        return 0;
    }
    for(int i=1;i<=n;i++) if(b[i]==0) b[i]=b[i-1];
    for(int i=n;i>=1;i--) if(b[i]==0) b[i]=b[i+1];
    for(int i=1;i<=n;i++) printf("%d ",b[i]);
    return 0;
}