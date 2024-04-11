#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=1e5+10,inf=2e9;
    int n,m,tmp=1,ret;
    int a[N],b[N],g[N],d[N];
    int prime[N],num;
    bool vis[N];
    unordered_map<int,bool> q;
    inline void oula(int n=1e5)
    {
        for(int i=2;i<=n;++i)
        {
            if(!vis[i]) prime[++num]=i;
            for(int j=1;j<=num&&i*prime[j]<=n;++j)
            {
                vis[i*prime[j]]=1;
                if(i%prime[j]==0) break;
            }
        }
    }
    inline int check(int x)
    {
        int sum=0;
        for(int j=1;prime[j]*prime[j]<=x;++j)
        {
            int i=prime[j];
            if(x%i==0)
            {
                int opt=q[i]?-1:1;
                while(x%i==0) x/=i,sum+=opt;               
            }
        }
        if(x!=1) sum+=q[x]?-1:1;
        return sum;
    }
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        cin>>n>>m;
        oula();
        for(int i=1;i<=n;++i) cin>>a[i];
        for(int i=1;i<=m;++i)
        {
            cin>>b[i];
            q[b[i]]=1;
        }
        g[1]=a[1];
        for(int i=2;i<=n;++i) g[i]=__gcd(g[i-1],a[i]);
        for(int i=n;i;--i)
        {
            if(check(g[i]/tmp)<0) tmp=g[i];
            d[i]=tmp;
        }
        for(int i=1;i<=n;++i)
        {
            a[i]/=d[i];
            //cout<<a[i]<<"!!"<<endl;
            ret+=check(a[i]);
        }
        cout<<ret<<'\n';
    }
}
signed main()
{
    red::main();
    return 0;   
}