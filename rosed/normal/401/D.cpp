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
    int n,mod;
    char c[N];
    int f[300010][105];
    vector<int> st[20];
    bool vis[10];
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        cin>>c>>mod;
        n=strlen(c);
        int tmp=1;
        f[0][0]=1;
        for(int s=0;s<(1<<n);++s)
        {
            int sum=0;
            for(int k=0;k<n;++k) sum+=((s>>k)&1);
            st[sum].push_back(s);
        }
        for(int i=1;i<=n;++i)
        {
            for(int s:st[i])
            {
                for(int j=0;j<10;++j) vis[j]=0;
                for(int k=0;k<n;++k)if((s>>k)&1)
                {
                    int t=(s^(1<<k));
                    if(vis[c[k]-'0']) continue;
                    vis[c[k]-'0']=1;
                    if(i==n&&c[k]=='0') continue;
                    for(int p1=0;p1<mod;++p1)
                    {
                        int p2=(p1+(c[k]-'0')*tmp)%mod;
                        f[s][p2]+=f[t][p1];
                    }
                }
            }
            tmp=tmp*10%mod;
        }
        cout<<f[(1<<n)-1][0]<<'\n';
    }
}
signed main()
{
    red::main();
    return 0;   
}