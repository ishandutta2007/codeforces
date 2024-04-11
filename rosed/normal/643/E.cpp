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
    const int N=5e5+10,mod=1e9+7,inv2=5e8+4,inf=1e18;
    const double pi=acos(-1.0);
    int n,m,idx;
    double dp[N][62];
    int f[N];
    void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        cin>>n;m=61;idx=1;
        for(int i=1;i<=m;++i) dp[1][i]=1;
        for(int i=1;i<=n;++i)
        {
            int opt,x;
            cin>>opt>>x;
            if(opt==1)
            {
                f[++idx]=x;
                for(int k=1;k<=m;++k) dp[idx][k]=1;
                vector<int> tmp;
                int k=0,now=idx;
                while(k<=60&&now)
                {
                    tmp.emplace_back(now);
                    now=f[now];
                    ++k;
                }
                for(int i=tmp.size()-2;i>0;--i)
                {
                    dp[tmp[i+1]][i+1]/=(dp[tmp[i]][i]+1)/2.0;
                    //cout<<tmp[i+1]<<"!!"<<'\n';
                }
                for(int i=0;i+1<(int)tmp.size();++i)
                {
                    dp[tmp[i+1]][i+1]*=(dp[tmp[i]][i]+1)/2.0;
                }
            }
            else
            {
                double ans=0;
                for(int i=1;i<=60;++i)
                {
                    ans+=i*(dp[x][i]-dp[x][i-1]);
                }
                cout<<fixed<<setprecision(10)<<ans-1<<'\n';
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
20 4
25 66 10 18 67 40 66 49 3 51 61 29 10 72 71 22 63 4 74 67

*/