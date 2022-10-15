/*************************************************************************
    > File Name: F.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-06-29 19:41:56
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 500005
#define MAXM 2000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q,a[MAXN];
int last[MAXN],pre[MAXN];
int ans[MAXN];
int minx[MAXM],minpos[MAXM];
struct query
{
    int l,r,id;
}qq[MAXN];
bool cmp(query x,query y)
{
    if(x.r!=y.r) return x.r<y.r;
    return x.l<y.l;
}
void build(int k,int l,int r)
{
    if(l==r) {minx[k]=INF; minpos[k]=l; return;}
    int mid=(l+r)/2;
    build(k*2,l,mid);build(k*2+1,mid+1,r);
    minx[k]=min(minx[k*2],minx[k*2+1]);
    if(minx[k*2]<minx[k*2+1]) minpos[k]=minpos[k*2]; else minpos[k]=minpos[k*2+1];
}
void update(int k,int l,int r,int pos,int val)
{
    if(l==r) {minx[k]=val; return;}
    int mid=(l+r)/2;
    if(pos<=mid) update(k*2,l,mid,pos,val);
    else update(k*2+1,mid+1,r,pos,val);
    minx[k]=min(minx[k*2],minx[k*2+1]);
    if(minx[k*2]<minx[k*2+1]) minpos[k]=minpos[k*2]; else minpos[k]=minpos[k*2+1];
}
P query(int k,int l,int r,int x,int y)
{
    if(l>y||r<x) return P(-1,INF);
    if(l>=x&&r<=y) return P(minpos[k],minx[k]);
    int mid=(l+r)/2;
    P lans=query(k*2,l,mid,x,y);
    P rans=query(k*2+1,mid+1,r,x,y);
    if(lans.S<rans.S) return lans; else return rans;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        scanf("%d%d",&qq[i].l,&qq[i].r);
        qq[i].id=i;
    }
    sort(qq,qq+q,cmp);
    build(1,1,n);
    int now=0;
    for(int i=1;i<=n;i++)
    {
        if(last[a[i]]!=0) update(1,1,n,last[a[i]],INF);
        update(1,1,n,i,last[a[i]]);
        pre[i]=last[a[i]];
        last[a[i]]=i;
        while(now<q&&qq[now].r==i)
        {
            P p=query(1,1,n,qq[now].l,qq[now].r);
            if(pre[p.F]<qq[now].l) ans[qq[now].id]=a[p.F]; else ans[qq[now].id]=0;
            now++;
        }
    }
    for(int i=0;i<q;i++) printf("%d\n",ans[i]);
    return 0;
}