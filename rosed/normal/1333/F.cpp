#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=5e5+10,mod=998244353,inf=2e9;
    int n;
    int a[N];
    int prime[N],tmp[N],num;
    bool vis[N];
    int id[N];
    inline bool cmp(int x,int y)
    {
        return a[x]<a[y];
    }
    inline void oula(int n)
    {
        tmp[1]=1;
        for(int i=2;i<=n;++i)
        {
            if(!vis[i]) prime[++num]=i,tmp[i]=i;
            for(int j=1;j<=num&&i*prime[j]<=n;++j)
            {
                vis[i*prime[j]]=1;
                tmp[i*prime[j]]=prime[j];
                if(i%prime[j]==0) break;
            }
        }
    }
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        cin>>n;
        oula(n);
        for(int i=1;i<=n;++i)
        {
            a[i]=i/tmp[i];
            id[i]=i;
        }
        sort(id+1,id+n+1,cmp);
        for(int i=2;i<=n;++i)
        {
            cout<<a[id[i]]<<" \n"[i==n];
        }
    }
}
signed main()
{
    red::main();
    return 0;
}
/*
6
1 1 1 2 3

*/