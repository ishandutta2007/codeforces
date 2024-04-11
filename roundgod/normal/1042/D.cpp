/*************************************************************************
    > File Name: D.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-17 16:17:52
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
#define size Wavatorcaibi
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,t,a[MAXN],sum[MAXN];
ll ch[MAXN][2],f[MAXN],size[MAXN],cnt[MAXN],key[MAXN];
ll sz,root;
inline void clear(ll x)
{
    ch[x][0]=ch[x][1]=f[x]=size[x]=cnt[x]=key[x]=0;
}
inline bool get(ll x)
{
    return ch[f[x]][1]==x;
}
inline void pushup(ll x)
{
    if (x)
    {
        size[x]=cnt[x];
        if (ch[x][0]) size[x]+=size[ch[x][0]];
        if (ch[x][1]) size[x]+=size[ch[x][1]];
    }
}
inline void rotate(ll x)
{
    ll old=f[x],oldf=f[old],whichx=get(x);
    ch[old][whichx]=ch[x][whichx^1]; f[ch[old][whichx]]=old;
    ch[x][whichx^1]=old; f[old]=x;
    f[x]=oldf;
    if (oldf) ch[oldf][ch[oldf][1]==old]=x;
    pushup(old); pushup(x);
}
inline void splay(ll x,ll goal=0)
{
    for(ll fa;(fa=f[x])!=goal;rotate(x))
        if(f[fa]!=goal) rotate((get(x)==get(fa))?fa:x);
    if(goal==0) root=x;
}
inline void insert(ll x)
{
    if (root==0){sz++; ch[sz][0]=ch[sz][1]=f[sz]=0; root=sz; size[sz]=cnt[sz]=1; key[sz]=x; return;}
    ll now=root,fa=0;
    while(1)
    {
        if (x==key[now])
        {
            cnt[now]++; pushup(now); pushup(fa); splay(now); break;
        }
        fa=now;
        now=ch[now][key[now]<x];
        if (now==0)
        {
            sz++;
            ch[sz][0]=ch[sz][1]=0;
            f[sz]=fa;
            size[sz]=cnt[sz]=1;
            ch[fa][key[fa]<x]=sz;
            key[sz]=x;
            pushup(fa);
            splay(sz);
            break;
        }
    }
}
inline ll find(ll x)
{
    ll now=root,ans=0;
    while(1)
    {
        if(!now) return ans;
        if(x<key[now]) now=ch[now][0];
        else
        {
            ans+=(ch[now][0]?size[ch[now][0]]:0);
            if (x==key[now]){splay(now); return ans;}
            ans+=cnt[now];
            now=ch[now][1];
        }
    }
}
inline ll findx(ll now,ll k)
{
    while(now)
    {
        if(k<=size[ch[now][0]]) now=ch[now][0];
        else if(k<=size[ch[now][0]]+cnt[now]) return key[now];
        else k-=size[ch[now][0]]+cnt[now],now=ch[now][1];
    }
}
inline ll pre()
{
    ll now=ch[root][0];
    while (ch[now][1]) now=ch[now][1];
    return now;
}
inline ll next()
{
    ll now=ch[root][1];
    while (ch[now][0]) now=ch[now][0];
    return now;
}
inline void del(ll x)
{
    ll whatever=find(x);
    if (cnt[root]>1){cnt[root]--; pushup(root); return;}
    if (!ch[root][0]&&!ch[root][1]) {clear(root); root=0; return;}
    if (!ch[root][0])
    { 
        ll oldroot=root; root=ch[root][1]; f[root]=0; clear(oldroot); return;
    }
    else if (!ch[root][1])
    {
        ll oldroot=root; root=ch[root][0]; f[root]=0; clear(oldroot); return;
    }
    ll leftbig=pre(),oldroot=root;
    splay(leftbig);
    ch[root][1]=ch[oldroot][1];
    f[ch[oldroot][1]]=root;
    clear(oldroot);
    pushup(root);
}
int main()
{
    scanf("%lld%lld",&n,&t);
    for(ll i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        sum[i]=sum[i-1]+a[i];
    }
    for(ll i=1;i<=n;i++) insert(sum[i]);
    ll ans=0;
    for(ll i=1;i<=n;i++) 
    {
        ans+=find(t);
        t+=a[i];
        del(sum[i]);
    }
    printf("%lld\n",ans);
    return 0;
}