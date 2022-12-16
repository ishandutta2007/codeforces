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
    const int N=3e5+10,mod=998244353,inf=2e9;
    int n,m,num;
    int tim[N],pos[N];
    struct node
    {
        int x,y;
        inline bool operator < (const node &t) const
        {
            if(x!=t.x) return x<t.x;
            return y<t.y;
        }
    }a[N];
    int dp[N];
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T=1;
        while(T--)
        {
            cin>>n>>m;
            for(int i=1;i<=n;++i)
            {
                cin>>tim[i];
            }
            for(int i=1;i<=n;++i)
            { 
                cin>>pos[i];
                if(abs(pos[i])>m*tim[i]) continue;
                ++num;
                a[num].x=tim[i]*m-pos[i];
                a[num].y=tim[i]*m+pos[i];
            }
            sort(a+1,a+num+1);
            for(int i=1;i<=num;++i) dp[i]=inf*inf;
            int ans=0;
            for(int i=1;i<=num;++i)
            {
                if(a[i].x<0) continue;
                int t=upper_bound(dp+1,dp+num+1,a[i].y)-dp;
                ans=max(ans,t);
                dp[t]=min(dp[t],a[i].y);
            }
            cout<<ans<<'\n';
            //dp[i]=max(dp[j]+1)[t_i*v-a_i>=a_j+t_j*v] ai>=aj

            //dp[i]=max(dp[j]+1)[(ti-tj)*v>=ai-aj] ai>=aj

            //dp[i]=max(dp[j]+1)[ti*v-ai>=tj*v-aj] ai>=aj

            //dp[i]=max(dp[j]+1)[(ti-tj)*v>=aj-ai] ai<=aj

            //dp[i]=max(dp[j]+1)[ti*v+ai>=tj*v+aj] ai<=aj

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
5
1 2
2 3
3 4
3 5

*/