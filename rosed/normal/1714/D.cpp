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
    const int N=1010,mod=1e9+7,inv2=5e8+4,inf=2e9;
    const double pi=acos(-1.0);
    int n,m;
    string s,t[N];
    int dp[N],g[N],pre[N];
    int len[N];
    inline bool check(int x,int y)
    {
        if(x+len[y]-1>=n) return 0;
        for(int i=0;i<len[y];++i,++x)
        {
            if(s[x]!=t[y][i]) return 0;
        }
        return 1;
    }
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int qwq;cin>>qwq;
        while(qwq--)
        {
            cin>>s;
            cin>>m;
            for(int i=1;i<=m;++i)
            {
                cin>>t[i];
                len[i]=t[i].length();
            }
            n=s.length();
            for(int i=0;i<=n;++i) dp[i]=inf;
            dp[0]=0;
            for(int i=0;i<n;++i)
            {
                for(int j=1;j<=m;++j)
                {
                    if(check(i,j))
                    {
                        for(int k=i;k<i+len[j];++k)
                        {
                            if(dp[i+len[j]]>dp[k]+1)
                            {
                                dp[i+len[j]]=dp[k]+1;
                                g[i+len[j]]=j;
                                pre[i+len[j]]=k;
                            }
                        }
                    }
                }
            }
            if(dp[n]>n)
            {
                cout<<"-1\n";
                continue;
            }
            else
            {
                cout<<dp[n]<<'\n';
                int now=n;
                while(now)
                {
                    cout<<g[now]<<' '<<now-len[g[now]]+1<<'\n';
                    now=pre[now];
                }
            }
        }
    }
}
signed main()
{
    red::main();
    return 0;
}
/*
1
bababa
2
ba
aba
caba

1
abacabaca
3
aba
bac
aca

*/