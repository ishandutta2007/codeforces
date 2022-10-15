/*************************************************************************
    > File Name: 1453.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-10 21:50:19
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 15
#define MAXM 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,q,mp[MAXN*MAXM];
int fa[MAXN*MAXM];
struct node
{
    int L,R,l[MAXN],r[MAXN],ans;
}s[4*MAXM];
int find(int x)
{
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}
node merge(node ls,node rs)
{
    node x;
    int mid=ls.R;
    x.ans=ls.ans+rs.ans;x.L=ls.L;x.R=rs.R;
    for(int i=1;i<=n;i++) fa[ls.l[i]]=ls.l[i],fa[ls.r[i]]=ls.r[i];
    for(int i=1;i<=n;i++) fa[rs.l[i]]=rs.l[i],fa[rs.r[i]]=rs.r[i];
    for(int i=1;i<=n;i++)
    {
        if(mp[(i-1)*m+mid]==mp[(i-1)*m+mid+1])
        {
            int p=find(ls.r[i]),y=find(rs.l[i]);
            if(p!=y)
            {
                x.ans--;
                fa[y]=p;
            }
        }
    }
    for(int i=1;i<=n;i++) x.l[i]=find(ls.l[i]),x.r[i]=find(rs.r[i]);
    return x;
}
void build(int k,int ll,int rr)
{
    s[k].L=ll;s[k].R=rr;
    if(ll==rr)
    {
        s[k].ans=0;
        for(int i=1;i<=n;i++) s[k].l[i]=s[k].r[i]=(i-1)*m+ll;
        for(int i=1;i<=n;i++) 
        {
            if(i!=1&&mp[(i-2)*m+ll]==mp[(i-1)*m+ll]) s[k].l[i]=s[k].r[i]=s[k].l[i-1]; else s[k].ans++;
        }
        return;
    }
    int mid=(ll+rr)/2;
    build(k*2,ll,mid);build(k*2+1,mid+1,rr);
    s[k]=merge(s[k*2],s[k*2+1]);
}
node query(int k,int ll,int rr,int x,int y)
{
    if(ll>=x&&rr<=y) return s[k];
    int mid=(ll+rr)/2;
    if(mid<x) return query(k*2+1,mid+1,rr,x,y);
    else if(mid>=y) return query(k*2,ll,mid,x,y);
    else return merge(query(k*2,ll,mid,x,y),query(k*2+1,mid+1,rr,x,y));
}
int main()
{
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=n;i++) 
        for(int j=1;j<=m;j++) 
            scanf("%d",&mp[(i-1)*m+j]);
    build(1,1,m);
    for(int i=0;i<q;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        node res=query(1,1,m,x,y);
        printf("%d\n",res.ans);
    }
    return 0;
}