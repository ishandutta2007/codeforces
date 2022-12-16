#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define double long double
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define eps (1e-15)
    const int N=5e5+10,mod=1e9+7,inv2=5e8+4,inf=2e9;
    const double pi=acos(-1.0);
    char s[N],t[N];
    int n,m;
    int num[26];
    int vis[26][N];
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        cin>>n;
        cin>>(s+1);
        for(int i=1;i<=n;++i)
        {
            int c=s[i]-'a';

            vis[c][++num[c]]=i;
        }
        int tot;
        cin>>tot;
        while(tot--)
        {
            int ans=0;
            cin>>(t+1);
            m=strlen(t+1);
            vector<int> sum(26,0);
            for(int i=1;i<=m;++i)
            {
                int c=t[i]-'a';
                ans=max(ans,vis[c][++sum[c]]);
            }
            cout<<ans<<'\n';
        }
    }
}
signed main()
{
    red::main();
    return 0;
}
/*
9
arrayhead
5
arya
harry
ray
rr
areahydra

*/