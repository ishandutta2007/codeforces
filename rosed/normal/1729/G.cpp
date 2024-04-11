#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define double long double
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define eps (1e-15)
    const int N=1e6+10,mod=1e9+7,inv2=(mod+1)/2,inf=2e18;
    void __init(int n=2000) {}
    inline void main()
    {
        string s,t;
        cin>>s>>t;
        int n=s.length(),m=t.length();
        auto check=[&](int sl,int sr) -> bool
        {
            if(sr-sl!=m-1) return 0;
            if(sl<0||sr>=n) return 0;
            for(int i=sl,j=0;i<=sr;++i,++j)
            {
                if(s[i]!=t[j]) return 0;
            }
            return 1;
        };
        vector dp(n+1,vector<int>(n+1,inf));
        vector sum(n+1,vector<int>(n+1,0));
        dp[0][0]=0;
        sum[0][0]=1;
        auto work=[&](int i,int j,int s1,int s2) -> void
        {
            if(dp[i][j]==s1) sum[i][j]=(sum[i][j]+s2)%mod;
            if(s1<dp[i][j]) dp[i][j]=s1,sum[i][j]=s2;
        };
        for(int i=0;i<n;++i)
        {
            for(int j=i;j>=0;--j)
            {
                int sl=i-m,sr=i-1;
                if(j<=sl&&check(sl,sr)) continue;
                int ql=i,qr=i+m-1;
                if(check(ql,qr))
                {
                    work(qr+1,qr+1,dp[i][j]+1,sum[i][j]);
                }
                if(j<=i-m+1&&check(i-m+1,i)) continue;
                work(i+1,j,dp[i][j],sum[i][j]);
                // for(int k=i;k<n;++k)
                // {
                //     int qr=k,ql=k-m+1;
                //     if(j<=ql&&check(ql,qr))
                //     {
                //         work(k+1,k+1,dp[i][j]+1,sum[i][j]);
                //     }
                //     else
                //     {
                //         work(k+1,j,dp[i][j],sum[i][j]);
                //     }
                // }
            }
        }
        //cout<<dp[6][3]<<"!!!"<<endl;
        int minn=inf,tot=0;
        for(int i=0;i<=n;++i)
        {
            if(dp[n][i]==minn) tot=(tot+sum[n][i])%mod;
            if(dp[n][i]<minn) minn=dp[n][i],tot=sum[n][i];
        }
        cout<<minn<<' '<<tot<<'\n';
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    red::__init();
    int qwq=1; cin>>qwq;
    while(qwq--) red::main();
    return 0;
}
/*
m/i=(-p%i)*inv[i]

inv[i]*i%p=1

*/