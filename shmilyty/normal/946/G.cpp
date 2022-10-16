#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
#define lowbit(x) (x&(-x))
using namespace std;
void fileio(const string &s)
{
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}
const int INF=4e18;
inline int read()
{
    int x=0;
    bool flag=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-')
            flag=0;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        x=(x<<1)+(x<<3)+c-'0';
        c=getchar();
    }
    return (flag?x:~(x-1));
}
int n,cnt,ans,a[200001],b[200001],f[200001],g[200001],t[400001];
map<int,int> mp;
void modify(int x,int y)
{
    for(;x<=cnt;x+=lowbit(x))
        t[x]=max(t[x],y);
}
int query(int x)
{
    int res=0;
    for(;x;x^=lowbit(x))
        res=max(res,t[x]);
    return res;
}
signed main()
{
    n=read();
    for(int i=1;i<=n;i++)
    {
        a[i]=b[i]=read()-i;
        mp[a[i]];
    }
    for(auto &i:mp)
        i.second=++cnt;
    for(int i=1;i<=n;i++)
        a[i]=mp[a[i]];
    for(int i=1;i<=n;i++)
    {
        f[i]=query(a[i])+1;
        modify(a[i],f[i]);
        if(i!=n)
            ans=max(ans,f[i]+1);
    }
    fill(t+1,t+1+n,0);
    for(int i=n;i;i--)
    {
        g[i]=query(cnt-a[i]+1)+1;
        modify(cnt-a[i]+1,g[i]);
        if(i!=1)
            ans=max(ans,g[i]+1);
    }
    fill(t+1,t+1+n,0);
    mp.clear();
    cnt=0;
    for(int i=1;i<=n;i++)
    {
        mp[b[i]];
        mp[b[i]+1];
    }
    for(auto &i:mp)
        i.second=++cnt;
    for(int i=1;i<=n;i++)
        a[i]=mp[b[i]];
    for(int i=2;i<=n;i++)
    {
        ans=max(ans,query(a[i]+1)+g[i]+1);
        if(b[i-1]<=b[i])
            ans=max(ans,f[i-1]+g[i]);
        modify(a[i-1],f[i-1]);
    }
    cout<<n-ans<<endl;
    return 0;
}