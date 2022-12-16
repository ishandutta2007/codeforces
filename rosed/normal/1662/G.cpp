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
    const int N=1e6+10,mod=998244353,inf=2e9;
    int n,rt,ans;
    vector<int> eg[N];
    int str[N];
    int cnt[N];
    inline void dfs(int now,int fa)
    {
        str[now]=1;
        for(int t:eg[now])
        {
            if(t==fa) continue;
            dfs(t,now);
            str[now]+=str[t];
        }
    }
    int st[N],top;
    inline void find(int now,int fa)
    {
        bool flag=0;
        if((n-str[now])*2>n) flag=1;
        for(int t:eg[now])
        {
            if(t==fa) continue;
            if(str[t]*2>n) flag=1;
            find(t,now);
        }
        if(!flag) rt=now;
    }
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        cin>>n;
        for(int i=2;i<=n;++i)
        {
            int x;cin>>x;
            eg[x].emplace_back(i);
            eg[i].emplace_back(x);
        }
        dfs(1,0);
        find(1,0);
        dfs(rt,0);
        bitset<1000000> b;
        b[0]=1;
        for(int t:eg[rt])
        {
            ++cnt[str[t]];
        }
        for(int i=0;i<n;++i)
        {
            if(cnt[i]>0)
            {
                int k=1;
                while(k<=cnt[i])
                {
                    b|=b<<(i*k);
                    cnt[i]-=k;
                    k*=2;
                }
                if(cnt[i]>k)
                {
                    b|=b<<(cnt[i]*i);
                }
            }
        }
        for(int i=0;i<n;++i)
        {
            if(b[i]) ans=max(ans,i*(n-i-1));
        }
        ans+=accumulate(str+1,str+n+1,0ll);
        cout<<ans<<'\n';
    }
}
signed main()
{
    red::main();
    return 0;
}
/*


*/