#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define double long double
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-15)
    const int N=2e6+10,mod=998244353,inv2=5e8+4,inf=2e9;
    inline void main()
    {
        int n,m,k;
        cin>>n>>m>>k;
        vector<int> f(k+1),str(k+1),tag(k+1);
        vector<int> cnt(m+1);
        for(int i=1;i<=k;++i)
        {
            f[i]=i;
            str[i]=1;
        }
        function<int(int)> find=[&](int k) -> int
        {
            return f[k]==k?k:f[k]=find(f[k]);
        };
        auto merge=[&](int x,int y) -> void
        {
            x=find(x),y=find(y);
            if(x==y) {tag[x]=1;return;}
            f[x]=y;
            str[y]+=str[x];
            tag[y]|=tag[x];
        };
        vector<int> pre(k+1),nxt(k+1);
        for(int i=1;i<=n;++i)
        {
            int s;cin>>s;
            int y=0;
            while(s--)
            {
                int x;cin>>x;
                if(y)
                {
                    
                    if((pre[x]&&pre[x]!=y)||(nxt[y]&&nxt[y]!=x)) {merge(x,y);tag[find(x)]=1;}
                    else if(!nxt[y])
                    {
                        pre[x]=y,nxt[y]=x;
                        merge(x,y);
                    }
                }
                y=x;
            }
        }
        for(int i=1;i<=k;++i) if(find(i)==i)
        {
            int tmp=str[i];
            if(tmp>m||tag[i]) continue;
            ++cnt[tmp];
        }
        vector<int> g,dp(m+1);
        dp[0]=1;
        for(int i=1;i<=m;++i)
        {
            if(cnt[i]) g.emplace_back(i);
            for(int t:g)
            {
                dp[i]=(dp[i]+dp[i-t]*cnt[t]%mod)%mod;
            }
        }
        cout<<dp[m]<<'\n';
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    red::main();
    return 0;
}
/*

*/